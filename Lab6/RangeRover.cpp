#include "RangeRover.h"

RangeRover::RangeRover() //folosesc spec-urile de la un	RangeRover Arona
{
	fuelCapacity = 31.1; //vorbim in litri
	fuelConsumption = 12.82;
	speedSunny = 213; //viteza maxima in conditii normale
	speedRain = 200;
	speedSnow = 181;
	name = "Range Rover Evoque";
}

double RangeRover::GetFuelCapacity()
{
	return fuelCapacity;
}

double RangeRover::GetFuelConsumption()
{
	return fuelConsumption;
}

double RangeRover::GetSpeed(Weather condition)
{
	if (condition == Weather::Sunny)
		return speedSunny;
	if (condition == Weather::Rain)
		return speedRain;
	else return speedSnow;
}
double RangeRover::GetRaceTiming(double circuitLength, Weather condition)
{
	if (fuelCapacity - (fuelConsumption / 100) * circuitLength <= 0)
		return 0.0;
	double time = (circuitLength / GetSpeed(condition)) * 60; //vreau timpul in minute
	return time;
}

std::string RangeRover::GetName()
{
	return name;
}

