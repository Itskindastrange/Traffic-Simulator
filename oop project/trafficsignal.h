#pragma once
#include"Header.h"
class trafficsignal
{
public:
	int r = 0, g = 0, b = 0, rx1, ry1, rx2, ry2, ex1, ex2, ey1, ey2;
	trafficsignal() // default constructor
	{
		rx1= ry1= rx2= ry2= ex1= ex2= ey1= ey2 = 0;
	}
	trafficsignal(int a, int b, int c, int d)// parametrized constructor
	{
		rx1 = a;
		ry1 = b;
		rx2 = c;
		ry2 = d;
		ex1 = rx1 + 2;
		ey1 = ry1 + 2;
		ex2 = rx2-3;
		ey2 = ry2-4;
	}
	virtual void create() // creating object on console
	{
		drawRectangle(rx1, ry1, rx2, ry2, 255, 255, 255,12,12,12);
		r = 255, g = 0, b = 0;
		drawEllipse(ex1, ey1, ex2, ey2, r, g, b,r,g,b);
	}
	virtual void change() // for changing lights of signal
	{
		if (r == 255)
		{
			r = 0;
			g = 255;
		}
		else if (g == 255)
		{
			r = 255;
			g = 0;
		}
		drawEllipse(ex1, ey1, ex2, ey2, r, g, b, r, g, b);
	}
};