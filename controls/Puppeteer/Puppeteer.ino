#include <Servo.h>

class controller{
  public:
  float starttime; //time at which a motor should start moving
  float endtime; //time at which a motor should stop moving
  int previous; //previous potentiometer value
  int current; //current potentiometer value
  int setvalue; //value sent to Victor
  char joint; //joint identification
  
  //constructor
  controller(char j){
    previous = 0;
    current = 0;
    setvalue = 90; 
    joint = j;
  }
  
  //watch time and schedule actions
  void update(float t){ //current time
    if(
  }

  //output controller information
  String toString(){
    return j + ": " + starttime + ", " + endtime + ", " + previous + ", " + current + ", " + setValue;
  }
}  
const int k_pBase = A5;
const int k_pShoulder = A4;
const int k_pElbow = A3;



