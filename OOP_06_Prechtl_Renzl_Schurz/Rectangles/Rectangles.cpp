#include <iostream>
#include "RectangleArea.h"

void RectangleArea::read_input()
{
	int h, b;

	std::cout << "H=";
	std::cin >> h;
	std::cout << std::endl;
	std::cout << "B=";
	std::cin >> b;

	if (1 >= h || b >= 100)
	{
		if (1 >= h)
		{
			std::cerr << "Hoehe kleiner als 1!" << " (" << h << ")" << std::endl;
		}
		if (b >= 100)
		{
			std::cerr << "Breite groesser als 100!" << " (" << b << ")" << std::endl;
		}
	}
	else {
		H = h;
		B = b;
	}
}

void Rectangle::display()
{
	std::cout << "h=" << H << " b=" << B << std::endl;
}

void RectangleArea::display()
{
	if (1 >= H || B >= 100)
	{
		std::cerr << "Flaeche kann nicht ausgegeben werden." << std::endl;
	}
	else {
		std::cout << "h=" << H << " b=" << B << " A=" << H * B << std::endl;
	}
}


int main()
{
	std::cout << "H muss >= 1 sein! & B muss <= 100 sein!" << std::endl;

	RectangleArea a;

	a.read_input();

	a.Rectangle::display();

	a.display();
}