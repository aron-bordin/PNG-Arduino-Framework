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


#ifndef motor_h
#define motor_h

#include "Arduino.h"

class Motor{
private:
	byte MOTOR1_A;
	byte MOTOR1_B;
	byte MOTOR1_PWM;
	byte MOTOR2_A;
	byte MOTOR2_B;
	byte MOTOR2_PWM;
	void setupPINs();
	void goMotor(byte m1_a, byte m1_b, byte m2_a, byte m2_b);

public:
	Motor(byte m1_a, byte m1_b, byte m1_pwm, byte m2_a, byte m2_b, byte m2_pwm);
	void setPINs(byte m1_a, byte m1_b, byte m1_pwm, byte m2_a, byte m2_b, byte m2_pwm);
	void setSpeed(byte v);
	void setMotorSpeed1(byte v);
	void setMotorSpeed2(byte v);
	void goFront();
	void goRight();
	void goRightStrong();
	void goLeft();
	void goLeftStrong();
	void goBack();
	void goStop();
};

#endif