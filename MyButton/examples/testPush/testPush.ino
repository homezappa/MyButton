#include <MyButton.h>

#define PIN_BUTTON          2


// MyButton object. Note: I have an NormallyClosed button, so I wired it from ground and pin 2, 
// and then INPUT_PULLUP is needed

MyButton  btn; 

void setup() {
  Serial.begin(9600);
  Serial.println("Test Push");
  
  btn.begin(PIN_BUTTON, INPUT_PULLUP); 	

// set long delay (defaults at 2000 msec)
  btn.setLongPushDelay(3000);
  // set push delay (defaults at 80 msec)
  btn.setPushDelay(100);
}

void loop() {
  // every loop I read the button
  btn.read();
  if (btn.wasLongPushed()==true) {
    Serial.println("WAS Long Pushed");
  } 
  if (btn.wasPushed()==true) {
    Serial.println("WAS Pushed");
  } 
  if (btn.isPushed()==true) {
    Serial.println("IS Pushed");
  }
  delay(5);
}
