#include "pilot.h"

string Pilot::getName() const
{
    return name;
}

int Pilot::getHours() const
{
	return flying_hours;
}

bool Pilot::getInfo() const
{
	return on_flight;
}

void Pilot::addHours(int hours)
{
	flying_hours = flying_hours + hours;
}

void Pilot::updateInfo(bool t)
{
	on_flight = t;
}

void Pilot::print() const
{
	cout << name << "(" << flying_hours << ")" << (on_flight ? "L" : "N");
}

