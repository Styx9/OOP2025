#pragma once
#include "Car.h"
class Fiat: public Car
{
public:
	Fiat(); //constructor simplu toate masinile vor avea variabilele fixate
	double GetFuelCapacity() override;
	double GetFuelConsumption() override;
	double GetSpeed(Weather condition) override;
	double  GetRaceTiming(double circuitLength, Weather condition) override;
	std::string GetName() override;
};

