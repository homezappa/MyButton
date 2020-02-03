/*
  MyButton.h - Library for buttons.
  Created by Andrea Zappaterra, 11 January 2020.
  Released into the public domain.
*/
#ifndef MyButton_h
#define MyButton_h

#include "Arduino.h"

class MyButton
{
  public:
    //pass a reference to a Print object
    MyButton();
    void begin(uint8_t);						// #Pin
	void begin(uint8_t,uint8_t);				// #Pin, INPUT_TYPE
	void begin(uint8_t,uint8_t,uint8_t);		// #Pin, INPUT_TYPE, msec long pushed
    bool isPushed();
	bool wasPushed();
	bool wasLongPushed();
	void setPushDelay(uint8_t);
	void setLongPushDelay(uint8_t);
    void read();							// You HAVE to call this at the beginning of loop()
  private:
	bool			_debug = false;
    int        		_pin;
    bool       		_isPushed;
    bool       	 	_wasPushed;
    bool       	  	_wasLongPushed;
    int           	_lastButtonState;   	// the previous reading from the input pin
    unsigned long 	_RaiseTime;  			// the time the output pin was HIGH from LOW
    unsigned long 	_FallTime;  			// the time the output pin was LOW from HIGH
    unsigned long 	_pushDelay;    		// the time at least the pin was HIGH to trigger WasPushed
    unsigned long 	_longDelay;    		// the time at least the pin was HIGH to trigger WasLongPushed
};

#endif
