#ifndef Timer_h
#define Timer_h

class Timer
{
	public:
		Timer();

		bool micro(int i, unsigned long ms);
		bool set(int i, unsigned long millis);
		bool seconds(int i, unsigned long secs);

		bool is(int i);
		bool exists(int i);
		bool clear(int i);

		long leftMicros(int i);
		float leftMillis(int i);
		float leftSeconds(int i);
		
	private:
		bool check_expired(int i);
		bool expired;
		
		unsigned long tasks[16][2];
};

#endif
