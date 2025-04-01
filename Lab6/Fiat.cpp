#include "Fiat.h"

Fiat::Fiat() //folosesc spec-urile de la un	Fiat Arona
{
	fuelCapacity = 23.0; //vorbim in litri
	fuelConsumption = 8.7;
	speedSunny = 208; //viteza maxima in conditii normale
	speedRain = 170;
	speedSnow = 151;
	name = "Fiat 500";
}

double Fiat::GetFuelCapacity()
{
	return fuelCapacity;
}

double Fiat::GetFuelConsumption()
{
	return fuelConsumption;
}

double Fiat::GetSpeed(Weather condition)
{
	if (condition == Weather::Sunny)
		return speedSunny;
	if (condition == Weather::Rain)
		return speedRain;
	else return speedSnow;
}
double Fiat::GetRaceTiming(double circuitLength, Weather condition)
{
	if (fuelCapacity - (fuelConsumption / 100) * circuitLength <= 0)
		return 0.0;
	double time = (circuitLength / GetSpeed(condition)) * 60; //vreau timpul in minute
	return time;
}

std::string Fiat::GetName()
{
	return name;
}

