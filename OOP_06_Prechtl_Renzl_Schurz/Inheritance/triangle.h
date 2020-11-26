#pragma once

class Triangle {
public:
	void WhoAmI();
};

class Isosceles : public Triangle {
public:
	void WhoAmI();
};

class Equilateral : public Isosceles{
public:
	void WhoAmI();
};