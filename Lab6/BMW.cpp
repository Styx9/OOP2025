#include "BMW.h"

BMW::BMW() //folosesc spec-urile de la un	BMW Arona
{
	fuelCapacity = 40.0; //vorbim in litri
	fuelConsumption = 12.1;
	speedSunny = 243; //viteza maxima in conditii normale
	speedRain = 209;
	speedSnow = 154;
	name = "BMW X5";
}

double BMW::GetFuelCapacity()
{
	return fuelCapacity;
}

double BMW::GetFuelConsumption()
{
	return fuelConsumption;
}

double BMW::GetSpeed(Weather condition)
{
	if (condition == Weather::Sunny)
		return speedSunny;
	if (condition == Weather::Rain)
		return speedRain;
	else return speedSnow;
}

double BMW::GetRaceTiming(double circuitLength, Weather condition)
{
	if (fuelCapacity - (fuelConsumption/100) * circuitLength <= 0)
		return 0.0;
	double time = (circuitLength / GetSpeed(condition))*60; //vreau timpul in minute
	return time;
}

std::string BMW::GetName()
{
	return name;
}

