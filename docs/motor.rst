Motor
=====

This module is used to control the L298 Dual H-Bridge Motor driver.
Tested with:

* L298


It'll probably work with similar components. If you test it a component not listed here, please add a comment in my blog, open a pull request or edit this file to share if it's working or if you are getting some error.


Simple Example
--------------

Include the library

.. code-block:: c

	#include "Motor.h"

Create a new Motor object. Set the PIN values as parameters, in this sequence: IN1, IN2, ENA, IN3, IN3, ENB

.. code-block:: c

	Motor *m = new Motor(6, 7, 5, 8, 9, 11);

Now you can use any method on **void loop()**

.. code-block:: c

	m->goFront();


Full example
------------
.. code-block:: cpp

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


Documentation
-------------

**Motor(byte m1_a, byte m1_b, byte m1_pwm, byte m2_a, byte m2_b, byte m2_pwm);** - Create the Motor with IN1, IN2, ENA, IN3, IN3, ENB

**void setPINs(byte m1_a, byte m1_b, byte m1_pwm, byte m2_a, byte m2_b, byte m2_pwm);** - Set IN1, IN2, ENA, IN3, IN3, ENB values

**void setSpeed(byte v);** - Set the speed of both motors. Value from 0 to 255

**void setMotorSpeed1(byte v);** - Set the speed of motor 1. Value from 0 to 255

**void setMotorSpeed2(byte v);** - Set the speed of motor 2. Value from 0 to 255

**void goFront();** - Go front  

**void goRight();** - Go right, activating one wheel

**void goRightStrong();** - Go right, activating both wheels

**void goLeft();** - Go left, activating one wheel

**void goLeftStrong();** - Go left, activating both wheels

**void goBack();** - Go back

**void goStop();** - Stop the movement