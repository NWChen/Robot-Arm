#include <Arduino.h>
#include <Controller.h>
#include <string>

double startTime; //time at which a motor should start moving
double endTime; //time at which a motor should stop moving
int previous; //previous potentiometer value
int current; //current potentiometer value
int setValue; //distance from 90
boolean finished;

//constructor
Controller::Controller(){
  previous = 0;
  current = 0;
  setValue = 90;
  finished = true;
}

//watch time and schedule actions
int Controller::update(double t){ //current time
  endTime = startTime + 10 * abs(current-previous);
  if(t==endTime || current-previous==0){
    setValue = 0;
    finished = true;
  }
  else{
    setValue = (current-previous)>0? 15:-15;
    finished = false;
  }
  return setValue;
}

//output controller information
string Controller:toString(){
  std::stringstream s;
  s << startTime << ":" endTime << ", " << previous << ":" << current << ", " << setValue;
  return s.str();
}