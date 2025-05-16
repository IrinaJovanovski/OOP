#pragma once
#include <iostream>
#include <string>
#include "avion.h"
using namespace std;

class Flota {
	string name;
	struct Elem {
		Avion* plane;
		Elem* next;
		Elem(Avion* p, Elem* n = nullptr): plane(p),next(n){}
	};
	Elem* first = nullptr;
public:
	Flota(string n): name(n) {};
	void addPlanes(Avion* p);
	int totalPlanes() const;
	int maxPassengersPlanes() const;
	Avion* maxPassangersPlane() const;
	void print() const;
};