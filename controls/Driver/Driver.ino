//feels like the wrong way to do things
//should probably start a timer instead of delaying
#include <Servo.h>

//potentiometer analog inputs
const int k_pBase = A5;
const int k_pShoulder = A3;
const int k_pElbow = A4;

//switch analog inputs
const int k_sZero = A0;

//PWM digital outputs
const int k_vBase = 9;
const int k_vShoulder = 8;
const int k_vElbow = 7;

//speed coefficients
short kBase = 1;
short kShoulder = 1;
short kElbow = 1;

//motor controller objects
Servo base;
Servo shoulder;
Servo elbow;

//time/state constants (ms)
const int refresh_rate = 20;
const int deadband = 10;
int offset;
int multiplier; //TODO: switch to function later on? time multiplier
int[3] duration;
int[3] value; 

//set of potentiometer positions
int[3] previous;
int[3] current;

void setup(){
  Serial.begin(9600); //baud rate
  
  //associate motor controllers with PWM ports
  base.attach(k_vBase);
  shoulder.attach(k_vShoulder);
  elbow.attach(k_vElbow);
}

void loop(){
  //TODO: add switch zeroing condition
 
  updatePots();
  //update motor values
  for(int i=0; i<previous.length(); i++){
    offset = current[i]-previous[i];
    //determine which direction to rotate
    if(offset > 0) value[i] = 1;
    else value[i] = -1;
    
    value[i] = value[i] * 15; //speed multiplier
    
    if(abs(offset) > deadband) duration[i] = multiplier*offset;
    else duration[i] = 0;
  }
  
  //how the fuck do you update concurrently but stop at different times?
  base.write(90 + value[0]);
  shoulder.write(90 + value[1]);
  elbow.write(90 + value[2]);
  
  
}

//freeze all motors
void halt(){
  base.write(90);
  shoulder.write(90);
  elbow.write(90);
}

boolean updatePots(){
  previous[0] = analogRead(k_pBase);
  previous[1] = analogRead(k_pShoulder);
  previous[2] = analogRead(k_pElbow);
  delay(refresh_rate);
  current[0] = analogRead(k_pBase);
  current[1] = analogRead(k_pShoulder);
  current[2] = analogRead(k_pElbow);
}

//establish puppet state as position = 0 for all joints
void zero(){
  for(int i=0; i<previous.length(); i++){
    previous[i] = 0;
    current[i] = 0;
  }
}
