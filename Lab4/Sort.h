#pragma once
#include <vector>
#include <stdarg.h>
#include <string>
class Sort
{
    int* list;//folosim array ca lista 
    int nrelements;
    void QuickSortHelper(int low, int high, bool ascendent);
    int Partition(int low, int high, bool ascendent); //private 
public:
    Sort(int nrelements, int min, int max);
    Sort();
    Sort(std::vector<int>& vec);
    Sort(int nrelements, ...);
    Sort(const char* strg);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
