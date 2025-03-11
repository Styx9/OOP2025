#include "Math.h"
#include <iostream>
using namespace std;


int main()
{
    cout << "Add(2, 3) = " << Math::Add(2, 3) << std::endl;
    cout << "Add(2, 3, 4) = " << Math::Add(2, 3, 4) << std::endl;

    cout << "Add(2.5, 3.5) = " << Math::Add(2.5, 3.5) << std::endl;
    cout << "Add(2.5, 3.5, 4.5) = " << Math::Add(2.5, 3.5, 4.5) << std::endl;

    cout << "Mul(2, 3) = " << Math::Mul(2, 3) << std::endl;
    cout << "Mul(2, 3, 4) = " << Math::Mul(2, 3, 4) << std::endl;

    cout << "Mul(1.5, 2.5) = " << Math::Mul(1.5, 2.5) << std::endl;
    cout << "Mul(1.5, 2.5, 3.5) = " << Math::Mul(1.5, 2.5, 3.5) << std::endl;

    cout << "Add(5 numbers: 1, 2, 3, 4, 5) = " << Math::Add(5, 1, 2, 3, 4, 5) << std::endl;

    const char* str1 = "Hello, ";
    const char* str2 = "world!";

    char* concatenated = Math::Add(str1, str2);
    if (concatenated) {
        std::cout << "String Add: " << concatenated << std::endl;
        delete[] concatenated; // Free allocated memory
    }
    else {
        std::cout << "String Add returned nullptr" << std::endl;
    }

    return 0;
}