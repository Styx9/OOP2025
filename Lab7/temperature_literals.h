#pragma once
float operator""_Kelvin(long double value)
{
	return value - 273.15;
}
float operator""_Fahrenheit(long double value)
{
	return (value - 32) * (5.0 / 9.0);
}