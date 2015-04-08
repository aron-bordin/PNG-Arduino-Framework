#include "Bluetooth.h"
#include <SoftwareSerial.h>

Bluetooth *blue = new Bluetooth(2, 3); //RX=2, TX=3

void setup(){
	Serial.begin(9600);
	blue->setName("Robo1-TCC");
	blue->setPIN(1234);
	blue->setMessageEnd('#');
	blue->setupBluetooth();
}

void loop(){
	String msg = blue->read();
	if (msg.length() > 0) {
		Serial.println(msg);
	}
}