#include <Timer.h>
Timer Timer;

enum {
  tMessage = 0
};

void setup() {
  Serial.begin(9600);
  Serial.println("init");
}

void loop() {
  if(Timer.is(tMessage)) {
    Serial.println("after 1s of pressed");
  }

  //suppose pin six with a button
  //keep it pressed or just once
  if(digitalRead(6)) {
    Timer.set(tMessage, 1000);
  }
}
