#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist;

int position = 0;
char incomingByte;

void setup() {
  base.attach(9);
  shoulder.attach(10);
  elbow.attach(11);
  wrist.attach(8);
  wrist.write(position);
  Serial.begin(9600);
}

void loop() {
  
  if (Serial.available() > 0) {
    
    incomingByte = Serial.read();
    
    if(incomingByte == 'R') {
      base.write(110);
      delay(10);
      freezeAll();
    }
    
    if(incomingByte == 'L') {
      base.write(70);
      delay(10);
      freezeAll();
    }
    
    if(incomingByte == 'U'){
      shoulder.write(130);
      delay(10); 
      freezeAll();
    }
    
    if(incomingByte == 'D'){
      shoulder.write(70);
      delay(10);
      freezeAll();
    }
    
    if(incomingByte == 'W' || incomingByte == 'w'){
      elbow.write(120);
      delay(10);
      freezeAll();
    }
    
    if(incomingByte == 'Q' || incomingByte == 'q'){
      elbow.write(80);
      delay(10);
      freezeAll();
    }
    
    if(incomingByte == 'A' || incomingByte == 'a'){
      position = position + 1;
      wrist.write(position);
      delay(10);
      freezeAll();
    }
    
    if(incomingByte == 'S' || incomingByte == 's'){
      position = position - 1;
      wrist.write(position);
      delay(10);
      freezeAll();
    }    
  }
  
  Serial.println(incomingByte);
    delay(10);
    
}

void freezeAllExcept(String motor){
  if(motor=="base"){
    shoulder.write(90);
    elbow.write(90);
  }
  
  if(motor=="shoulder"){
    base.write(90);
    elbow.write(90);
  }
  
  if(motor=="elbow"){
    base.write(90);
    shoulder.write(90);
  }
}  

void freezeAll(){
  base.write(90);
  shoulder.write(90);
  elbow.write(93);
}
