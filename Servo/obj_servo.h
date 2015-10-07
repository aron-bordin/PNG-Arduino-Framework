#ifndef OBJ_SERVO_H
#define OBJ_SERVO_H

#include "Arduino.h"
#include "Servo.h"

class ObjServo{
private:
	int PIN;
	Servo servo;

public:
	ObjServo();
	ObjServo(int P);
	void setPIN(int P);
	int getPIN();
	void rotate(int d);
	void setup();

};

#endif // OBJ_SERVO_H