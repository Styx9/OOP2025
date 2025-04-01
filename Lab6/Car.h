#pragma once
#include "Weather.h"
#include <string>
class Car
{
protected:
	std::string name;
	double fuelCapacity;
	double fuelConsumption;
	double speedSunny;
	double speedRain;
	double speedSnow;
public:
	virtual double GetFuelCapacity() = 0;
	virtual double GetFuelConsumption() = 0;
	virtual double GetSpeed(Weather condition) = 0;
	virtual std::string GetName() = 0;
	virtual double GetRaceTiming(double circuitLength, Weather condition) = 0;
	virtual ~Car() {}
};

