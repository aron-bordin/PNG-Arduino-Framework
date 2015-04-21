#include "Temperature.h"

Temperature *temp = new Temperature(A7); //module PIN

void setup(){
	Serial.begin(9600);
}

void loop(){
	Serial.print("Temperature: ");
	Serial.print(temp->getTemperatureC());
	Serial.print(" degrees Celsius  ");
	Serial.print(temp->getTemperatureF());
	Serial.println(" degrees Fahrenheit");
	delay(500);
}