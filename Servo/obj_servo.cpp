#include "obj_servo.h"

/**
 * Create the servo object
 */
ObjServo::ObjServo(){
	PIN = 4;
}

/**
 * Create the servo object with PIN value
 */
ObjServo::ObjServo(int P){
	setPIN(P);
}

/**
 * Set the PIN value
 * @param P PIN number
 */
void ObjServo::setPIN(int P){
	PIN = P;
	this->setup();
}

/**
 * Setup the PIN and rotate the servo to 0
 */
void ObjServo::setup(){
	servo.attach(PIN);
	servo.write(0);
}

/**
 * Get the servo PIN number
 * @return int number of the PIN
 */
int ObjServo::getPIN(){
	return PIN;
}

/**
 * Rotate the servo
 * @param d servo position
 */
void ObjServo::rotate(int d){
	servo.write(d);
}
