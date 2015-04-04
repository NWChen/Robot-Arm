This arm is meant to be put together with as few parts as possible, to achieve mechanical simplicity while maintaining good arm control. 

Currently the control system is based on:
- Arduino Mega 2560 
- Arduino Mega Sensor Shield (optional)
- 12V SLA Battery
- Victor 884/Victor 888/Talon SR/any other 20A+ DC motor controller
	- We'd like to avoid Jaguars because of their frequency issues with window motors, and their PWM input issues (especially with Arduino)
- Copious amounts of turnpots and servos

There's a possibility of including relays or manual switches for use with an electromagnet.