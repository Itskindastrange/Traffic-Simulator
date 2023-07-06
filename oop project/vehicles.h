#pragma once
#include <iostream>
#include "vehicle.h"
#include "signals.h"
#include "intersection.h"
#include "road.h"
using namespace std;
class vehicles :public signals, public vehicle
{
	intersection inter;
	signals s;
	vehicle* v;
	road r1;
	road r2;
	int size;
	int ssize;
	int w, h;
	int t = 0;
public:
	vehicles() // default constructor 
	{
		v = new vehicle[4];
		size = 4;
		w = 0;
		h = 0;
	}
	vehicles(vehicle* v, int size) // parametrized constructor
	{
		this->size = size;
		this->v = new vehicle[size];
		for (int i = 0; i < size; i++)
		{
			this->v[i] = v[i];
		}
		w = 0;
		h = 0;
	}
	vehicles(vehicle* v, int size, signals s0) :s(s0) // parametrized constructor
	{
		this->size = size;
		this->v = new vehicle[size];
		for (int i = 0; i < size; i++)
		{
			this->v[i] = v[i];
		}
	}
	vehicles(vehicle* v, int size, signals s0, intersection i0) :s(s0), inter(i0)
	{
		this->size = size;
		this->v = new vehicle[size];
		for (int i = 0; i < size; i++)
		{
			this->v[i] = v[i];
		}
	}
	vehicles(vehicle* v, int size, signals s0, intersection i0, road r1, road r2) :s(s0), inter(i0), r1(r1), r2(r2)
	{
		this->size = size;
		this->v = new vehicle[size];
		for (int i = 0; i < size; i++)
		{
			this->v[i] = v[i];
		}
	}
	bool check(int i, int*& cd)
	{
		for (int j = 0; j < size; j++)
		{
			if (j == i)
			{
				continue;
			}
			if (v[i].direction == 0)
			{
				if (cd[i * 2] >= cd[j * 2] - 2 && cd[i * 2] <= cd[j * 2])
					if (!(cd[i * 2 + 1] != cd[j * 2 + 1]))
					{
						cd[i * 2] += 4;
						return false;
					}
				if (cd[i * 2] == cd[j * 2] - 3)
				{
					if (!(cd[i * 2 + 1] != cd[j * 2 + 1]))
						return true;
				}
			}
			if (v[i].direction == 1)
			{
				if (cd[i * 2] <= cd[j * 2] + 2 && cd[i * 2] >= cd[j * 2])
					if (!(cd[i * 2 + 1] != cd[j * 2 + 1]))
					{
						cd[i * 2] += 4;
						return false;
					}
				if (cd[i * 2] == cd[j * 2] + 3)
				{
					if (!(cd[i * 2 + 1] != cd[j * 2 + 1]))
						return true;
				}
			}
			if (v[i].direction == 3)
			{
				if (cd[i * 2 + 1] <= cd[j * 2 + 1] + 2 && cd[i * 2 + 1] >= cd[j * 2 + 1])
					if (!(cd[i * 2] != cd[j * 2]))
					{
						cd[i * 2 + 1] -= 4;
						return false;
					}
				if (cd[i * 2 + 1] == cd[j * 2 + 1] + 3)
				{
					if (!(cd[i * 2] != cd[j * 2]))
						return true;
				}
			}
			if (v[i].direction == 2)
			{
				if (cd[i * 2 + 1] <= cd[j * 2 + 1] + 2 && cd[i * 2 + 1] >= cd[j * 2 + 1])
					if (!(cd[i * 2] != cd[j * 2]))
					{
						cd[i * 2 + 1] += 4;
						return false;
					}

				if (cd[i * 2 + 1] == cd[j * 2 + 1] - 3)
				{
					if (!(cd[i * 2] != cd[j * 2]))
						return true;
				}
			}
		}
		return false;
	}
	void start() // for moving vehciles
	{
		bool p = false; // for checking if user wants to exit
		getWindowDimensions(w, h);
		int* cd = new int[size * 2]; // for coordinates of all the vehicles
		for (int i = 0; i < size * 2; i++)
		{
			cd[i] = 0;
		}
		for (int i = 0; i < size; i++) // getting coordinates from vehicle class
		{
			cd[i * 2] = v[i].x1;
			cd[i * 2 + 1] = v[i].y1;
		}
		for (;;)
		{
			for (int i = 0; i < size; i++) // for moving vehicles
			{
				char color = 'r';
				t++;
				inter.create();
				if (v[i].direction == 0)
				{
					drawRectangle(10 * cd[i * 2] + 0, cd[i * 2 + 1] + 0, 10 * cd[i * 2] + 25, cd[i * 2 + 1] + 25, 0, 0, 0, 255, 255, 0);
					delay(v[i].speed);
					drawRectangle(10 * cd[i * 2] + 0, cd[i * 2 + 1] + 0, 10 * cd[i * 2] + 25, cd[i * 2 + 1] + 25, 71, 72, 76, 71, 72, 76);
					if (!check(i, cd))
					{
						if (s.color(0) == 'g')
							cd[i * 2]++;
						else if ((10 * cd[i * 2] > inter.x1 - 30 || 10 * cd[i * 2] < inter.x1 - 40))
						{
							cd[i * 2]++;
						}
					}
					if (10 * cd[i * 2] > w - 50)
					{
						cd[i * 2] = v[i].x1;
						p = true; // if vehicle has covered the distance it resets back to original position
					}
					char c = getKey(); // getting input 

					if (c == 's') cd[i * 2] = v[i].x1; // for resetting distance
					if (10 * cd[i * 2] >= inter.x1 && 10 * cd[i * 2] <= inter.x1 + 50) // rest condtions are for changing directions
					{
						if (c == 'k')
						{
							v[i].direction = 2;
							cd[i * 2] = w / 2 - 50;
							cd[i * 2 + 1] = inter.y2 / 10;
							v[i].x1 = w / 2 - 50;
							v[i].y1 = 3;
						}
					}
					if (10 * cd[i * 2] >= inter.x1 + 43 && 10 * cd[i * 2] <= inter.x2)
					{
						if (c == 'i')
						{
							v[i].direction = 3;
							cd[i * 2] = w / 2 + 20;
							cd[i * 2 + 1] = inter.y1 / 10;
							v[i].x1 = w / 2 + 20;
							v[i].y1 = 43;
						}
					}
					if (10 * cd[i * 2] >= inter.x1 && 10 * cd[i * 2] <= inter.x1 + 50)
						if (c == 'm')
						{
							v[i].direction = 1;
							cd[i * 2] = inter.x1 / 10;
							cd[i * 2 + 1] = h / 2 + 30;
							v[i].x1 = 90;
							v[i].y1 = h / 2 + 30;
						}
				}
				if (v[i].direction == 1)
				{
					drawRectangle(10 * cd[i * 2] + 0, cd[i * 2 + 1] + 0, 10 * cd[i * 2] + 25, cd[i * 2 + 1] + 25, 0, 0, 0, 255, 255, 0);
					delay(v[i].speed);
					drawRectangle(10 * cd[i * 2] + 0, cd[i * 2 + 1] + 0, 10 * cd[i * 2] + 25, cd[i * 2 + 1] + 25, 71, 72, 76, 71, 72, 76);
					if (!check(i, cd))
					{
						if (s.color(1) == 'g') // for checking if signal is green
							cd[i * 2]--;
						else if (10 * cd[i * 2] < inter.x2 + 10 || 10 * cd[i * 2]>inter.x2 + 20)
						{
							cd[i * 2]--;
						}
					}
					if (10 * cd[i * 2] < 21)
						cd[i * 2] = v[i].x1;
					char c = getKey();

					if (c == 'y') cd[i * 2] = v[i].x1;
					if (10 * cd[i * 2] >= inter.x1 - 10 && 10 * cd[i * 2] <= inter.x2 - 50)
					{
						if (c == 'h')
						{
							v[i].direction = 2;
							cd[i * 2] = w / 2 - 50;
							cd[i * 2 + 1] = inter.y2 / 10;
							v[i].x1 = w / 2 - 50;
							v[i].y1 = 3;
						}
					}
					if (10 * cd[i * 2] >= inter.x1 + 55 && 10 * cd[i * 2] <= inter.x2)

					{
						if (c == 'n')
						{
							v[i].direction = 3;
							cd[i * 2] = w / 2 + 20;
							cd[i * 2 + 1] = inter.y1 / 10;
							v[i].x1 = w / 2 + 20;
							v[i].y1 = 43;
						}

						if (c == 'b')
						{
							v[i].direction = 0;
							cd[i * 2] = inter.x2 / 10;
							cd[i * 2 + 1] = h / 2 - 50;
							v[i].x1 = 3;
							v[i].y1 = h / 2 - 50;
						}
					}
				}
				if (v[i].direction == 2)
				{
					drawRectangle(cd[i * 2] + 0, 10 * cd[i * 2 + 1] + 0, cd[i * 2] + 25, 10 * cd[i * 2 + 1] + 25, 0, 0, 0, 255, 255, 0);
					delay(v[i].speed);
					drawRectangle(cd[i * 2] + 0, 10 * cd[i * 2 + 1] + 0, cd[i * 2] + 25, 10 * cd[i * 2 + 1] + 25, 71, 72, 76, 71, 72, 76);
					if (!check(i, cd))
					{
						if (s.color(3) == 'g')
							cd[i * 2 + 1]++;
						else if (10 * cd[i * 2 + 1] > inter.y1 - 30 || 10 * cd[i * 2 + 1] < inter.y1 - 40)
						{
							cd[i * 2 + 1]++;
						}
					}
					if (10 * cd[i * 2 + 1] > h - 50)
						cd[i * 2 + 1] = v[i].y1;
					char c = getKey();

					if (c == '1') cd[i * 2 + 1] = v[i].y1;
					if (10 * cd[i * 2 + 1] >= inter.y1 - 5 && 10 * cd[i * 2 + 1] < inter.y1 + 50)
					{
						if (c == '2')
						{
							v[i].direction = 3;
							cd[i * 2] = w / 2 + 20;
							cd[i * 2 + 1] = inter.y1 / 10;
							v[i].x1 = w / 2 + 20;
							v[i].y1 = 43;
						}

						if (c == '3')
						{
							v[i].direction = 0;
							cd[i * 2] = inter.x2 / 10;
							cd[i * 2 + 1] = h / 2 - 50;
							v[i].x1 = 3;
							v[i].y1 = h / 2 - 50;
						}
					}
					if (10 * cd[i * 2 + 1] <= inter.y2 + 5 && 10 * cd[i * 2 + 1] >= inter.y1 + 30)
					{
						if (c == '4')
						{
							v[i].direction = 1;
							cd[i * 2] = inter.x1 / 10;
							cd[i * 2 + 1] = h / 2 + 30;
							v[i].x1 = 90;
							v[i].y1 = h / 2 + 30;
						}
					}
				}
				if (v[i].direction == 3)
				{
					drawRectangle(cd[i * 2] + 0, 10 * cd[i * 2 + 1] + 0, cd[i * 2] + 25, 10 * cd[i * 2 + 1] + 25, 0, 0, 0, 255, 255, 0);
					delay(v[i].speed);
					drawRectangle(cd[i * 2] + 0, 10 * cd[i * 2 + 1] + 0, cd[i * 2] + 25, 10 * cd[i * 2 + 1] + 25, 71, 72, 76, 71, 72, 76);
					if (!check(i, cd))
					{
						if (s.color(2) == 'g')
							cd[i * 2 + 1]--;
						else if (10 * cd[i * 2 + 1] < inter.y2 + 10 || 10 * cd[i * 2 + 1]>inter.y2 + 20)
						{
							cd[i * 2 + 1]--;
						}
					}
					if (10 * cd[i * 2 + 1] < 21)
						cd[i * 2 + 1] = v[i].y1;
					char c = getKey();

					if (c == '5') cd[i * 2 + 1] = v[i].y1;
					if (10 * cd[i * 2 + 1] <= inter.y2 - 5 && 10 * cd[i * 2 + 1] >= inter.y1 + 30)
					{
						if (c == '6')
						{
							v[i].direction = 2;
							cd[i * 2] = w / 2 - 50;
							cd[i * 2 + 1] = inter.y2 / 10;
							v[i].x1 = w / 2 - 50;
							v[i].y1 = 3;
						}
					}
					if (10 * cd[i * 2 + 1] >= inter.y1 - 20 && 10 * cd[i * 2 + 1] < inter.y1 + 50)
						if (c == '7')
						{
							v[i].direction = 0;
							cd[i * 2] = inter.x2 / 10;
							cd[i * 2 + 1] = h / 2 - 50;
							v[i].x1 = 3;
							v[i].y1 = h / 2 - 50;
						}
					if (10 * cd[i * 2 + 1] <= inter.y2 - 5 && 10 * cd[i * 2 + 1] >= inter.y1 + 30)
					{
						if (c == '8')
						{
							v[i].direction = 1;
							cd[i * 2] = inter.x1 / 10;
							cd[i * 2 + 1] = h / 2 + 30;
							v[i].x1 = 90;
							v[i].y1 = h / 2 + 30;
						}
					}
				}
				if (t == 100) // for changing signals
				{
					s.change(1);
					s.change(0);
					s.change(2);
					s.change(3);
				}
				if (t == 230) 
				{
					s.change(1);
					s.change(0);
					s.change(2);
					s.change(3);
					t = 0;
				}
			}
		}
	}
};