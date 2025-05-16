#include "flota.h"

void Flota::addPlanes(Avion *p)
{
	first = new Elem(p, first);
}

int Flota::totalPlanes() const
{
	int cnt = 0;
	for (Elem* temp = first; temp; temp = temp->next) {
		cnt++;
	}
	return cnt;
}

int Flota::maxPassengersPlanes() const
{
	int m = 0;
	for (Elem* temp = first; temp; temp = temp->next) {
		m += temp->plane->getPassengersMax();
	}
	return m;
}

Avion* Flota::maxPassangersPlane() const
{
	int m = 0;
	for (Elem* temp = first; temp; temp = temp->next) {
		if (temp->plane->getPassengersMax() > m) {
			m = temp->plane->getPassengersMax();
		}
	}
	for (Elem* temp = first; temp; temp = temp->next) {
		if (m == temp->plane->getPassengersMax()) {
			return temp->plane;
		}
	}
}

void Flota::print() const
{

	cout << name << ":" << endl;
	for (Elem* temp = first; temp; temp = temp->next) {
		temp->plane->printAvion();
		cout << endl;
	}
}


