#include "Time.h"

Time::Time()
{
	hour = 0;
	min = 0;
	sec = 0;
}

Time::Time(int sec) {

	set_time(0, 0, sec);
}

Time::Time(int min, int sec) {

	set_time(0, min, sec);
}

Time::Time(int hour, int min, int sec) {

	set_time(hour, min, sec);
}

void Time::set_time(int hour, int min, int sec)
{
	if (min < 60 && sec < 60) {
		this->hour = hour;
		this->min = min;
		this->sec = sec;
	}
	else {
		this->hour = 0;
		this->min = 0;
		this->sec = 0;
	}
}

void Time::get_time(int& hour, int& min, int& sec)
{
	hour = this->hour;
	min = this->min;
	sec = this->sec;
}

int Time::get_hour() const
{
	return hour;
}

int Time::get_min() const
{
	return min;
}

int Time::get_sec() const
{
	return sec;
}

void Time::print_time() const
{
	printf("%u:%u:%d", hour, min, sec);
}

const Time Time::operator+(const Time& a)
{
	Time b;

	b.sec = this->sec + a.sec;
	b.min = this->min + a.min;
	b.hour = this->hour + a.hour;

	if (b.sec > 60) {
		b.min++;
		b.sec -= 60;
	}
	if (b.min > 60) {
		b.hour++;
		b.min -= 60;
	}

	return b;
}
