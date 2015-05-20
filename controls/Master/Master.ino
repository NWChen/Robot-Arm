#include <Servo.h>

const int k_pBase = A3;
const int k_pShoulder = A4;
const int k_pElbow = A5;


const int k_vBase = 9;
const int k_vShoulder = 10;
const int k_vElbow = 11;

Servo vBase, vShoulder, vElbow;

int pBase, pShoulder, pElbow;
float i=0;

void setup() {
  Serial.begin(9600);
  vBase.attach(k_vBase);
  vShoulder.attach(k_vShoulder);
  vElbow.attach(k_vElbow);
}

void loop() {
  
  pBase = analogRead(k_pBase);
  pShoulder = analogRead(k_pShoulder);
  pElbow = analogRead(k_pElbow);
  
  Serial.print(pBase);
  Serial.print(", ");
  Serial.print(pShoulder);
  Serial.print(", ");
  Serial.print(pElbow);
  Serial.println();
  
  //vBase.write(map(pBase, 0, 1023, 70, 110));
  vShoulder.write(map(pShoulder, 300, 1000, 70, 110));
  
  delay(100);
  
  /*
  i += 0.1;
  vBase.write(90*(sin(i)+1));
  Serial.print(sin(i));
  Serial.print(" ");
  Serial.println(vBase.read());
  delay(100);
  */
}
    



