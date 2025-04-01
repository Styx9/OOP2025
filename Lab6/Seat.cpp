#include "Seat.h"

Seat::Seat() //folosesc spec-urile de la un	Seat Arona
{
	fuelCapacity = 20.0; //vorbim in litri
	fuelConsumption = 5.7;
	speedSunny = 193; //viteza maxima in conditii normale
	speedRain = 155; 
	speedSnow = 134;
	name = "Seat Arona";
}

double Seat::GetFuelCapacity()
{
	return fuelCapacity;
}

double Seat::GetFuelConsumption()
{
	return fuelConsumption;
}

double Seat::GetSpeed(Weather condition)
{
	if (condition == Weather::Sunny)
		return speedSunny;
	if (condition == Weather::Rain)
		return speedRain;
	else return speedSnow;
}
double Seat::GetRaceTiming(double circuitLength, Weather condition)
{
	if (fuelCapacity - (fuelConsumption / 100) * circuitLength <= 0)
		return 0.0;
	double time = (circuitLength / GetSpeed(condition)) * 60; //vreau timpul in minute
	return time;
}

std::string Seat::GetName()
{
	return name;
}

