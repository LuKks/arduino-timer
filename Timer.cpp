#include "Timer.h"
#include "Arduino.h"

Timer::Timer() {

}

bool Timer::second(int i, unsigned long secs) {
	return micro(i, secs * 1000000);
}

bool Timer::milli(int i, unsigned long ms) {
	return micro(i, ms * 1000);
}

bool Timer::micro(int i, unsigned long ms) {
	check(i); //check expired

	if(_tasks[i][1] > 2) {
		return false; //if there is time yet, false
	}

	_tasks[i][0] = micros(); //start
	_tasks[i][1] = ms + 2; //ms + state
	return true;
}

bool Timer::is(int i) {
	check(i); //check expired

	if(_tasks[i][1] != 1) {
		return false; //if not expired, false
	}

	_tasks[i][1] = 0; //set used
	return true;
}

bool Timer::check(int i) {
	//(not used && micros() - start >= ms)
	if(_tasks[i][1] >= 2 && micros() - _tasks[i][0] >= _tasks[i][1] - 2) {
		_tasks[i][1] = 1; //set expired
		return true;
	}
	
	return false;
}

bool Timer::exists(int i) {
	return _tasks[i][1] >= 2;
}

bool Timer::remove(int i) {
	_tasks[i][1] = 0;
	return true;
}

float Timer::leftSeconds(int i) {
	return leftMicros(i) / 1000000;
}

float Timer::leftMillis(int i) {
	return leftMicros(i) / 1000;
}

long Timer::leftMicros(int i) {
	return _tasks[i][1] <= 2 ? 0 : micros() - _tasks[i][0];
} 
