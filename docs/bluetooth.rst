Bluetooth
=========

This module can be used to send and receive bluetooth data. If you want to connect your Arduino with a Bluetooth device, Arduino, Android, iOS or any other, check the Helpers module to find some classes that will help you to connect them.
This module was tested with:

* Bluetooth-RS232 HC-05

It'll probably work with similar components. If you test it a component not listed here, please add a comment in my blog, open a pull request or edit this file to share if it's working or if you are getting some error.


Tutorials
---------

* `How to connect an Android device with Arduino and bluetooth <https://bytedebugger.wordpress.com/2014/06/27/tutorial-how-to-connect-an-android-device-with-arduino-and-bluetooth/>`_


Simple Example
--------------

Include the library

.. code-block:: c

	#include <SoftwareSerial.h>
	#include "Bluetooth.h"

Create a new Bluetooth object

.. code-block:: c

	Bluetooth *blue = new Bluetooth(5, 6);

Add the following method in **void setup()** to start the bluetooth serial

.. code-block:: c

	blue->begin();

Now you can use any method on **void loop()**

.. code-block:: c

	String msg = blue->read(); // read and receive a message
	blue->send("I'm sending a message");


Full example - Chat
-------------------
.. code-block:: cpp

	#include "Bluetooth.h"
	#include <SoftwareSerial.h>

	Bluetooth *blue = new Bluetooth(2, 3); //RX=2, TX=3

	void setup(){
		Serial.begin(9600);
		blue->setName("PNGArduinoFramework");
		blue->setPIN(6666);
		blue->setMessageEnd('#');
		blue->setupBluetooth(); //apply this changes to the module. You need to run it only in the first time
		blue->begin(); //start the bluetooth serial
	}

	void loop(){
		String msg = blue->read();
		if (msg.length() > 0) {
			Serial.println(msg);
		}
	}


Documentation
-------------

**Bluetooth(int r, int t);** - Create a new Bluetooth object with RX and TX PINs

**int getrxPin();** - Get the RX PIN

**int gettxPin();** - Get the TX PIN

**char * getPIN();** - Get Bluetooth PIN

**char * read();** - Read and receive a message

**char * getName();** - Get the Bluetooth device name

**char getMessageEnd();** - Get the char that means 'end of string'

**void setMessageEnd(char end);** - Set the char that mean 'end of string'

**void setName(char name[]);** - Set Bluetooth device name

**void setrxPin(int rx);** - Set RX PIN

**void settxPin(int tx);** - Set TX PIN

**void setupBluetooth();** - Apply the bluetooth changes(name or pin). Must be used in the **void setup()**

**void send(char c[]);** - Send a message

**void setPIN(int pin);** - Set bluetooth PIN

**void setBaudrate(unsigned long baudrate);** - Set the Bluetooth serial Baudrate

**void begin();** - Start the Bluetooth serial. Must be used in the **void setup()**