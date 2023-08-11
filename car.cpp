#include "car.h"

void truck_car::accelerate()
{
	cout << "Грузовик едет.\n";
}

void truck_car::brake()
{
	cout << "Грузовик затормозил.\n";
}

void sport_car::accelerate()
{
	cout << "Спортивный автомобиль нереально гонит.\n";
}

void sport_car::brake()
{
	cout << "Спортивный автомобиль нереально круто тормозит.\n";
}
