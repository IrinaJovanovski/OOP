#include "avion.h"


string Avion::getPlaneName() const
{
	return name;
}

Pilot* Avion::getCaptain() const
{
	return captain;
}

Pilot* Avion::getCopilot() const
{
	return copilot;
}

int Avion::getPassengersMax() const
{
	return max;
}

void Avion::addCaptain(Pilot* cap)
{
	if (cap->getHours() >= 100) {
		captain = cap;
		captain->updateInfo(true);
	}
}

void Avion::addCopilot(Pilot* cop)
{
	copilot = cop;
	copilot->updateInfo(true);
}

void Avion::printAvion() const
{
	cout << "AVION:" << name << " - " << max;
}
