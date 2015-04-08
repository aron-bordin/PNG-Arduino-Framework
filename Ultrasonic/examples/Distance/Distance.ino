#include "Ultrasonic.h"

Ultrasonic *ult = new Ultrasonic(A5, A4);

void setup(){
	Serial.begin(9600);
}

void loop(){
	Serial.print("Raw distance = ");
	Serial.print(ult->readDistanceRaw());
	Serial.print(" - Distance(CM) = ");
	Serial.println(ult->readDistanceCM());
	delay(500);
}