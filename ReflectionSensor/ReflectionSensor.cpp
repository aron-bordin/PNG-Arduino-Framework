#include "ReflectionSensor.h"

/**
 * Create ReflectionSensor object with a list of PINs
 */
ReflectionSensor::ReflectionSensor(int pins[]){
	int i;
	for(i = 0; i < 128; i++){
		bigger[i] = 0;
		smaller[i] = 9999;
    setPINLimit(i, 500);
  }
	setupPINs();
}

/**
 * Set the PIN limit to check if it's black. Default value: 500
 * @param int pin number
 * @param int value
 */
void ReflectionSensor::setPINLimit(int pin_number, int value){
  limit[pin_number] = value;
}

/**
 * Set pinMode
 */
void ReflectionSensor::setupPINs(){
	int i;
  for(i = 0; i < 128; i++){
    if(input_pins[i] && output_pins[i])
      pinMode(output_pins[i], OUTPUT);
    else
      break;
  }
}

/**
 * Return the analog read from sensor
 * @param byte n - sensor number
 * @return int by analogRead
 */
unsigned short int ReflectionSensor::rawSensor(byte n){
  digitalWrite(output_pins[n], HIGH);
  delay(1);
  int v = analogRead(input_pins[n]);
  digitalWrite(output_pins[n],LOW);
  Serial.println(v);
  return v;
}

/**
 * Read each sensor 200 times and calculate the average
 */
void ReflectionSensor::Calibrate(){ 
  for (int c=0; c<200; c++) {
    for (int i=0; i<128; i++)  {  
      if(!input_pins[i] || !output_pins[i])
        break;
      int v = rawSensor(i);
      if (v > bigger[i]) 
        bigger[i] = v;
      if (v < smaller[i])
        smaller[i] = v;
    }
    // delay(10);
  }  
  for (int i=0; i<100; i++) {
    if(!input_pins[i] || !output_pins[i])
        break;
    limit[i] = (smaller[i]+bigger[i])/2; 
  }
}

/**
 * Check if a sensor is reading a dark color comparated with the calibration
 * @param PIN number
 * @return int is black
 */
int ReflectionSensor::isBlack(int i){ 
  return rawSensor(i) > limit[i] ? 1 : 0;
}