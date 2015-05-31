#include <Controller.h>
#include <Servo.h>

#define P_BASE A5
#define P_SHOULDER A4
#define P_ELBOW A3
#define P_WRIST A2
#define P_GRIPPER A1

#define V_BASE 9
#define V_SHOULDER 8
#define V_ELBOW 7
#define V_WRIST 6
#define V_GRIPPER 5

#define STOPVALUE 90

float time;
Controller base;
Controller shoulder;
Controller elbow;
Controller controllers[] = {base, shoulder, elbow};
int potentiometers[] = {P_BASE, P_SHOULDER, P_ELBOW, P_WRIST, P_GRIPPER};

void setup(){
  Servo vbase;
  Servo vshoulder;
  Servo velbow;
  Servo vwrist;
  vbase.attach(V_BASE);
  vshoulder.attach(V_SHOULDER);
  velbow.attach(V_ELBOW);
  vwrist.attach(V_WRIST); 
  base = Controller();
  shoulder = Controller();
  elbow = Controller();  
  time = 0;
}

void loop(){
  time = millis();
  for(int i=0; i<3; i++){
    controllers[i].update(time);
    if(controllers[i].finished){
      controllers[i].previous = analogRead(potentiometers[i]);
      if(hasElapsed(time, 20)){
        time = millis();
        controllers[i].current = time;
        controllers[i].startTime = time; 
      }
    }
    Serial.println(controllers[i].toString());
  }
  Serial.println(" - - - ");
}

//wait for a time period in ms
boolean hasElapsed(int startTime, int duration){ 
  if(millis()==startTime + duration) return true;
  return false;
}


