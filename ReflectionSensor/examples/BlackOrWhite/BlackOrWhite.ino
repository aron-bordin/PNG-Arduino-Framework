#include "ReflectionSensor.h"

int pins[] = {A0};  //reads data from two sensors

ReflectionSensor *r = new ReflectionSensor(pins);

void setup(){
	Serial.begin(9600);

	r->Calibrate(); //auto-learn the diff between black and white
}

void loop(){
	Serial.print("Sensor 1: ");
	Serial.println(r->isBlack(0) ? "Black" : "White");
	delay(1000);

}