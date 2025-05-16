#include <iostream>
#include "Lista.h"
#include "Parametar.h"
#include "Argument.h"
#include "Funkcija.h"
#include "Biblioteka.h"
int main() {
    Argument a1("a1",Parametar::INT,20);
    Argument aii("aii",Parametar::INT,25);
    cout << "Argument 1: " << a1 << endl;
    Argument b2("b2",Parametar::STRING,"plaza");
    cout << "Argument 2: " << b2 << endl;
    Argument c3("c3",Parametar::FLOAT,20.19);
    cout << "Argument 3: " << c3 << endl;
    Parametar a2("a2",Parametar::INT);
    Parametar a3("a3",Parametar::FLOAT);
    cout << "a2 == a3? " << (a2 == a3) << endl;
    Parametar a4("a4",Parametar::INT);
    cout << "a2 == a4? " << (a2 == a4) << endl;
    cout << "b2 == a1? " << (b2 == a1) << endl;
    cout << "a1 == aii? " << (a2 == aii) << endl;
    cout << a3 << endl;
    Funkcija f1("f1");
    Funkcija f2("f2");
    f1.addToTheFunction(&a2);
    cout << f1;
    f1.addToTheFunction(&a4);
    f2.addToTheFunction(&b2);
    f2.addToTheFunction(&c3);
    cout << f1.getParemeterFromPosition(1) << endl;
    Biblioteka b1;
    b1.addToTheLibrary(&f1);
    Funkcija f3("f3");
    b1.addToTheLibrary(&f2);
    b1.addToTheLibrary(&f3);
    f3.addToTheFunction(&a3);
    cout << "Biblioteka : " << b1;
    return 0;
}
