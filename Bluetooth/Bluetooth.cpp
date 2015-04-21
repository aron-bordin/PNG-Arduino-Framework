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
void Bluetooth::setName(char new_name[]){
    strcpy(name, "AT+NAME");
    strcat(name, new_name);
}

/**
 * Set the Serial Baudrate for the bluetooth module
 * @param baudrate value with the  baudrate
 */
void Bluetooth::setBaudrate(unsigned long baudrate){
    this->baudrate = baudrate;
}

/**
 * Setup Bluetooth settings. Must be used in Arduino setup()
 */
void Bluetooth::setupBluetooth(){
    btSerial->begin(baudrate);
    delay(1100);
    btSerial->write("AT");
    btSerial->write("AT+BAUD4");
    delay(1100);
    Serial.println("\nSetting bluetooth with 9600");
    while (btSerial->available())
        Serial.write(btSerial->read());

    btSerial->write(name);
    delay(1100);
    Serial.print("\nSetting Bluetooth name: ");
    Serial.println(name);

    while (btSerial->available()) 
        Serial.write(btSerial->read());

    btSerial->write(PIN);
    delay(1100);
    Serial.print("\nNew PIN: ");
    Serial.println(PIN);
    while (btSerial->available()) 
    Serial.write(btSerial->read());

    btSerial->write("AT+VERSION");
    delay(1100);
    Serial.print("\nBluetooth version");
    while (btSerial->available()) 
    Serial.write(btSerial->read());
}

/**
 * Create and start the Serial of Bluetooth object with RX and TX parameters.
 */
Bluetooth::Bluetooth(int r, int t){
    setrxPin(r);
    settxPin(t);
    setName("PNGFramework");
    setPIN(1234);
    setMessageEnd('\0');
    setBaudrate(9600);
    btSerial = new SoftwareSerial(r, t);
}

void Bluetooth::begin(){
    btSerial->begin(baudrate);
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

/**
 * Get the bluetooth PIN
 */
char *Bluetooth::getPIN(){
    return &PIN[0];
}

/**
 * Set the bluetooth PIN
 * @param pin [description]
 */
void Bluetooth::setPIN(int pin){
    char _pin[32];
    strcpy(PIN, "AT+PIN");
    sprintf(_pin, "%d", pin);
    strcat(PIN, _pin);
}