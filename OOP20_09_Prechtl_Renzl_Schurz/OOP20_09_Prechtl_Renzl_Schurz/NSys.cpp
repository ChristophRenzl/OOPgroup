#include <iostream>
#include "NSys.h"
#include <math.h>
#include <array>
#include <vector>

//ASCII:
//A=65
//....
//Z=90
//
//Ascii zwischen 65 bis 90  -55
//A=10

//int NSys::findBase(std::string number)
//{
//	int max = 0;
//
//	char tmp=*number.begin();
//
//	for (auto it = number.begin();it!=number.end();it++)
//	{
//		if (*it > max)
//		{
//			tmp = *it;
//		}
//	}
//
//	if (tmp >= 48 && tmp <= 57)
//	{
//		max = tmp - 48;
//	}
//	if (tmp >= 65 && tmp <= 90)
//	{
//		max = tmp - 55;
//	}
//	 
//
//	return max;
//}

inline int NSys::tointeger()
{
	int zahl = 0;
	int base = this->Base;
	std::string number = this->Number;
	int n = number.length();
	std::vector<char> carr(number.begin(),number.end());

	for (auto it = carr.begin(); it != carr.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	//for (int i=0;i!=n;i++)
	//{
	//	char* help = &number[n-i];
	//	//int help2 = (int)help;

	//	if ((int)help >= 48 && (int)help <= 57)
	//	{
	//		zahl += ((int)help - 48)* pow(base, i);
	//	}
	//	if ((int)help >= 65 && (int)help <= 90)
	//	{
	//		zahl += pow(base,i) * ((int)help - 55);
	//	}
	//	i++;
	//}
	return zahl;
}
