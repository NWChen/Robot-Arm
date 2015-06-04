#include <Servo.h>

#define P_BASE A5
#define P_SHOULDER A3
#define P_ELBOW A4
#define P_WRIST A2
#define P_GRIPPER A1

#define V_BASE 9
#define V_SHOULDER 10
#define V_ELBOW 11
#define V_WRIST 8
#define V_GRIPPER 5

#define STOPVALUE 90

int posPB_offset = 0;
int posPS_offset = 0;
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist;
Servo gripper;

int posVB = 0;
int posPB = 0;
const double kB = 1;

int posVS = 0;
int posPS = 0;
const double kS = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  base.attach(V_BASE);
  shoulder.attach(V_SHOULDER);
  elbow.attach(V_ELBOW);
  wrist.attach(V_WRIST);
  posPB_offset = analogRead(P_BASE);
  posPS_offset = analogRead(P_SHOULDER);
}

void loop() {
  // put your main code here, to run repeatedly:
  posPB = map(analogRead(P_BASE), 0, 1023, 150, -150);
  if(posPB > posVB){
    base.write(103);
    posVB += kB;
  }
  else if(posPB < posVB){
    base.write(83);
    posVB += -kB;
  }
  else{
    base.write(90);
  }
  //Serial.println(String(posPB) + ", " + String(posVB));
  
  posPS = map(analogRead(P_SHOULDER), -142, -700, -120, 90);
  //posPS = analogRead(P_SHOULDER);
  if(posPS > posVS){
    shoulder.write(110);
    posVS += kS;
  }
  else if(posPS < posVS){
    shoulder.write(85);
    posVS += -kS;
  }
  else{
    shoulder.write(90);
  }
  Serial.println(String(posPS) + ", " + String(posVS));  
  delay(20);
}


