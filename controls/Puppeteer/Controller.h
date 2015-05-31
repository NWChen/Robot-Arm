#ifndef Controller_h
#define Controller_h

#include "Arduino.h"

class Controller{
	public:
		Controller();
		int update();
		String toString();
};

#endif
