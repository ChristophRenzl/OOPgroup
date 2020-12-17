#pragma once

class Complex
{
public:

	int a, b;

	Complex(int A,int B);
	Complex();

	~Complex();

	Complex operator+(const Complex& A) const
	{
		return Complex(a + A.a, b + A.b);
	}
	//inline Complex operator+(const Complex A, const Complex B);
	Complex readInput(int x, int y);
	void printComplex(Complex A);
};