#pragma once
#include <iomanip>
#include <iostream>

using namespace std;

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
	void get_time(int& hour, int& min, int& sec) const;
	int get_hour() const;
	int get_min() const;
	int get_sec() const;
	void print_time() const;
	const Time operator+ (const Time& a);

	friend ostream& operator<<(ostream& os, const Time& t);
};