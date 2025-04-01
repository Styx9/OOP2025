#pragma once
#include "Weather.h"
#include "Car.h"
#include <vector>
class Circuit
{
private:
	std::vector<Car*> cars;
	std::vector<std::pair<Car*, double>> raceResult;
	double length;
	Weather condition;
public:
	void SetLength(double length);
	void SetWeather(Weather condition);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

