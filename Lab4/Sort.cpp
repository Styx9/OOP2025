#include "Sort.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
Sort::Sort(int nrelements, int min, int max) {
    this->nrelements = nrelements;
    list = new int[nrelements];
    for (int i = 0; i < nrelements; i++)
        list[i] = min + (std::rand() % (max - min + 1)); //adaugam la min un numar dintre nr de numere dintre max si min 
}
Sort::Sort() {
    vector<int> defaultVec = { 34, 56, 76, 23, 111, 32, 45 }; //<-intrebat despre implementare
    nrelements = defaultVec.size();
    list = new int[nrelements];
    for (int i = 0; i < nrelements; i++)
        list[i] = defaultVec[i];
}
Sort::Sort(std::vector<int>&vec)
{
    nrelements = vec.size();
    list = new int[nrelements];
    for (int i = 0; i < nrelements; i++)
        list[i] = vec[i];
}
Sort::Sort(int nrelements, ...) {
    this->nrelements = nrelements;
    list = new int[nrelements];
    va_list vl;
    va_start(vl, nrelements);
    for (int i = 0; i < nrelements; i++)
        list[i] = va_arg(vl, int);
    va_end(vl);
}
Sort::Sort(const char* strg) {
    vector<int> temp;
    stringstream ss(strg);
    string num;

    while (getline(ss, num, ',')) {
        temp.push_back(stoi(num));
    }

    nrelements = temp.size();
    list = new int[nrelements];
    for (int i = 0; i < nrelements; i++)
        list[i] = temp[i];
}
void Sort::InsertSort(bool ascendent) {
    int i, key, j;
    for (i = 1; i < nrelements; i++) {
        key = list[i];
        j = i - 1;
        while (j >= 0 && ((ascendent && list[j] > key) || (!ascendent && list[j] < key))) {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
}
void Sort::QuickSort(bool ascendent)
{
    QuickSortHelper(0, nrelements - 1, ascendent);
}
void Sort::QuickSortHelper(int low, int high, bool ascendent)
{
    if (low < high)
    {
        int m = Partition(low, high, ascendent);
        QuickSortHelper(low,m - 1, ascendent);
        QuickSortHelper(m + 1, high, ascendent);
    }
}
int Sort::Partition(int low, int high, bool ascendent)
{
    int pivot = list[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if ((ascendent && list[j] < pivot) || (!ascendent && list[j] > pivot)) {
            i++;
            swap(list[i], list[j]);
        }
    }
    swap(list[i + 1], list[high]);
    return i + 1;
}
void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < nrelements - 1; i++) {
        for (int j = 0; j < nrelements - i - 1; j++) {
            if ((ascendent && list[j] > list[j + 1]) || (!ascendent && list[j] < list[j + 1])) {
                swap(list[j], list[j + 1]);
            }
        }
    }
}
void Sort::Print() {
    for (int i = 0; i < nrelements; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
int Sort::GetElementsCount()
{
    return nrelements;
}
int Sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index < nrelements)
        return list[index];
    else return 1;
}