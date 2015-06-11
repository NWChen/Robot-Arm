#include <Servo.h>

//puppet, A1 to A5
#define k_pBase A1
#define k_pShoulder A2
int pShoulder = 0;

//sensors, A0
#define k_sShoulder A0
int sShoulder = 0;

//motors, 8 to 11
#define k_mBase 10
#define k_mShoulder 9

//servo objects
Servo base;
Servo shoulder;

//constants
const int pTolerance = 4;
#define k_baseNeutral 90
const float k_baseCCW = -1; //<90 = counterclockwise
const float k_baseCW = 1; //>90 = clockwise, usually greater than CCW offset
const float k_baseSpeed = 10;
#define k_shoulderNeutral 90
const float k_shoulderCW = 2.2; //<90 = clockwise when facing hub
const float k_shoulderCCW = -1; //>90 = counterclockwise when facing hub, usually greater than CW offset
const float k_shoulderSpeed = 6;

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
}

void loop() {
  pShoulder = int(map(analogRead(k_pShoulder), 35, 770, 0, 200));
  sShoulder = int(map(analogRead(k_sShoulder), 330, 1023, 0, 200));
  //Serial.println(String(pShoulder) + ", " + String(sShoulder) + ", " + String(pid(pShoulder, sShoulder)));
  //lower value = forward/clockwise, higher value = backward/counterclockwise
  if(sShoulder < pShoulder+pTolerance && sShoulder > pShoulder-pTolerance) shoulder.write(k_shoulderNeutral);
  else if(sShoulder < pShoulder+pTolerance) shoulder.write(k_shoulderNeutral + k_shoulderCW*k_shoulderSpeed);
  else if(sShoulder > pShoulder-pTolerance) shoulder.write(k_shoulderNeutral + k_shoulderCCW*k_shoulderSpeed);
  else shoulder.write(k_shoulderNeutral);
  Serial.println(String(pShoulder) + ", " + String(sShoulder) + ", " + String(shoulder.read()));
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
