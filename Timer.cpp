#include "Timer.h"
#include "Arduino.h"

Timer::Timer() {}

bool Timer::micro(int i, unsigned long ms) {
	expired = Timer::check_expired(i);

	//cleared or expired
	if(tasks[i][1] < 2) {
		tasks[i][0] = micros(); //start
		tasks[i][1] = ms + 2; //time + state
	}
	
	return expired;
}

bool Timer::is(int i) {
	return Timer::check_expired(i) ? Timer::clear(i) : false;
}

bool Timer::check_expired(int i) {
	//(exists && micros() - start >= ms)
	if(tasks[i][1] >= 2 && micros() - tasks[i][0] >= tasks[i][1] - 2) {
		tasks[i][1] = 1; //expire
		return true;
	}
	
	return false;
}

bool Timer::exists(int i) {
	return tasks[i][1] >= 2;
}

bool Timer::clear(int i) {
	tasks[i][1] = 0;
	return true;
}

long Timer::leftMicros(int i) {
	return tasks[i][1] <= 2 ? 0 : (tasks[i][1] - (micros() - tasks[i][0]));
}

//helpers
bool Timer::set(int i, unsigned long millis) { return Timer::micro(i, millis * 1000); }
bool Timer::seconds(int i, unsigned long secs) { return Timer::micro(i, secs * 1000000); }

float Timer::leftMillis(int i) { return Timer::leftMicros(i) / 1000; }
float Timer::leftSeconds(int i) { return Timer::leftMicros(i) / 1000000; }
