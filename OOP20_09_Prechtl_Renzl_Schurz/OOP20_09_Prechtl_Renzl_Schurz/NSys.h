#pragma once
#include <string.h>
#include <vector>

//enum number {
//	A = 10, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
//};

class NSys {
public:

	int Base;
	std::string Number;

	NSys():
	Base{ 0 },
	Number { "0" } {};
	

	/*int findBase(std::string number);*/

	NSys(int base, std::string number)
	{
		this->Base = base;
		this->Number = number;
	}
	/*NSys(std::string number)
	{
		this->Number = number;
		this->Base = findBase(number);
	}*/


	inline int tointeger();

};