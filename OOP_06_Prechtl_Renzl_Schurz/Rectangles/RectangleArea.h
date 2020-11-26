#pragma once
#pragma once

class Rectangle
{
public:
	float H, B;
	void display();
};

class RectangleArea : public Rectangle
{
public:
	void read_input();
	void display();
};