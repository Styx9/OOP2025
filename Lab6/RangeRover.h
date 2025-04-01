#pragma once
#include "Car.h"
class RangeRover: public Car
{
public:
	RangeRover(); //constructor simplu toate masinile vor avea variabilele fixate
	double GetFuelCapacity() override;
	double GetFuelConsumption() override;
	double GetSpeed(Weather condition) override;
	double GetRaceTiming(double circuitLength, Weather condition);
	std::string GetName() override;
};


