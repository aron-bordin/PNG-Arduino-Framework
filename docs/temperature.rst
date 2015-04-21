Temperature
===========

This module can be used to read the temperature. Tested with the following components:

* LM35

It'll probably work with similar components. If you test it a component not listed here, please add a comment in my blog, open a pull request or edit this file to share if it's working or if you are getting some error.


Example
-------

.. code-block:: c

	#include "Temperature.h"

	Temperature *temp = new Temperature(A7); //module PIN

	void setup(){
		Serial.begin(9600);
	}

	void loop(){
		Serial.print("Temperature: ");
		Serial.print(temp->getTemperatureC());
		Serial.print(" degrees Celsius  ");
		Serial.print(temp->getTemperatureF());
		Serial.println(" degrees Fahrenheit");
		delay(500);
	}


Methods
-------

**Temperature(int PIN);** - Create the Temperature object with the PIN

**int getTemperatureC();** - Get the temperature in Celsius

**int getTemperatureF();** - Get the Temperature in Fahrenheit

**int getTemperatureRaw();** - Return the raw value read by the sensor