/**
 *     
 	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "LedMatrixObject.h"

LedMatrixObject::LedMatrixObject(
			byte LEDARRAY_D, byte LEDARRAY_C, 
			byte LEDARRAY_B, byte LEDARRAY_A, 
			byte LEDARRAY_G, byte LEDARRAY_DI, 
			byte LEDARRAY_CLK, byte LEDARRAY_LAT){

	this->LEDARRAY_D = LEDARRAY_D;
	this->LEDARRAY_C = LEDARRAY_C;
	this->LEDARRAY_B = LEDARRAY_B;
	this->LEDARRAY_A = LEDARRAY_A;
	this->LEDARRAY_G = LEDARRAY_G;
	this->LEDARRAY_DI = LEDARRAY_DI;
	this->LEDARRAY_CLK = LEDARRAY_CLK;
	this->LEDARRAY_LAT = LEDARRAY_LAT;

	configure();
}


void LedMatrixObject::configure(){
	pinMode(LEDARRAY_D, OUTPUT); 
	pinMode(LEDARRAY_C, OUTPUT);
	pinMode(LEDARRAY_B, OUTPUT);
	pinMode(LEDARRAY_A, OUTPUT);
	pinMode(LEDARRAY_G, OUTPUT);
	pinMode(LEDARRAY_DI, OUTPUT);
	pinMode(LEDARRAY_CLK, OUTPUT);
	pinMode(LEDARRAY_LAT, OUTPUT);
}

void LedMatrixObject::clear(){
	for(int i = 0; i < 32; i++)
		Word1[i] = 0;
}

void LedMatrixObject::clearScene(){
	for(byte i = 0; i < 16; i++)
		for(byte k = 0; k < 16; k++)
			this->Scene[i][k] = 1;
}

void LedMatrixObject::sceneToWord(){
	//clear word
	clear();

	int i, k, key = 0;
	unsigned int value;
	for(i = 0; i < 16; i++){
		for(k = 0; k < 16; k++){
			if(i < 8){
				value = Scene[i][k] << (7 - i);
				Word1[15 - k] += value;
			} else {
				value = Scene[i][k] << (15 - i);
				Word1[31 - k] += value;
			}
		}
	}
}

void LedMatrixObject::draw(){
	sceneToWord();
	display();
	clearScene();
}

void LedMatrixObject::display(){
	unsigned char i;

	for( i = 0 ; i < 16 ; i++ )
	{
		digitalWrite(LEDARRAY_G, HIGH);		
		
		Display_Buffer[0] = Word1[i];		
		Display_Buffer[1] = Word1[i+16];

		send(Display_Buffer[1]);
		send(Display_Buffer[0]);

		digitalWrite(LEDARRAY_LAT, HIGH);					 
		delayMicroseconds(1);
	
		digitalWrite(LEDARRAY_LAT, LOW);
		delayMicroseconds(1);

		scan_Line(i);

		digitalWrite(LEDARRAY_G, LOW);
		
		delayMicroseconds(100);		
	}	
}

void LedMatrixObject::send(unsigned int dat) {
	unsigned char i;
	digitalWrite(LEDARRAY_CLK, LOW);
	delayMicroseconds(1);;	
	digitalWrite(LEDARRAY_LAT, LOW);
	delayMicroseconds(1);;

	for( i = 0 ; i < 8 ; i++ )
	{
		if( dat&0x01 )
		{
			digitalWrite(LEDARRAY_DI, HIGH);	
		}
		else
		{
			digitalWrite(LEDARRAY_DI, LOW);
		}

		delayMicroseconds(1);
		digitalWrite(LEDARRAY_CLK, HIGH);				  
			delayMicroseconds(1);
		digitalWrite(LEDARRAY_CLK, LOW);
			delayMicroseconds(1);		
		dat >>= 1;
			
	}			
}


void LedMatrixObject::scan_Line(unsigned int m) {	
	switch(m)
	{
		case 0:			
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, LOW); 					
			break;
		case 1:					
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		case 2:					
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 3:					
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		case 4:
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 5:
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		case 6:
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 7:
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		case 8:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 9:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, HIGH); 		
			break;	
		case 10:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 11:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		case 12:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 13:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		case 14:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 15:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		default : break;	
	}
}

void LedMatrixObject::setScene(unsigned char  Scene[16][16]){
	for(byte i = 0; i < 16; i++)
		for(byte k = 0; k < 16; k++)
			this->Scene[i][k] = Scene[i][k];
}

void LedMatrixObject::setLedOn(int x, int y){
	Scene[x][y] = 0;
}

void LedMatrixObject::setLedOff(int x, int y){
	Scene[x][y] = 1;
}

void LedMatrixObject::toggleLed(int x, int y){
	Scene[x][y] = !Scene[x][y];
}