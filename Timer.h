#ifndef Timer_h
#define Timer_h

class Timer
{
	public:
		Timer();

		bool second(int i, unsigned long secs);
		bool milli(int i, unsigned long ms);
		bool micro(int i, unsigned long ms);

		bool is(int i);
		bool check(int i);
		bool exists(int i);
		bool remove(int i);

		float leftSeconds(int i);
		float leftMillis(int i);
		long leftMicros(int i);
		
	private:
		unsigned long _tasks[16][2];
};

#endif
