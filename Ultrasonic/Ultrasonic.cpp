/**
 *     
	This file is part of .PNG Arduino Framework.

    .PNG Arduino Framework is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    .PNG Arduino Framework is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with .PNG Arduino Framework.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "Ultrasonic.h"

/**
 * Create the Ultrasonic object with PINs
 * @param T_PIN  Trigger PIN
 * @param E_PIN  Echo PIN
 */
Ultrasonic::Ultrasonic(int T_PIN, int E_PIN){
	setTriggerPIN(T_PIN);
	setEchoPIN(E_PIN);
	setupPINs();
}

/**
 * Setup PINs
 */
void Ultrasonic::setupPINs(){
	pinMode(TRIGGER_PIN,OUTPUT);
	pinMode(ECHO_PIN,INPUT);	
}

/**
 * Set Trigger PIN
 * @param T_PIN Trigger PIN value
 */
void Ultrasonic::setTriggerPIN(int T_PIN){
	TRIGGER_PIN = T_PIN;
}

/**
 * Set ECHO PIN
 * @param E_PIN ECHO PIN value
 */
void Ultrasonic::setEchoPIN(int E_PIN){
	ECHO_PIN = E_PIN;
}

/**
 * Get the Trigger PIN
 * @return int Trigger PIN
 */
int Ultrasonic::getTriggerPIN(){
	return TRIGGER_PIN;
}

/**
 * Get echo PIN
 * @return in ECHO Pin value
 */
int Ultrasonic::getEchoPIN(){
	return ECHO_PIN;
}

/**
 * Get the distance read in cm
 * @return float distance
 */
float Ultrasonic::readDistanceCM(){
	return(readDistanceRaw()/29/2);
}

/**
 * Read the raw distance value 
 * @return float raw distance in time
 */
float Ultrasonic::readDistanceRaw(){
	digitalWrite(TRIGGER_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIGGER_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIGGER_PIN, LOW);
	long duration = pulseIn(ECHO_PIN, HIGH);
	return duration;
}