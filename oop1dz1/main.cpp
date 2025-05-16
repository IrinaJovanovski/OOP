#include <iostream>
#include <string>
#include "flota.h"
#include "avion.h"
#include "pilot.h"
using namespace std;

int main() {
	Flota f1("Flota I");
	Avion a1("Boing 747", 100), a2("Foker", 200), a3("Airbus 330", 150);
	Pilot p1("Vladimir Aleksic", 110, false), p2("Radivoj Bozic", 500, true),
		p3("Milos Ilic", 1000, false), p4("Tadija Sondermajer", 349, false),
		p5("Zoran Radosavljevic", 1157, true), p6("Iljo Arizanov", 57, false);
	a1.addCaptain(&p1);
	a2.addCaptain(&p2);
	a3.addCaptain(&p3);
	a1.addCopilot(&p4);
	a2.addCopilot(&p5);
	a3.addCopilot(&p6);
	f1.addPlanes(&a1);
	f1.addPlanes(&a2);
	f1.addPlanes(&a3);
	f1.print();
	cout << endl;
	f1.maxPassangersPlane()->printAvion();

}