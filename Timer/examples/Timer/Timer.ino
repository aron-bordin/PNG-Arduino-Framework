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


#include "Timer.h"

Timer *timer1 = new Timer(6000);
Timer *timer2 = new Timer(500);


void setup(){
	Serial.begin(9600);
	timer1->setOnTimer(&PrintHello1);
	timer1->Start();

	timer2->setOnTimer(&PrintHello2);
	timer2->Start();

}

void PrintHello1(){
	Serial.println("Hello timer 1 !!");
}

void PrintHello2(){
	Serial.println("Hello timer 2!!");
}
void loop(){
	timer1->Update();
	timer2->Update();
}