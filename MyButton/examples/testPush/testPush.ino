#include <MyButton.h>

#define PIN_BUTTON          2


// MyButton object. Note: I have an NormallyClosed button, so I wired it from ground and pin 2, 
// and then INPUT_PULLUP is needed

MyButton  btn(PIN_BUTTON, INPUT_PULLUP); 

void setup() {
  // we'll use the led builtin
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

  Serial.begin(9600);
  Serial.println("Blinking Led");

  // set long delay (defaults at 2000 msec)
  btn.setLongPushDelay(2500);
  // set push delay (defaults at 80 msec)
  btn.setPushDelay(60);
}

void loop() {
  // every loop I read the button
  btn.read();
  if (btn.wasPushed()==true) {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on 
    delay(500);                        // wait for half a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off 
  } else if (btn.wasLongPushed()==true) {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on 
    delay(2000);                       // wait for two seconds
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off 
  } else if (btn.isPushed()==true) {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on 
    delay(50);                        // wait for 50 milliseconds only
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off 
  }
  delay(50);
}
