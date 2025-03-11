#include "Canvas.h";
#include <iostream>
using namespace std;


int main()
{
	Canvas canvas(50, 30); //intializam matricea de lungime height si latime width

	//dreptunghi
	canvas.DrawRect(2, 2, 10, 6, '#');
	canvas.Print();
	cout << endl;
	canvas.Clear();
	//umplem dreptunghi
	canvas.FillRect(12, 2, 20, 6, '#');
	canvas.Print();
	cout << endl;
	canvas.Clear();

	//cerc
	canvas.DrawCircle(15, 10, 5, '@');
	canvas.Print();
	cout << endl;
	canvas.Clear();
	//umplem cerc
	canvas.FillCircle(25, 10, 3, '@');
	canvas.Print();
	cout << endl;
	canvas.Clear();

	//desenam linie
	canvas.DrawLine(0, 0, 5, 5 , '*');
	canvas.Print();
	cout << endl;

	canvas.Clear();
	canvas.Print();
	return 0;
}