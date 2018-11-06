Arduino Timer
=============

This module allow us to easily create Timer callbacks. In a predetermined interval, your function will be called. Works as a "thread", where a secondary function will run when necessary.

There are two types of timers

* **Default**: Will run the callback each interval
* **Single-shot**: Run only once. If you need to run a single shot timer again, use the method ->Start();


Simple Example
--------------

Include the library

.. code-block:: c

	#include "Timer.h"

Create a new Timer object

.. code-block:: c

	Timer *timer1 = new Timer(6000); //timer with 6 seconds

Add the following methods in **void setup()**

.. code-block:: c

	timer1->setOnTimer(&FunctionCallback);
	timer1->Start(); //start the thread.

Now add this method on **void loop()**

.. code-block:: c

	timer1->Update(); //will check the Timer and if necessary, will run it.


Full example - Two timers
-------------------------

.. code-block:: cpp

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


Documentation
-------------

**Timer(unsigned long int ms);** - Create a Timer with the time

**Timer(unsigned long int ms, CallBackType callback);** Create a Timer with time and callback

**Timer(unsigned long int ms, CallBackType callback, bool isSingle);** Create a Timer with time, callback and set if is single shot
	
**void setInterval(unsigned long int ms);** - Set callback interval

**void setEnabled(bool Enabled);** - Set if the timer is Enabled.

**void setSingleShot(bool isSingle);** - If isSingle is True, the callback will be called once, until you call Start() or Resume() again

**void setOnTimer(CallBackType callback);** - Set function callback

**void Start();** - Start the Timer. Will count the interval from the moment that you start it. If the timer is paused,it will restart the Timer.

**void Resume();** - Resume the Timer. If not started, will start it. If paused, will resume it. For example, in a timer of 5 seconds, if it was paused in 3 seconds, the resume in continue in 3 seconds.

**void Pause();** - Pause the timer, so you can resume it later.

**void Stop();** - Stop the timer.

**void Update();** - Must to be called in the loop(), will check the timer, and if necessary, will run the callback

**unsigned long int getInterval();** - Get the interval

**unsigned long int getCurrentTime();** - Get time passed since the last tick

**CallBackType getOnTimerCallback();** - Get the Timer Callback

**bool isEnabled();** - Check if the Timer is enabled

**bool isSingleShot();** - Check if it is Single Shot
