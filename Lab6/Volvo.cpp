#include "Volvo.h"

Volvo::Volvo() 
{
	fuelCapacity =40; //vorbim in litri
	fuelConsumption = 11.2;
	speedSunny = 180; //viteza maxima in conditii normale
	speedRain = 159;
	speedSnow = 121;
	name = "Volvo XC60";
}

double Volvo::GetFuelCapacity()
{
	return fuelCapacity;
}

double Volvo::GetFuelConsumption()
{
	return fuelConsumption;
}

double Volvo::GetSpeed(Weather condition)
{
	if (condition == Weather::Sunny)
		return speedSunny;
	if (condition == Weather::Rain)
		return speedRain;
	else return speedSnow;
}
double Volvo::GetRaceTiming(double circuitLength, Weather condition)
{
	if (fuelCapacity - (fuelConsumption / 100) * circuitLength <= 0)
		return 0.0;
	double time = (circuitLength / GetSpeed(condition)) * 60; //vreau timpul in minute
	return time;
}
std::string Volvo::GetName()
{
	return name;
}

