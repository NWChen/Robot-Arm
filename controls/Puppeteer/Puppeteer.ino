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

int time;
Controller base;
Controller shoulder;
Controller elbow;
Controller controllers[3] = {base, shoulder, elbow};
Servo victors[3] = {};
int potentiometers[5] = {P_BASE, P_SHOULDER, P_ELBOW, P_WRIST, P_GRIPPER};

void setup(){
  Serial.begin(9600);
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
  victors[0] = vbase;
  victors[1] = vshoulder;
  victors[2] = velbow;
}

void loop(){
  time = millis();
  for(int i=0; i<3; i++){
    victors[0].write(STOPVALUE + controllers[i].watch(time));
    
    int previous = analogRead(potentiometers[i]);
    delay(20);
    int current = analogRead(potentiometers[i]);
    
    time = millis();
    controllers[i].watch(time);
    
    if(controllers[i].finished && abs(current-previous)>2){
      controllers[i].previous = previous;
      controllers[i].current = current;
      controllers[i].startTime = time; 
    }
    
    Serial.println(controllers[0].toString());
  }
  //Serial.println(" - - - ");
}

//wait for a time period in ms
boolean hasElapsed(int startTime, int duration){ 
  if(millis()==startTime + duration) return true;
  return false;
}



