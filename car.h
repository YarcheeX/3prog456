#pragma once
#include <iostream>

using namespace std;

//абстрактный класс
class car {

protected:
	string brand = "";
	string model = "";
	string color = "";

	string body_type = "";
	string engine_type = "";
	int engine_power;
	double engine_capacity;

public:
	virtual void accelerate() = 0;
	virtual void brake() = 0;
};

class truck_car : public car {

private:
	float load_capacity;

public:
	void accelerate();
	void brake();

};

class sport_car : public car {

private:
	string sport_category;

public:
	void accelerate();
	void brake();
};
