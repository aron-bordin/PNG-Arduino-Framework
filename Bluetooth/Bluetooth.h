/**
 *     
    This file is part of .PNG Arduino Framework.

    .PNG Arduino Framework is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    .PNG Arduino Framework is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with .PNG Arduino Framework.  If not, see <http://www.gnu.org/licenses/>.
 */



#ifndef bluetooth_h
#define bluetooth_h

#include "Arduino.h"
#include <SoftwareSerial.h>


class Bluetooth{
private:
    int rxPin;
    int txPin;
    char PIN[32];
    SoftwareSerial *btSerial;
    char msg[1024];
    char name[255];
    char message_end;

public:
    Bluetooth(int r, int t);
    int getrxPin();
    int gettxPin();
    char * read();
    char * getName();
    char getMessageEnd();
    char * getPIN();
    void setMessageEnd(char end);
    void setName(char name[]);
    void setrxPin(int rx);
    void settxPin(int tx);
    void setPIN(int pin);
    void setupBluetooth();
    void send(char c[]);
};


#endif
