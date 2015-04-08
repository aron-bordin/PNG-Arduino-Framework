## Bluetooth

This module can be used to send and receive bluetooth data. If you want to connect your Arduino with a Bluetooth device, Arduino or any other, check the Helpers module to find some classes that will help you to connect them.
This module was tested with:
* BC417 Bluetooth to Serial
* Bluetooth-RS232 HC-05

It'll probably work with similar components. If you test it a component not listed here, please add a comment in my blog, open a pull request or edit this file to share if it's working or if you are getting some error.


## Example

Include the library
```c++
	#include "Bluetooth.h"
```

Create a new Bluetooth object
```c++
	Bluetooth *blue = new Bluetooth(5, 6);
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


## Methods

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

**void setupBluetooth();** - Setup the Bluetooth module

**void send(char c[]);** - Send a message

**void setPIN(int pin);** - Set bluetooth PIN
    

## Contribute

This library still under development. We need help adding new components and testing with differents Arduino and components versions. 
Any help will be appreciated :)