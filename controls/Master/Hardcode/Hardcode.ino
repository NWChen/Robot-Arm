#include <Servo.h>

const int k_vBase = 9;
const int k_vShoulder = 10;
const int k_vElbow = 11;
const int k_vWrist = 8;

Servo vBase, vShoulder, vElbow, vWrist;

float i=0;

boolean baseDone = false;
boolean shoulderDone = false;
boolean elbowDone = false;
boolean wristDone = false;

void setup() {
  Serial.begin(9600);
  vBase.attach(k_vBase);
  vShoulder.attach(k_vShoulder);
  vElbow.attach(k_vElbow);
  vWrist.attach(k_vWrist);
}

void loop() {
  
  Serial.println("base");
  if(!baseDone){
    vBase.write(100);
    delay(100);
    baseDone = true;
    vBase.write(90);
  }
  
  delay(500);
  
  Serial.println("shoulder");
  if(!shoulderDone){
    vShoulder.write(60);
    delay(200);
    shoulderDone = true;
    vShoulder.write(90);
  }  
  
  delay(500);
  
  Serial.println("elbow");
  if(!elbowDone){
    vElbow.write(80);
    delay(100);
    elbowDone = true;
    vElbow.write(90);
  }
  
  delay(500);
  
  Serial.println("wrist");
  if(!wristDone){
    vWrist.write(100);
    delay(100);
    wristDone = true;
  }
  
  delay(1000);
  Serial.println("done");
}
    



