#include <iostream>
#include <string>
#include "Statistika.h"


int main() {
    Kosarkas k1("Toma Tomic",34,Kosarkas::pozicija::PG);
    Statistika s1(k1);
    s1.addTryI(3);
    s1.addScoreII();
    s1.addScoreI(5);
    s1.addnumAssistance();
    Kosarkas k2("Petar Peric",28,Kosarkas::pozicija::C);
    Statistika s2(k2);
    s2.addnumAssistance(2);
    k2.changePoz(Kosarkas::pozicija::SF);
    cout << s1;
    cout << endl;
    cout << s2;
    return 0;
}
