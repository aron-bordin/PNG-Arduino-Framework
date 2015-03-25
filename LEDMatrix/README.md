# PNG-Arduino-Framework - Beta 0.1  - LED Matrix

.PNG - Programmers of New Generation


## About

PNG Framework was developed by stutents of Unesp - University of the State of São Paulo, Brazil, with the goal to turn Arduino project development easier. The framework has a chain of modular classes, compatible with some Arduino components. 


## Installation

1. Download the master branch from GitHub.
2. Unzip it
3. Move all folders to your Library folder (On your `Libraries` folder inside Sketchbooks of Arduino software).


## LED Matrix

This module will help you to work with [16x16 LED Matrix with Arduino](http://www.elabpeers.com/led-matrix-display.html).

You can read the full tutorial here: https://bytedebugger.wordpress.com/2015/01/28/tutorial-how-to-use-dot-led-matrix-display-with-arduino/


## Tutorials

* [How to use Dot LED Matrix Display with Arduino](https://bytedebugger.wordpress.com/2015/01/28/tutorial-how-to-use-dot-led-matrix-display-with-arduino/)
* [Flappy Duino – Creating an Arduino clone of Flappy Bird with LED Matrix](https://bytedebugger.wordpress.com/2015/01/29/flappy-duino-creating-an-arduino-clone-of-flappy-bird-with-led-matrix/)


## Example
```c++

	#include "LedMatrixObject.h"


	LedMatrixObject *led = new LedMatrixObject(2, 3, 4, 5, 6, 7, 8, 9);

	unsigned char  Scene[16][16] = {
	    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
	    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
	    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	    {1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
	    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
	    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	void setup(){

	}

	void loop(){
		led->setScene(Scene);
		led->setLedOn(0, 0);
		led->setLedOff(8, 5);
		led->draw();
	}
```


# Documentation

**LedMatrixObject(byte LEDARRAY_D, byte LEDARRAY_C, byte LEDARRAY_B, byte LEDARRAY_A, byte LEDARRAY_G, byte LEDARRAY_DI, byte LEDARRAY_CLK, byte LEDARRAY_LAT);** - Create the LED matrix

**void clear();** - clear the scene

**void draw();** - draw the scene on the led matrix - call it on loop()

**void setScene(unsigned char  Scene[16][16]);** - set and Scene[16][16]

**void setLedOn(int x, int y);** - Turn on the led x, y on

**void setLedOff(int x, int y);** -  Turn off the led x,y

**void toggleLed(int x, int y);** -  Toggle the state of the led x,y


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