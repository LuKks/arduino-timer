# arduino-timer
https://amxmodx-es.com/Thread-Arduino-tasks-timers-delay-sin-bloquear

Note: it's old text.

```c++
#include <Timer.h>
Timer timer;

enum { //task ids
  tMessages = 0,
  tLed,
  tAlerts,
  tInfo
}

void setup() {
	timer.second(tLed, 15); //part of example three
}

void loop() {
	//example one
	if(timer.milli(tMessages, 1000)) { //also exists timer.micro
		//executed every second
	}
	
	//example two
	//you can create timers inside loop but you have to create the timer below timer.is, otherwise timer.is never executed
	//because the functions to create timers works like timer.is too (showed above with tMessages), check out:
	if(timer.is(tAlerts)) {
		//executed every second too
	}

	timer.second(tAlerts, 1);

	//note: in the first check of the example one will be executed and after every second (test for more understand)

	//example three
	if(timer.exists(tLed) && digitalRead(6)) { //imagine that pin six it's a button
		timer.remove(tLed); //also you can remove without check exists, just to show more functions
	}

	if(timer.is(tLed)) { //executed one time after 15 seconds (if you didn't press the button)
		digitalWrite(13, HIGH);
	}

	return; //the code below will not executed but it's just for show it

	//example four (utility)
	//these functions not check if the task expired, only calculate the time left. Just use for informative purposes:
	timer.leftSeconds(tLed); //int
	timer.leftMillis(tLed); //int

	timer.fLeftSeconds(tLed); //float
	timer.fLeftMillis(tLed); //float

	timer.leftMicros(tLed); //int

	//important difference on use, check this out:

	/*on setup:*/ timer.second(tLed, 15);
	/*on loop:*/ if(timer.leftSeconds(tLed) == 10) { }

	/*seems the if will be execute after 5 seconds but not, will do after 4 seconds.
	on another words: seems the if will be executed when the seconds left are 10 but not, will do when are 11.
	because when the seconds left are 10.999 (and later 10.998) this always return 10 (always return an integer, not rounded)
	to solve that, we can use fLeftSeconds:*/
	/*on loop:*/ if(timer.fLeftSeconds(tLed) == 10.0) { }

	//you should read this before use floats: https://www.arduino.cc/reference/en/language/variables/data-types/float/*/
}
```
