#include <Servo.h>

const int k_servo = 9;
Servo servo;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(k_servo);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  servo.write(-180);
  delay(1000);
  servo.write(180);
  delay(1000);
  */
  servo.write(83);
  Serial.println("83");
  delay(300);
  servo.write(90);
  delay(500);
  servo.write(105);
  Serial.println("105");
  delay(300);
}
