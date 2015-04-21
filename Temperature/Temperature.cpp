#include "Temperature.h"

/**
 * Create the Temperature Object with PIN
 */
Temperature::Temperature(int PIN){
	pin = PIN;
	pinMode(pin, INPUT);
}

/**
 * Get the temperature in C
 * @return value
 */
int Temperature::getTemperatureC(){
	return getTemperatureRaw()/1024.0*5000/10;
}

/**
 * Get the temperature in F
 * @return value
 */
int Temperature::getTemperatureF(){
	return (getTemperatureC() * 9)/5 + 32;
}

/**
 * Get the raw value from the sensor
 * @return value
 * 
 */
int Temperature::getTemperatureRaw(){
	return analogRead(pin);
}