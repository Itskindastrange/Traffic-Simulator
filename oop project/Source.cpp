#include "Header.h"
#include "lane.h"
#include "road.h"
#include"intersection.h"
#include "trafficsignal.h"
#include "vehicle.h"
#include "vehicles.h"
#include"signals.h"
#include <iostream>
using namespace std;
int main() {
	// Initialising
	int w = 0, h = 0;
	getWindowDimensions(w, h);
	
	cls();
	showConsoleCursor(false);
	intersection intersect(w / 2 - 80, h / 2 - 80, w / 2 + 81, h / 2 + 81); // passing intersection points

	trafficsignal s1(360, 140, 380, 160);    // making four traffic signals
	trafficsignal s2(580, 323, 600, 343);
	trafficsignal s3(565, 350, 585, 370);
	trafficsignal s4(373, 115, 393, 135);

	int si = 4;  // setting size of traffic signal
	trafficsignal* s = new trafficsignal[si]; // creating an array of traffic signals to pass on to signals
	s[0] = s1;
	s[1] = s2;
	s[2] = s3;
	s[3] = s4;
	signals trafficsignals(s, si);// creating signals which contain traffic signals 
	drawRectangle(0, 0, w / 2 - 79, h / 2 - 79, 126, 200, 86, 126, 200, 86);  //creating grass for sides of road
	drawRectangle(w / 2 + 81, 0, w, h / 2 - 81, 126, 200, 86, 126, 200, 86);
	drawRectangle(0, h / 2 + 81, w / 2 - 79, h, 126, 200, 86, 126, 200, 86);
	drawRectangle(w / 2 + 81, h / 2 + 81, w, h, 126, 200, 86, 126, 200, 86);
	trafficsignal *ts = &trafficsignals;
	ts->create(); // implementing Polymorphism

	vehicle v0(3, h / 2 - 50, 0, 5); // creating vehicles for simulator
	vehicle v1(90, h / 2 +30, 1, 5);
	vehicle v2(w/2-50, 3, 2, 5);
	vehicle v3(w / 2+20, 43, 3, 5);

	si = 4;
	vehicle* v = new vehicle[si]; // creating an array of vehicles
	v[0] = v0;
	v[1] = v1;
	v[2] = v2;
	v[3] = v3;
	road r2(w / 2 - 80, 0, w / 2 - 80, h, w / 2 + 80, h, w / 2 + 80, 0, intersect, 0); // creating road and passing object of intersection
	r2.create();
	road r1(0, h / 2 - 80, w, h / 2 - 80, w, h / 2 + 80, 0, h / 2 + 80, intersect,0);// creating road and passing object of intersection
	r1.create();
	
	vehicles cars(v, si, trafficsignals,intersect,r1,r2);  // creating an object of vehicle which contain all the vehicles
	vehicle* ve = &cars;

	ve->start(); // Implementing Polymorphism
	
}

