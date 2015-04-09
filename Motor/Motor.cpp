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


#include "Motor.h"


/**
 * Create the motor instance with parameters
 * @param m1_a   [description]
 * @param m1_b   [description]
 * @param m1_pwm [description]
 * @param m2_a   [description]
 * @param m2_b   [description]
 * @param m2_pwm [description]
 */
Motor::Motor(byte m1_a, byte m1_b, byte m1_pwm, byte m2_a, byte m2_b, byte m2_pwm){
	setPINs(m1_a, m1_b, m1_pwm, m2_a, m2_b, m2_pwm);
	setSpeed(100);
	setupPINs();
}

/**
 * Setup PINs
 */
void Motor::setupPINs(){
	pinMode(MOTOR1_A, OUTPUT);
	pinMode(MOTOR1_B, OUTPUT);
	pinMode(MOTOR1_PWM, OUTPUT);
	pinMode(MOTOR2_A, OUTPUT);
	pinMode(MOTOR2_B, OUTPUT);
	pinMode(MOTOR2_PWM, OUTPUT);
}

/**
 * Set PINs values
 * @param m1_a   [description]
 * @param m1_b   [description]
 * @param m1_pwm [description]
 * @param m2_a   [description]
 * @param m2_b   [description]
 * @param m2_pwm [description]
 */
void Motor::setPINs(byte m1_a, byte m1_b, byte m1_pwm, byte m2_a, byte m2_b, byte m2_pwm){
	MOTOR1_A = m1_a;
	MOTOR1_B = m1_b;
	MOTOR1_PWM = m1_pwm;
	MOTOR2_A = m2_a;
	MOTOR2_B = m2_b;
	MOTOR2_PWM = m2_pwm;
}

/**
 * Set speed
 * @param v speed, from 0 to 255
 */
void Motor::setSpeed(byte v){
	if((v <=0 ) || (v >= 255))
		return;
	analogWrite(MOTOR1_PWM, v);
	analogWrite(MOTOR2_PWM, v);
}

/**
 * Set the speed of motor one
 * @param v [description]
 */
void Motor::setMotorSpeed1(byte v){
	if((v <=0 ) || (v >= 255))
		return;
	analogWrite(MOTOR1_PWM, v);
}

/**
 * Set the speed of motor two
 * @param v [description]
 */
void Motor::setMotorSpeed2(byte v){
	if((v <=0 ) || (v >= 255))
		return;
	analogWrite(MOTOR2_PWM, v);
}

/**
 * 
 * Change PINs values
 * @param m1_a [description]
 * @param m1_b [description]
 * @param m2_a [description]
 * @param m2_b [description]
 */
void Motor::goMotor(byte m1_a, byte m1_b, byte m2_a, byte m2_b){
	digitalWrite(MOTOR1_A, m1_a);
	digitalWrite(MOTOR1_B, m1_b);
	digitalWrite(MOTOR2_A, m2_a);
	digitalWrite(MOTOR2_B, m2_b);
}

/**
 * Move the robot to the front
 */
void Motor::goFront(){
	goMotor(1, 0, 0, 1);
}

/**
 * Move the robot to the right
 */
void Motor::goRight(){
	goMotor(1, 0, 0, 0);
}

/**
 * Move the the robot strongly to the right
 */
void Motor::goRightStrong(){
	goMotor(1, 0, 1, 0);
}

/**
 * Move the robot to the left
 */
void Motor::goLeft(){
	goMotor(0, 0, 0, 1);
}

/**
 * Move the robot strongly to the left
 */
void Motor::goLeftStrong(){
	goMotor(0, 1, 0, 1);
}

/**
 * MOve the robot back
 */
void Motor::goBack(){
	goMotor(0, 1, 1, 0);
}

/**
 * Stop the robot moviments
 */
void Motor::goStop(){
	goMotor(0, 0, 0, 0);
}
