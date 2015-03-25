#ifndef bluetooth_h
#define bluetooth_h

#include "Arduino.h"
#include <SoftwareSerial.h>


class Bluetooth{
private:
    int rxPin;
    int txPin;
    SoftwareSerial *btSerial;
    char msg[1024];
    char name[255];
    char message_end;

public:
    Bluetooth();
    Bluetooth(int r, int t);
    int getrxPin();
    int gettxPin();
    char * Read();
    char * getName();
    char getMessageEnd();
    void setMessageEnd(char end);
    void setName(char name[]);
    void setrxPin(int rx);
    void settxPin(int tx);
    void setupBluetooth();
    void Send(char c[]);
};


#endif
