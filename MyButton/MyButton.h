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
    MyButton(uint8_t);						// #Pin
	MyButton(uint8_t,uint8_t);				// #Pin, INPUT_TYPE
	MyButton(uint8_t,uint8_t,uint8_t);		// #Pin, INPUT_TYPE, msec long pushed
    bool isLongPushed();
    bool isPushed();
    void    read();
  private:
    int           _pin;
    bool       _isPushed;
    bool       _isLongPushed;
    bool       _waitForLongPush;
    int           _buttonState;             // the current reading from the input pin
    int           _lastButtonState;   // the previous reading from the input pin
    unsigned long _lastDebounceTime;  // the last time the output pin was toggled
    unsigned long _debounceDelay;    // the debounce time; increase if the output flickers
    unsigned long _longDelay;
    unsigned long _lastLongPushTime;
};

#endif
