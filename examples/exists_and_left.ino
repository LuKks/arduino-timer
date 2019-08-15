#include <Timer.h>
Timer Timer;

enum {
  tMessage = 0,
  tLed,
  tUpdate
};

void setup() {
  Serial.begin(9600);
  Serial.println("init");

  Timer.seconds(tLed, 10);
}

void loop() {
  //show info while tLed is pending
  if(Timer.exists(tLed)) {
    Serial.println(Timer.leftMillis(tLed));
  }

  if(Timer.is(tLed)) {
    Serial.println("led high");
    digitalWrite(13, HIGH);
  }
}
