#include <iostream>
#include "complex.h"

Complex::Complex(int A,int B)
{
	a = A;
	b = B;
}

Complex::Complex()
{
	a = 0;
	b = 0;
}

Complex::~Complex()
{
	std::cout << "deleted!" << std::endl;
}

//inline Complex operator+(const Complex A, const Complex B)
//{
//	Complex C;
//	C.a = A.a + B.a;
//	C.b = A.b + B.b;
//	return C;
//}

Complex Complex::readInput(int x, int y)
{
	Complex tmp;
	tmp.a=x;
	tmp.b= y;
	return tmp;
}

void Complex::printComplex(Complex A)
{
	std::cout << A.a << A.b << "i" << std::endl;
}
