#pragma once
#include "Header.h"
class intersection
{
protected:
	
public:
	int x1, x2, y1, y2;
	intersection() // default constructor
	{
		x1 = x2 = y1 = y2 = 0;
	}
	intersection(int x1, int y1, int x2, int y2) // parametrized constructor
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
	intersection(const intersection&a) // copy constructor
	{
		this->x1 = a.x1;
		this->y1 = a.y1;
		this->x2 = a.x2;
		this->y2 = a.y2;
	}
	void create()// creating object on console
	{
		drawRectangle(x1, y1, x2, y2, 71,72,76,71,72,76); 
	}
};