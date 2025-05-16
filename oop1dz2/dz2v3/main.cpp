#include <iostream>
#include <string>
#include "Firma.h"

int main() {
    Firma f;
    Radnik r1(50,4);
    Radnik r2(100,8);
    Radnik r3(95,7);
    Radnik r4(110,8);
    f.postaviIme("UNC");
    f.postaviProviziju(20);
    f += &r1;
    f += &r2;
    f += &r3;
    f += &r4;
    Posao p("Prevodilac",100,4000);
    f*p;
    f+p;
    cout << f;
    return 0;
}
