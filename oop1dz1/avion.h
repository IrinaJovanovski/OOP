#pragma once
#include <iostream>
#include <string>
#include "pilot.h"
using namespace std;

class Avion {
	string name;
	Pilot* captain;
	Pilot* copilot;
	int max;
public:
	Avion(string n, int m) : name(n), max(m) {}
	string getPlaneName() const;
	Pilot* getCaptain() const;
	Pilot* getCopilot() const;
	int getPassengersMax() const;
	void addCaptain(Pilot* cap);
	void addCopilot(Pilot* cop);
	Avion(const Avion&) = delete;
	void printAvion() const;
};