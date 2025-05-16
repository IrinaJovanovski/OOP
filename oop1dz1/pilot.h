#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pilot {
	string name;
	int flying_hours;
	bool on_flight;
public:
	Pilot(string n, int h, bool of = false) : name(n),flying_hours(h),on_flight(of){}
	string getName() const;
	int getHours() const;
	bool getInfo() const;
	void addHours(int hours);
	void updateInfo(bool t);
	Pilot(const Pilot&) = delete;
	//Pilot& operator = (const Pilot&) = delete;
	void print() const;
};