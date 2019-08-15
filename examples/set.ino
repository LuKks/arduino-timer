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
}

void loop() {
  if(Timer.seconds(tMessage, 1)) {
    Serial.println("every 1s (message)");
  }
  
  if(Timer.set(tLed, 1000)) { //millis
    Serial.println("every 1s (led)");
  }

  if(Timer.micro(tUpdate, 1000000)) {
    Serial.println("every 1s (update)");
  }
}
