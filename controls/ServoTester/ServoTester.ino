#include <Servo.h>

const int k_servo = 12;
Servo servo;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(k_servo);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(-180);
  delay(1000);
  servo.write(180);
  delay(1000);
}
