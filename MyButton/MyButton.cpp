/*
  MyButton.h - Library for buttons.
  Created by Andrea Zappaterra, 11 January 2020.
  Released into the public domain.
*/

#include "Arduino.h"
#include "MyButton.h"

MyButton::MyButton(uint8_t pin, uint8_t mode, uint8_t longDelay)
{
  pinMode(pin, mode);
  _pin = pin;
  _longDelay = (unsigned long) longDelay;
  _pushDelay = (unsigned long) 80;
  _lastButtonState = digitalRead(_pin);
}

MyButton::MyButton(uint8_t pin, uint8_t mode)
{
  pinMode(pin, mode);
  _pin = pin;
  _longDelay = (unsigned long) 2000;
  _pushDelay = (unsigned long) 80;
  _lastButtonState = digitalRead(_pin);
}

MyButton::MyButton(uint8_t pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _longDelay = 2000;
  _pushDelay = (unsigned long) 80;
  _lastButtonState = digitalRead(_pin);
}

void MyButton::setPushDelay(uint8_t t) {
	_pushDelay = (unsigned long) t;
}

void MyButton::setLongPushDelay(uint8_t t) {
	_longDelay = (unsigned long) t;
}

void MyButton::read()
{
  int reading = digitalRead(_pin);

    if (reading != _lastButtonState) {
      //what is the new state ?
        if (reading == HIGH) { 	
            _isPushed = true;
			_wasPushed = false;
			_wasLongPushed = false;
            // was low, now high, start timing for normal and long wasSomething
            _RaiseTime = millis();
        } else {
            // was High, now Low, check timing for normal and long wasSomething
            _isPushed = false;
			_FallTime = millis();
			if (( _FallTime - _RaiseTime) > _longDelay ) {
				_wasLongPushed = true;
			} else if (( _FallTime - _RaiseTime) > _pushDelay ){
				_wasPushed = true;
			} else {
				_wasLongPushed = false;
				_wasPushed = false;
			}	
        }
        _lastButtonState = reading;
    }
}

bool MyButton::isPushed() {
    return _isPushed;
}

bool MyButton::wasPushed() {
    return _wasPushed;
}

bool MyButton::wasLongPushed() {
    return _wasLongPushed;
}
