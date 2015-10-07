#ifndef ReflectionSensor_h
#define ReflectionSensor_h

#include "Arduino.h"


class ReflectionSensor{
private:
	int bigger[128];
	int smaller[128];
	int limit[128];
	void setupPINs();
	int input_pins[128];
	int output_pins[128];


public:
	ReflectionSensor(int input_pins[]);
	void Calibrate();
	int isBlack(int i);
	unsigned short int rawSensor(byte n);
	void setPINLimit(int pin_number, int value);
};

#endif