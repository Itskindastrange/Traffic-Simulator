#pragma once
#include"Header.h"
#include "lane.h"
#include"intersection.h"
#include "trafficsignal.h"
class road :protected lane,protected intersection
{
	lane l;
	intersection i;
	int direction;
protected:
	int x1, y1, x2, y2, x3, y3, x4, y4;
public:
	road()
	{
		x1 = x2 = x3 = x4 = y1 = y2 = y3 = y4 = 0;
	}
	road(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) :l((x1 + x4) / 2, (y1 + y4) / 2, (x2 + x3) / 2, (y2 + y4) / 2)
	{
		this->x1 = x1;
		this->x2 = x2;
		this->x3 = x3;
		this->x4 = x4;
		this->y1 = y1;
		this->y2 = y2;
		this->y3 = y3;
		this->y4 = y4;
	}
	road(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, intersection i,int direction) :l((x1 + x4) / 2, (y1 + y4) / 2, (x2 + x3) / 2, (y2 + y3) / 2,i),i(i)/*, s(350, 300 / 2, 360, 170)*/
	{
		this->x1 = x1;
		this->x2 = x2;
		this->x3 = x3;
		this->x4 = x4;
		this->y1 = y1;
		this->y2 = y2;
		this->y3 = y3;
		this->y4 = y4;
		this->direction = direction;
	}
	void create()
	{
        drawRectangle(x1, y1, x3, y3, 255, 255, 255,71,72,76);
		l.create();
		i.create();
	}
};