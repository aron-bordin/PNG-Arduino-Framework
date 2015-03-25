#include "Bluetooth.h"

/**
 * Get Bluetooth RX PIN
 * @return int - rx PIN
 */
int Bluetooth::getrxPin(){
    return rxPin;
}

/**
 * Set Bluetooth RX PIN
 * @param int RX PIN
 */
void Bluetooth::setrxPin(int rx){
    rxPin = rx;
}

/**
 * Get Bluetooth TX PIN
 * @return int TX PIN
 */
int Bluetooth::gettxPin(){
    return txPin;
}

/**
 * Set Bluetooth TX PIN
 * @param int TX PIN
 */
void Bluetooth::settxPin(int tx){
    txPin = tx;
}

/**
 * Get Bluetooth device name
 * @return *char device name
 */
char * Bluetooth::getName(){
    return &name[0];
}

/**
 * Set message char that represents the end of message. Default '\0'
 * @param char end of the message
 */
void Bluetooth::setMessageEnd(char end){
    message_end = end;
}

/**
 * Get the message end delimiter
 * @return char end of messages
 */
char Bluetooth::getMessageEnd(){
    return message_end;
}

/**
 * Set Bluetooth device name
 * @param char[] name
 */
void Bluetooth::setName(char name[]){
    strcpy(name, this->name);
}

/**
 * Setup Bluetooth settings. Must be used in Arduino setup()
 */
void Bluetooth::setupBluetooth(){
    btSerial = new SoftwareSerial(rxPin, txPin);
    pinMode(txPin, OUTPUT);
    pinMode(rxPin, INPUT);

    btSerial->begin(9600);

    Serial.println("Setting bluetooth with 9600");
    btSerial->write("AT+BAUD4");
    while (btSerial->available()) 
        Serial.write(btSerial->read());

    Serial.println("\nSetting Bluetooth name");
    char _name[255];
    strcpy(_name, "AT+NAME");
    strcat(_name, name);
    btSerial->write(name);

    while (btSerial->available()) 
        Serial.write(btSerial->read());

    Serial.println("\nConfigurando PIN para 6666");
    btSerial->write("AT+PIN6666");
    delay(1100);
    while (btSerial->available()) 
    Serial.write(btSerial->read());

    Serial.println("\nVersao do bluetooth");
    btSerial->write("AT+VERSION");
    delay(1100);
    while (btSerial->available()) 
    Serial.write(btSerial->read());
}

/**
 * Create Bluetooth object with RX = 2 and TX = 3
 */
Bluetooth::Bluetooth(){
    setrxPin(2);
    settxPin(3);
    btSerial = new SoftwareSerial(2, 3);
    setName("PNGFramework");
}

/**
 * Create Bluetooth objct with RX and TX parameters.
 */
Bluetooth::Bluetooth(int r, int t){
    setrxPin(r);
    settxPin(t);
    setName("PNGFramework");
    btSerial = new SoftwareSerial(r, t);
}

/**
 * Read received message
 * @return
 */
char * Bluetooth::read(){
    int i = 0;
    char c;
    char ch[1024];
    if(btSerial->available())
        while(1){
            c = btSerial->read();
            ch[i++] = c;
            if(c == message_end)
              break;
        }
    ch[i] = '\0';
    strcpy(msg, ch);
    return &msg[0];
}


/**
 * Send a message to the connected device by Bluetooth
 * @param char[] message
 */
void Bluetooth::send(char c[]){
    btSerial->print(c);
}