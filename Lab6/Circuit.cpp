#include "Circuit.h"
#include "Car.h"
#include <iostream>

void Circuit::SetLength(double length)
{
	this->length = length;
}

void Circuit::SetWeather(Weather condition)
{
	this->condition = condition;
}

void Circuit::AddCar(Car* car)
{
	cars.push_back(car);
}

void Circuit::Race()
{
	raceResult.clear();
	for (Car* i : cars)
	{
		double time = i->GetRaceTiming(length, condition);
		raceResult.push_back({ i,time });
	}
}

void Circuit::ShowFinalRanks()
{
	for (size_t i = 0; i < raceResult.size();i++)
	{
		for (size_t j = 0; j < raceResult.size()-1; j++)
			if (raceResult[j+1].second < raceResult[j].second)
				swap(raceResult[j], raceResult[j+1]);
	}
	for (size_t i = 0; i < raceResult.size(); i++)
		if(raceResult[i].second>0.0)
			std::cout << "Numele masinii: " << raceResult[i].first->GetName() << " timpul: " << raceResult[i].second << std::endl;
}

void Circuit::ShowWhoDidNotFinish()
{
	for (size_t i = 0; i < raceResult.size(); i++)
		if (raceResult[i].second == 0.0)
			std::cout << "Numele masinii: " << raceResult[i].first->GetName() << " nu  a terminat cursa " << std::endl;
}



