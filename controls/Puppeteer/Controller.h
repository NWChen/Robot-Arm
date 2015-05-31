#ifndef Controller_h
#define Controller_h

#include "Arduino.h"

class Controller{
	public:
		double startTime; 
		double endTime; 
		int previous; 
		int current; 
		int setValue; 
		bool finished;
		Controller();
		int update(double t);
		String toString();
};

#endif