#include <Servo.h>

Servo MyServo;

char incomingByte;
int MyPosition = 90;


void setup() {
  MyServo.attach(8);
  MyServo.write(MyPosition);
  
  Serial.begin(9600);
}

void loop() {
  
//  MyPosition = MyPosition + 1;
//     MyServo.write(MyPosition);
//     
//     delay(50);
  
  if (Serial.available() > 0) {
    
    incomingByte = Serial.read();
    
    if(incomingByte == 'L') {
      MyPosition = MyPosition + 1;
      MyServo.write(MyPosition);
    }
    
    if(incomingByte == 'R') {
      MyPosition = MyPosition - 1;
      MyServo.write(MyPosition);
    }
  }
    delay(10);
    
}
        
