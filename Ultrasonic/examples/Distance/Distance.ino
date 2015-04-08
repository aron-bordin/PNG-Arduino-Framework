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