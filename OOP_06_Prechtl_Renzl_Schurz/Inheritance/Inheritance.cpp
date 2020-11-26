#include "triangle.h"
#include <iostream>

void Triangle::WhoAmI()
{
    std::cout << "I am a triangle" << std::endl;
}

void Isosceles::WhoAmI()
{
    std::cout << "I am an isoceles triangle" << std::endl;
}

void Equilateral::WhoAmI()
{
    std::cout << "I am an equilateral triangle" << std::endl;
}

int main()
{
    Equilateral a;

    a.WhoAmI();

    a.Isosceles::WhoAmI();

    a.Triangle::WhoAmI();

}
