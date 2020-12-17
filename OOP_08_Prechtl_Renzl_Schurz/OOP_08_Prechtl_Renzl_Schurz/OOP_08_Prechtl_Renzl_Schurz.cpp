// OOP_08_Prechtl_Renzl_Schurz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "complex.h"
#include "complex.cpp"

int main()
{
    Complex A(1,2);
    Complex B(4,5);

    std::cout << "Hello World!\n";

    Complex C = A + B;
}

