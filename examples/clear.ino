#include <Timer.h>
Timer Timer;

enum {
  tMessage = 0,
  tLed
};

void setup() {
  Serial.begin(9600);
  Serial.println("init");

  Timer.seconds(tLed, 10);
}

void loop() {
  //suppose pin six with a button
  if(digitalRead(6)) {
    Timer.clear(tLed);
  }

  //if you didn't press the button,
  //executed once after 15s
  if(Timer.is(tLed)) {
    Serial.println("led high");
    digitalWrite(13, HIGH);
  }
}
