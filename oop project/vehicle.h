#pragma once
#include "Header.h"
class vehicle
{
public:
	int x1, y1, direction, speed;
	int w = 0, h = 0;
	vehicle()// default constructor
	{
		x1 = y1 = 0;
		direction = 0;
		speed = 0;
	}
	vehicle(int x1, int y1, int a, int b)// parametrized constructor
	{
		this->x1 = x1;
		this->y1 = y1;
		direction = a;
		speed = b;
	}
	virtual void start() // for moving cars
	{
		getWindowDimensions(w, h);
		int i = x1, j = y1;
		if (direction == 0) {
			for (;;)
			{
				drawRectangle(10 * i + 0, j + 0, 10 * i + 25, j + 25, 0, 0, 0, 255, 255, 0);
				delay(speed);
				drawRectangle(10 * i + 0, j + 0, 10 * i + 25, j + 25, 12, 12, 12, 12, 12, 12);
				i++;
				if (10 * i > w - 50)
					i = x1;
				
			}
		}
		else if (direction == 1)
		{
			for (;;) {
				drawRectangle(10 * i + 0, j + 0, 10 * i + 25, j + 25, 0, 0, 0, 255, 255, 0);
				delay(speed);
				drawRectangle(10 * i + 0, j + 0, 10 * i + 25, j + 25, 12, 12, 12, 12, 12, 12);
				i--;
				if (10 * i < 21)
					i = x1;
				char c = getKey();

				if (c == 'q') break;

				if (c == 's') i = x1;

				if (c == 'k') j += 10;

				if (c == 'i') j -= 10;
			}
		}
		else if (direction == 2)
		{
			for (;;) {
				drawRectangle(i + 0, 10*j + 0,  i + 25, 10*j + 25, 0, 0, 0, 255, 255, 0);
				delay(speed);
				drawRectangle(i + 0, 10*j + 0, i + 25,10* j + 25, 12, 12, 12, 12, 12, 12);
				j++;
				if (10 * j > h-50)
					j = y1;
				char c = getKey();

				if (c == 'q')
					break;

				if (c == 's') j = y1;

				if (c == 'k') j += 10;

				if (c == 'i') j -= 10;
			}
		}
		else if (direction == 3)
		{
			for (;;) {
				drawRectangle(i + 0, 10 * j + 0, i + 25, 10 * j + 25, 0, 0, 0, 255, 255, 0);
				delay(speed);
				drawRectangle(i + 0, 10 * j + 0, i + 25, 10 * j + 25, 12, 12, 12, 12, 12, 12);
				j--;
				if (10 * j < 21)
					j = y1;
				char c = getKey();

				if (c == 'q')
					break;

				if (c == 's') j = y1;

				if (c == 'k') j += 10;

				if (c == 'i') j -= 10;
			}
		}
	}
};