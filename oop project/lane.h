#pragma once
#include"Header.h"
#include"intersection.h"
class lane /*:protected road*/
{
	intersection i;
protected:
	int x1, y1, x2, y2;
public:
	lane()  // default constructor
	{
		x1 = x2 = y1 = y2 = 0;
	}
	lane(int x1, int y1, int x2, int y2,intersection i)// parametrized constructor with object of intersection
	{
		this->i = i;
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
	lane(int x1, int y1, int x2, int y2)  // creating parametrized constructor
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
	void create()// creating object on console
	{
		drawLine(x1, y1, x2, y2, 255,255,255);
	}
};