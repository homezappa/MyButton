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
  _lastButtonState = LOW;
  _buttonState = LOW;
  _lastDebounceTime = 0;
  _debounceDelay = 50;
}

MyButton::MyButton(uint8_t pin, uint8_t mode)
{
  pinMode(pin, mode);
  _pin = pin;
  _longDelay = (unsigned long) 2000;
  _lastButtonState = LOW;
  _buttonState = LOW;
  _lastDebounceTime = 0;
  _debounceDelay = 50;
}

MyButton::MyButton(uint8_t pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _longDelay = 2000;
  _lastButtonState = LOW;
  _buttonState = LOW;
  _lastDebounceTime = 0;
  _debounceDelay = 50;
}

void MyButton::read()
{
  int reading = digitalRead(_pin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
//  if (reading != _lastButtonState) {
//    // reset the debouncing timer
//    _lastDebounceTime = millis();
//  }

//  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != _buttonState) {
      //what is the new state ?
        if (reading == HIGH) {
            _isPushed = true;
            // was low, now high, start timing for long Push
            _waitForLongPush = true;
            _lastLongPushTime = millis();
        } else {
            _isPushed = false;
            _waitForLongPush = false;
            _isLongPushed = false;
        }
        _buttonState = reading;
    }
    else {
        if (reading == HIGH) {
            _isPushed = true;
            if (_waitForLongPush == true) {
                if ((millis() - _lastLongPushTime) > _longDelay) {
                    _isLongPushed = true;
                    _waitForLongPush = false;
                }
            }
        } else {
            _isPushed = false;
            _waitForLongPush = false;
            _isLongPushed = false;
        }
    }
//  }
}

bool MyButton::isPushed() {
    return _isPushed;
}

bool MyButton::isLongPushed() {
    return _isLongPushed;
}
