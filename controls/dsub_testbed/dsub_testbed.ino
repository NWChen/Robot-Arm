#include <Servo.h>

const int k_pBase = A5;
const int k_pElbow = A4;
const int k_pShoulder = A3;
const int k_pWrist = A2;
const int k_pGripper = A1;

const int vBase = 8;
int previous = 0, current = 0;
float k = 1;
int t = 0;
Servo base;

void setup() {
  Serial.begin(9600);
  base.attach(vBase);
}

void loop() {
  
  previous = analogRead(k_pBase);
  delay(20);
  current = analogRead(k_pBase);
  
  if(current-previous > 0){
    k=2;
  }
  else{
    k=-2;
  }

  if(abs(current-previous) > 2){
    t = 15*abs(current-previous);
  }
  else{
    t = 0;
  }
  base.write(90 + (k*15));
  delay(t);
  //Serial.println(t);
  halt();
  
  Serial.print(analogRead(k_pBase));
  Serial.print(", ");
  Serial.print(analogRead(k_pElbow));
  Serial.print(", ");
  //Serial.println(analogRead(k_pShoulder));
}

void halt(){
  base.write(90);
}
    



