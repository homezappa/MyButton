/*
  Test program for library MyButton.
  Created by Andrea Zappaterra, 18 February 2020.
  Released into the public domain.
*/


#include <MyButton.h>

#define PIN_BUTTON          2


// MyButton object. Note: I have an NormallyClosed button, so I wired it from ground and pin 2, 
// and then INPUT_PULLUP is needed

// Creation of MyButton object
MyButton  btn; 

void setup() {
  Serial.begin(9600);
  Serial.println("Test Push");
// Initialization of MyButton object
// Note: I have an NormallyClosed button, so I wired it from ground and pin 2, 
// and then INPUT_PULLUP is needed as mode parameter
// Inizializzazione dell'oggetto MyButton  
// Nota: Ho un pulsante normalmente chiuso, così lo ho collegato fra il pin 2
// e GND, quindi devo inizializzare il mode a INPUT_PULLUP
  btn.begin(PIN_BUTTON, INPUT_PULLUP); 	

// set long delay (defaults at 2000 msec)
// Configuro il ritardo per la "è stato premuto a lungo" a 3000msec (il default è 2000msec)
  btn.setLongPushDelay(3000);
// set push delay (defaults at 80 msec)
// Configuro il ritardo per la "è stato premuto" a 100msec (il default è 80msec)
  btn.setPushDelay(100);
}

void loop() {
// every loop I read the button
// ogni loop occorre eseguire la read()
  btn.read();

// The button was long pushed? (note: calling this resets the state, so, warning)
// Il pulsante è stato premuto a lungo? (nota: chiamando questa funzione lo stato si resetta, quindi occhio
// a non richiamarla dopo, perchè si otterrebbe sempre false
  if (btn.wasLongPushed()==true) {
    Serial.println("WAS Long Pushed");
  } 
// The button was pushed? (note: calling this resets the state, so, warning)
// Il pulsante è stato premuto? (nota: chiamando questa funzione lo stato si resetta, quindi occhio
// a non richiamarla dopo, perchè si otterrebbe sempre false
  if (btn.wasPushed()==true) {
    Serial.println("WAS Pushed");
  } 
// The button IS pushed now? (note: calling this resets the state, so, warning)
// Il pulsante è premuto adesso? (nota: chiamando questa funzione lo stato si resetta, quindi occhio
// a non richiamarla dopo, perchè si otterrebbe sempre false
  if (btn.isPushed()==true) {
    Serial.println("IS Pushed");
  }
  delay(5); // delay of only 5 msec, only for settlement
}
