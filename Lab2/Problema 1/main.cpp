#include "NumberList.h"
#include <iostream>

int main()
{
	NumberList list;
	list.Init();
	list.Add(23);
	list.Add(12);
	list.Add(29);
	list.Add(11);
	list.Add(8);
	list.Add(67);
	list.Add(32);
	list.Sort();
	std::cout << "Vectorul dupa sortare:";
	list.Print();

}