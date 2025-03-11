#include "Math.h"
#include <iostream>
using namespace std;


int main()
{
    cout << "Add(2, 3) = " << Math::Add(2, 3) << endl;
    cout << "Add(2, 3, 4) = " << Math::Add(2, 3, 4) << endl;

    cout << "Add(2.5, 3.5) = " << Math::Add(2.5, 3.5) << endl;
    cout << "Add(2.5, 3.5, 4.5) = " << Math::Add(2.5, 3.5, 4.5) << endl;

    cout << "Mul(2, 3) = " << Math::Mul(2, 3) << endl;
    cout << "Mul(2, 3, 4) = " << Math::Mul(2, 3, 4) << endl;

    cout << "Mul(1.5, 2.5) = " << Math::Mul(1.5, 2.5) << endl;
    cout << "Mul(1.5, 2.5, 3.5) = " << Math::Mul(1.5, 2.5, 3.5) << endl;

    cout << "Add(5 numbers: 1, 2, 3, 4, 5) = " << Math::Add(5, 1, 2, 3, 4, 5) << endl;

    const char* str1 = "Hello, ";
    const char* str2 = "world!";

    char* concatenated = Math::Add(str1, str2);
    if (concatenated) {
        cout << "String Add: " << concatenated << endl;
        delete[] concatenated; 
    }
    else {
        cout << "String Add returned nullptr" << endl;
    }

    return 0;
}
