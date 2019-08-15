# arduino-timer

Timers without blocking [in 50 lines](https://github.com/LuKks/arduino-timer/Timer.cpp) for Arduino.

![](https://img.shields.io/maintenance/yes/2019.svg?style=flat-square) ![](https://img.shields.io/github/size/LuKks/arduino-timer/Timer.cpp.svg) ![](https://img.shields.io/github/license/LuKks/arduino-timer.svg)

###### examples/set.ino
```c++
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
```

## Install
[Download ZIP](https://github.com/LuKks/arduino-timer/archive/master.zip)\
In Arduino IDE go to: Sketch -> Include Library -> Add .ZIP library

## Description
Native `delay(ms)` is normally useless, specially for multi timing.\
`Timer` gives control with `set`, `is`, `clear`, `exists` and `left*`.\
Precision at microseconds.\
Aware of overflow.

## License
Code released under the [MIT License](https://github.com/LuKks/arduino-timer/blob/master/LICENSE).
