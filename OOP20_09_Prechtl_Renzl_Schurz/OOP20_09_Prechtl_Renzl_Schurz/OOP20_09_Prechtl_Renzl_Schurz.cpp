#include <iostream>
#include <string.h>
#include "NSys.h"
#include "NSys.cpp"
#include "NSysexception.h"
#include "NSysexception.cpp"

int main()
{
    NSys A(11,"A123");
    NSys B(10, "123");
    std::cout << A.Base<<std::endl;

    int one = pow(10, 2) * 1;
    int test=B.tointeger();

    std::cout << test << std::endl;
}