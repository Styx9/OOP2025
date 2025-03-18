#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
	//primul constructor
	Sort s1(5, 10, 50);
	s1.Print();
	s1.BubbleSort();
	cout << "Dupa sortare: ";
	s1.Print();
	cout << endl;

	//al doilea constructor
	Sort s2;
	s2.Print();
	s2.InsertSort(true);
	cout << "Dupa sortare: ";
	s2.Print();
	cout << endl;

	//al treilea constructor
	vector<int> vec = { 42,17,99,3,88,21 };
	Sort s3(vec);
	s3.Print();
	s3.QuickSort(false);
	cout << "Dupa sortare: ";
	s3.Print();
	cout << endl;

	//al patrulea constructor
	Sort s4(6, 5, 12, 34, 1, 9, 22);
	s4.Print();
	s4.BubbleSort(false);
	cout << "Dupa sortare: ";
	s4.Print();
	cout << endl;

	//al cincilea constructor
	Sort s5("14,76,33,89,22");
	s5.Print();
	s5.InsertSort(true);
	cout << "Dupa sortare: ";
	s5.Print();
	cout << endl;

	//celelalte functii
	cout << "Numarul de elemente din s1: " << s1.GetElementsCount() << endl;
	cout << "Elementul de la indexul 4 in s4: " << s4.GetElementFromIndex(4) << endl;

}