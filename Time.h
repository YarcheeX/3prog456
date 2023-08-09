#pragma once
#include <stdio.h>

class Time {

private:
	unsigned min, sec;
	int hour;
public:
	Time();
	Time(int sec);
	Time(int min, int sec);
	Time(int hour, int min, int sec);

	void set_time(int hour, int min, int sec);
	void get_time(int& hour, int& min, int& sec);
	int get_hour() const;
	int get_min() const;
	int get_sec() const;
	void print_time() const;
	const Time operator+ (const Time& a);
};