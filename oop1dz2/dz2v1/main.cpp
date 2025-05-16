#include <iostream>
#include <string>
#include "Kontakt.h"
using namespace std;

int main() {
    Broj b1("381","63","234567");
    Broj b2("381","60","290746");
    Broj b3("209","59","947361");
    Broj b4("210","90","9473961");
    Broj b5("555","34","9123456");
    Broj b6("999","32","1373961");
    Kontakt k1("posao",b1);
    k1 += b2;
    Kontakt k2("kuca",b3);
    k2 += b4;
    Kontakt k3("inostrani",b5);
    k3 += b6;
    cout << k1;
    cout << endl;
    cout << k2;
    cout << endl;
    cout << k3;
    cout << endl;
    return 0;
}
