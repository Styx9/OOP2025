#pragma warning(disable : 4996)
#include "Number.h"
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;
//functiile normale si constructor + destructor
Number::Number(const char* value, int base) //constructor
{
	if (base >= 2 && base <= 16)
		this->base = base;
	else {
		cout << "Eroare baza invalita";
		return;
	}
	number = new char[strlen(value) + 1];
	strcpy(number, value);
}
Number::Number(int number) //constructor pentru initializarea cu int 
{
	base = 10; //baza def pt int e 10
	char buffer[50];
	sprintf(buffer, "%d", number);
	this->number = new char[strlen(buffer) + 1];
	strcpy(this->number, buffer);
}
Number::~Number() {
	delete[] number;
}
void Number::SwitchBase(int newBase) {

	//transformarea dintr-o baza in baza 10
	char* endPtr;
	long valDecimal = strtol(number, &endPtr, base); //transformam numarul din char pointer in long si numarul este automat transformat in baza 10;
	
	char buffer[50];
	int i = 0;
	long temp = valDecimal;
	while (temp > 0)
	{
		int rest = temp % newBase;
		if (rest < 10)
			buffer[i++] = '0' + rest;
		else
			buffer[i++] = 'A' + (rest - 10); //pentru numere mai mari de baza 10
		temp /= newBase;
	}
	buffer[i]='\0';
	//trebuie sa inversam stringul deoarece apare invers
	for (int j = 0; j < i / 2; j++)
		swap(buffer[j], buffer[i - j - 1]);
	delete[] number; //il stergem si il inlocuim
	number = new char[i + 1];
	strcpy(number, buffer);
	base = newBase;
}
int Number::GetDigitsCount()
{
	return strlen(number);
}
int Number::GetBase()
{	
	return base;
}
void Number::Print() {
	cout << "The number is : ";
	for (int i = 0; i < strlen(number); i++)
		cout << number[i];
	cout << " in base: " << base << endl;
}
//operator overloading
	bool Number::operator>(Number& rhs) const
{
		if (strlen(this->number) > strlen(rhs.number))
			return true;
		else if (strlen(this->number) < strlen(rhs.number))
			return false;
	else if (strlen(this->number) == strlen(rhs.number))
	{
		for (int i = strlen(this->number); i >= 0; i--)
			if (this->number[i] - '0' < rhs.number[i] - '0')
				return false;
	}
	return true;
}
	bool Number::operator<(Number& rhs) const
	{
		if (strlen(this->number) < strlen(rhs.number))
			return true;
		else if (strlen(this->number) > strlen(rhs.number))
			return false;
		else if (strlen(this->number) == strlen(rhs.number))
		{
			for (int i = strlen(this->number); i >= 0; i--)
				if (this->number[i] - '0' > rhs.number[i] - '0')
					return false;
		}
		return true;
	}
	bool Number::operator==(Number& rhs) const
	{
		return (strcmp(number, rhs.number)==0);
	}
	Number operator+(const Number& lhs,const Number& rhs) {
		int commonBase = (lhs.base > rhs.base) ? lhs.base : rhs.base;
		char* endPtr;
		long lhsDecimal = strtol(lhs.number, &endPtr, lhs.base);
		long rhsDecimal = strtol(rhs.number, &endPtr, rhs.base);

		long sum = lhsDecimal + rhsDecimal;
		long temp = sum;
		char buffer[50];
		int i = 0;
		while (temp > 0)
		{
			int rest = temp % commonBase;
			if (rest < 10)
				buffer[i++] = '0' + rest;
			else
				buffer[i++] = 'A' + (rest - 10);
			temp /= commonBase;
		}
		for (int j = 0; j < i / 2; j++)
			swap(buffer[j], buffer[i - j - 1]);
		return Number(buffer, commonBase);
	}
	Number operator-(const Number& lhs,const  Number& rhs)
	{
		int commonBase = (lhs.base > rhs.base) ? lhs.base : rhs.base; //le-am facut const asa ca nu pot modifica bazele lor (daca nu e const nu merge scaderea)
		char* endPtr;
		long lhsDecimal = strtol(lhs.number, &endPtr, lhs.base);
		long rhsDecimal = strtol(rhs.number, &endPtr, rhs.base);

		long dif = lhsDecimal - rhsDecimal;
		if (dif < 0)
		{
			cout << "Scaderea a rezultat un numar negativ!" << endl;
			return Number("0",rhs.base); // stiu ca merge sa rezolvi si numerele negative but i dont wanna 
		}
		long temp = dif;
		char buffer[50];
		int i = 0;
		while (temp > 0)
		{
			int rest = temp % commonBase;
			if (rest < 10)
				buffer[i++] = '0' + rest;
			else
				buffer[i++] = 'A' + (rest - 10);
			temp /= commonBase;
		}
		for (int j = 0; j < i / 2; j++)
			swap(buffer[j], buffer[i - j - 1]);
		return Number(buffer, commonBase);
	}
	void Number::operator--()
	{
		for (int i = 1; i < strlen(number); i++)
		{
			number[i - 1] = number[i];
		}
		number[strlen(number) - 1] = '\0';
}
	void Number::operator--(int) {
		number[strlen(number) - 1] = '\0';
	}
	Number::Number(const Number& source):
		number{nullptr}
	{
		number = new char[strlen(source.number) + 1];
		strcpy(number, source.number);
	}
	Number::Number(Number&& source) :
		number{ source.number } {
		source.number = nullptr;
	}
	Number& Number::operator=(const Number& rhs)
	{
		if (this == &rhs) return *this; //daca vrem sa copiem un acelasi obiect doar il returnam
		delete[] number;
		base = rhs.base;
		number = new char[strlen(rhs.number) + 1];
		strcpy(number, rhs.number);
		return *this;
	}
	Number& Number::operator=(Number&& rhs) {
		if (this == &rhs) return *this;

		delete[] number;
		number = rhs.number;
		base = rhs.base;
		rhs.number = nullptr;
		return *this;
	}
	Number& Number::operator=(int value) //face din int obiect din Number ca sa il putem utiliza la calcule
	{
		*this = Number(value);
		return *this;
	}
	Number& Number::operator=(const char* value) //inlocuim valoarea din number cu o alta valoare
	{
		delete[] number;
		number = new char[strlen(value) + 1];
		strcpy(number, value);
		return *this;
	}
	char Number::operator[](int index)const {
		if (index >= 0 && index < strlen(number))
			return number[index];
		return '\0';
	}
	void Number::operator +=(Number& rhs) {
		*this = *this + rhs;
	}