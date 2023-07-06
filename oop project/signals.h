#pragma once
#include "Header.h"
#include "trafficsignal.h"
#include <iostream>
using namespace std;
class signals:public trafficsignal
{
	trafficsignal * s;
			 int size;
			 int w, h;
public:
	signals()
	{
		s = new trafficsignal[4];
		size = 4;
		w = 0;
		h = 0;
	}
	signals(trafficsignal* s, int size)
	{
		this->size = size;
		this->s = new trafficsignal[size];
		for (int i = 0; i < size; i++)
		{
			this->s[i] = s[i];
		}
		w = 0;
		h = 0;
	}
	void create()
	{
		for (int i = 0; i < size; i++)
		{
			drawRectangle(s[i].rx1, s[i].ry1, s[i].rx2, s[i].ry2, 255, 255, 255, 12, 12, 12);
			if(i<size/2)
			s[i].r = 0, s[i].g = 255, s[i].b = 0;
			else
				s[i].r = 255, s[i].g = 0, s[i].b = 0;
			drawEllipse(s[i].ex1, s[i].ey1, s[i].ex2, s[i].ey2, s[i].r, s[i].g, s[i].b, s[i].r, s[i].g, s[i].b);
		}
	}
	void change(int i)
	{
		if (s[i].r == 255)
		{
			s[i].r = 0;
			s[i].g = 255;
		}
		else if (s[i].g == 255)
		{
			s[i].r = 255;
			s[i].g = 0;
		}
		drawEllipse(s[i].ex1, s[i].ey1, s[i].ex2, s[i].ey2, s[i].r, s[i].g, s[i].b, s[i].r, s[i].g, s[i].b);
	}
	char color(int i)
	{
		if (s[i].r == 255)
		{
			return 'r';
		}
		else
			return 'g';
	}
	void set(char i,int y)
	{
		if (i == 'r')
		{
			s[y].g = 0;
			s[y].r = 255;
			s[y].b = 0;
			drawEllipse(s[i].ex1, s[i].ey1, s[i].ex2, s[i].ey2, s[i].r, s[i].g, s[i].b, s[i].r, s[i].g, s[i].b);
		}
		if (i == 'g')
		{
			s[y].g = 255;
			s[y].r = 0;
			s[y].b = 0;
			drawEllipse(s[i].ex1, s[i].ey1, s[i].ex2, s[i].ey2, s[i].r, s[i].g, s[i].b, s[i].r, s[i].g, s[i].b);
		}
		else if(i=='y')
		{
			cout << "f";
			s[y].g = 255;
			s[y].r = 255;
			s[y].b = 0;
			drawEllipse(s[y].ex1, s[y].ey1, s[y].ex2, s[y].ey2, s[y].r, s[y].g, s[y].b, s[y].r, s[y].g, s[y].b);
		}
	}
};