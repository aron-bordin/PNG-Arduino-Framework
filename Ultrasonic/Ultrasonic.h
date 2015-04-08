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


#ifndef ultrasonic_h
#define ultrasonic_h

#include "Arduino.h"

class Ultrasonic{
private:
	int TRIGGER_PIN;
	int ECHO_PIN;

public:
	Ultrasonic(int T_PIN, int E_PIN);
	void setupPINs();
	void setTriggerPIN(int T_PIN);
	void setEchoPIN(int E_PIN);
	int getTriggerPIN();
	int getEchoPIN();
	float readDistanceCM();
	float readDistanceRaw();
};

#endif
