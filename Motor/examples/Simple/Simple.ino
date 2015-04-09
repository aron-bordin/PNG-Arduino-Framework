#include "Motor.h"

Motor *m = new Motor(6, 7, 5, 8, 9, 11);

void setup(){
	m->setSpeed(200); //value from 0 to 255

}

void loop(){
	m->goFront();
	delay(1000);
	m->goRightStrong();
	delay(1000);
	m->goBack();
	delay(1000);
	m->goRightStrong();
	delay(1000);
}