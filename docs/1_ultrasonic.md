## Ultrasonic

This module can be used to read distance with ultrasonic on Arduino.
This module was tested with:

* HC-SR04

It'll probably work with similar components. If you test it a component not listed here, please add a comment in my blog, open a pull request or edit this file to share if it's working or if you are getting some error.


## Simple Example

Include the library
```c++
#include "Ultrasonic.h"
```

Create a new Ultrasonic object
```c++
Ultrasonic *ult = new Ultrasonic(A5, A4); //TRIGGER_PIN and ECHO_PIN
```

Now you can use any method on **void loop()**:
```c++
Serial.println(ult->readDistanceCM());
```

## Full example - Chat
```c++
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

```


## Methods

**Ultrasonic(int T_PIN, int E_PIN);** - Create the Ultrasonic object
**void setupPINs();** - If you change any PIN value, you'll need to run this method to update it
**void setTriggerPIN(int T_PIN);** - Set the TRIGGER_PIN
**void setEchoPIN(int E_PIN);** - Set the ECHO_PIN
**int getTriggerPIN();** - Get the TRIGGER_PIN
**int getEchoPIN();** - Get the ECHO_PIN
**float readDistanceCM();** - Read the distance in CM
**float readDistanceRaw();** - Read the raw value returned by the sensor
    

## Contribute

This library still under development. We need help adding new components and testing with differents Arduino and components versions. 
Any help will be appreciated :)