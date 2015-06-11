#include <Servo.h>

//puppet, A1 to A5
#define k_pBase A1
#define k_pShoulder A2
#define k_pElbow A3
#define k_pWrist A4
#define k_pGripper A5
int pShoulder = 0;

//sensors, A0
#define k_sShoulder A0
int sShoulder = 0;

//motors, 8 to 11
#define k_mBase 10
#define k_mShoulder 9
#define k_mElbow 4
#define k_mWrist 8
#define k_mGripper 11

//servo objects
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist;
Servo gripper;

//constants
int pos_mBase = 0;
int dk_Base = 1;
int pBase = 0;
int pElbow = 0;
int pWrist = 0;
int pGripper = 0;
const int pTolerance = 4;
#define k_baseNeutral 90
const float k_baseCCW = 2.5; //>90 = clockwise, usually greater than CCW offset
const float k_baseCW = -1.2; //<90 = counterclockwise
const float k_baseSpeed = 8;
#define k_shoulderNeutral 90
const float k_shoulderCW = 2.2; //<90 = clockwise when facing hub
const float k_shoulderCCW = -1; //>90 = counterclockwise when facing hub, usually greater than CW offset
const float k_shoulderSpeed = 6;
#define k_gripperNeutral 90
const float k_gripperSpeed = 60;

/*
//PID
unsigned long lastTime;
double Input, Output, Setpoint;
double errSum, lastErr;
double kp = 0.1;
double ki = 0.0;
double kd = 0.0;
*/

void setup() {
  Serial.begin(9600);
  base.attach(k_mBase);
  shoulder.attach(k_mShoulder);
  elbow.attach(k_mElbow);
  wrist.attach(k_mWrist);
  gripper.attach(k_mGripper);
  pBase = map(analogRead(k_pBase), 0, 1023, 0, 200);
  pos_mBase = pBase;
  //pShoulder = int(map(analogRead(k_pShoulder), 60, 800, 0, 200));
  sShoulder = pShoulder;
}

void loop() {
  pBase = map(analogRead(k_pBase), 0, 1023, 0, 200);
  pShoulder = map(analogRead(k_pShoulder), 60, 800, 0, 200);
  pElbow = map(analogRead(k_pElbow), 0, 850, 0, 180);
  pWrist = map(analogRead(k_pWrist), 300, 1023, 180, 0);
  //pGripper = map(analogRead(k_pGripper), 0, 1023, 0, 200);
  pGripper = analogRead(k_pGripper);
  sShoulder = map(analogRead(k_sShoulder), 400, 1023, 0, 200);
  
  if(pBase > pos_mBase+pTolerance){
    base.write(k_baseNeutral + k_baseCW*k_baseSpeed);
    pos_mBase += dk_Base;
  }
  else if(pBase < pos_mBase-pTolerance){
    base.write(k_baseNeutral + k_baseCCW*k_baseSpeed);
    pos_mBase += -dk_Base;
  }
  else{
    base.write(k_baseNeutral);
  }

  //lower value = forward/clockwise, higher value = backward/counterclockwise
  if(sShoulder < pShoulder+pTolerance && sShoulder > pShoulder-pTolerance) shoulder.write(k_shoulderNeutral);
  else if(sShoulder < pShoulder+pTolerance) shoulder.write(k_shoulderNeutral + k_shoulderCW*k_shoulderSpeed);
  else if(sShoulder > pShoulder-pTolerance) shoulder.write(k_shoulderNeutral + k_shoulderCCW*k_shoulderSpeed);
  
  elbow.write(pElbow);
  wrist.write(pWrist);
  
  if(pGripper > 900) gripper.write(k_gripperNeutral + k_gripperSpeed);
  else if(pGripper < 200) gripper.write(k_gripperNeutral - k_gripperSpeed);
  else gripper.write(k_gripperNeutral);
  
  Serial.println(String(analogRead(k_pShoulder)) + ", " + String(analogRead(k_sShoulder)) + ", " + String(pShoulder) + ", " + String(sShoulder) + ", " + String(shoulder.read()));
  //Serial.println(String(pShoulder) + ", " + String(sShoulder) + ", " + String(pid(pShoulder, sShoulder)));
  //Serial.println(String(pBase) + ", " + String(pos_mBase) + ", " + String(base.read()));
  //Serial.println(String(analogRead(k_pElbow)) + ", " + String(pElbow));
  //Serial.println(String(analogRead(k_pWrist)));
  //Serial.println(String(analogRead(k_pGripper)));
}

/*
double pid(int pShoulder, int sShoulder){

  Input = sShoulder;
  Setpoint = pShoulder;

  unsigned long now = millis();
  double timeChange = (double)(now - lastTime);
  
  double error = Setpoint - Input;
  errSum += (error * timeChange);
  double dErr = (error - lastErr) / timeChange;
  
  Output = kp * error + ki * errSum + kd * dErr;
  
  lastErr = error;
  lastTime = now;
  
  return Output;
}
*/
