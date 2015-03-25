# PNG-Arduino-Framework - Beta 0.1 - Bluetooth

.PNG - Programmers of New Generation


## About

PNG Framework was developed by stutents of Unesp - University of the State of São Paulo, Brazil, with the goal to turn Arduino project development easier. The framework has a chain of modular classes, compatible with some Arduino components. 


## Tutorials
* Bluetooth:
  * [How to connect an Android device with Arduino and bluetooth](https://bytedebugger.wordpress.com/2014/06/27/tutorial-how-to-connect-an-android-device-with-arduino-and-bluetooth/)


## Installation

1. Download the master branch from GitHub.
2. Unzip it
3. Move all folders to your Library folder (On your `Libraries` folder inside Sketchbooks of Arduino software).


## Bluetooth

This module can be used to send and receive bluetooth data. If you want to connect your Arduino with a Bluetooth device, Arduino or any other, check the Helpers module to find some classes that will help you to connect them.
This module was tested with:
* BC417 Bluetooth to Serial
* Bluetooth-RS232 HC-06

It'll probably work with similar components. If you test it a component not listed here, please add a comment in my blog, open a pull request or edit this file to share if it's working or if you are getting some error.


## Example

Inclued the libray
```c++
	#include "Bluetooth.h"
```

Create a new Bluetooth object
```c++
	Bluetooth *blue = new Bluetooth();
```

Add the following method in **void setup()**:
```c++
	blue->setupBluetooth();
```
Now you can use any method on **void loop()**:
```c++
	String msg = blue->read(); // read and receive a message
	blue->send("I'm sending a message");
```


## Documentation

**Bluetooth();** - Create a new Bluetooth object

**Bluetooth(int r, int t);** - Create a new Bluetooth object with RX and TX PINs

**int getrxPin();** - Get the RX PIN

**int gettxPin();** - Get the TX PIN

**char * read();** - Read and receive a message

**char * getName();** - Get the Bluetooth device name

**char getMessageEnd();** - Get the char that means 'end of string'

**void setMessageEnd(char end);** - Set the char that mean 'end of string'

**void setName(char name[]);** - Set Bluetooth device name

**void setrxPin(int rx);** - Set RX PIN

**void settxPin(int tx);** - Set TX PIN

**void setupBluetooth();** - Setup the Bluetooth module

**void send(char c[]);** - Send a message


## Contribute

This library still under development. We need help adding new components and testing with differents Arduino and components versions. 
Any help will be appreciated :)

## About .PNG team

[Aron Barreira Bordin](http://github.com/aron-bordin/)

Felipe Kutait

Hugo Waki

[Mateus Lopes](https://github.com/lopeslopes)

Matheus Barbosa

[Raul Pelegrini Neto](https://github.com/RaulPelegrini)

[Vinicius Moretto](https://github.com/vinimoretto)

Vitor Costanzo