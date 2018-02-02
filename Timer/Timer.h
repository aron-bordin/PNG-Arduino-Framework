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


#include "stdlib.h"
#include "Arduino.h"

#ifndef TIMER_H
#define TIMER_H
typedef void (*CallBackType)();


class Timer{
private:
	void Create(unsigned long int ms, CallBackType callback, bool isSingle);
	unsigned long int msInterval;
	bool blEnabled;
	bool blSingleShot;
	CallBackType onRun;
	bool Tick();
	unsigned long LastTime;
	unsigned long DiffTime;//used when I pause the Timer and need to resume

public:
	Timer(unsigned long int ms);
	Timer(unsigned long int ms, CallBackType callback);
	Timer(unsigned long int ms, CallBackType callback, bool isSingle);
	~Timer();

	void setInterval(unsigned long int ms);
	void setEnabled(bool Enabled);
	void setSingleShot(bool isSingle);
	void setOnTimer(CallBackType callback);
	void Start();
	void Resume();
	void Pause();
	void Stop();
	void Update();


	unsigned long int getInterval();
	unsigned long int getCurrentTime();
	unsigned long int getRemaining();
	CallBackType getOnTimerCallback();

	bool isEnabled();
	bool isSingleShot();

};


#endif // TIMER_H
