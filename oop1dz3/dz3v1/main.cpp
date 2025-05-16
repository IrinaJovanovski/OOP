#include <iostream>
#include <exception>
#include "Vreme.h"
#include "LetnjaGuma.h"
#include "ZimskaGuma.h"
#include "GumaZaSveSezone.h"
#include "Lista.h"
using namespace std;

int main() {
    try{
        Vreme v1(12,15,23,12,2023);
        Vreme v2(23, 28,31, 12, 2024);
        v2 += 100;
        Vreme v3(12,15,23,12,2023);
        cout << (v1 == v3) << endl;
        cout << v2;
        LetnjaGuma l1(50,80,3,1.6,5000,v1);
        LetnjaGuma l2(50,80,3,1.6,5000,v1);
        ZimskaGuma z1(50,40,3,6,6000,v2);
        GumaZaSveSezone a1(50,80,3,6,5000,v3);
        cout << (l1 == l2) << endl;
        cout << a1;
        cout << (z1 == a1) << endl;
        cout << z1;
        cout << "Korektna dubina(pre i posle smanjivanja dubine);" << endl;
        cout << l1.CorrectDepthOfTread() << endl;
        l1--;
        cout << l1.CorrectDepthOfTread() << endl;
        Lista<Vreme> listaVreme;
        listaVreme.addToTheEnd(v1);
        listaVreme.addToTheEnd(v2);
        listaVreme.addToTheEnd(v3);
        cout << listaVreme[0];
        listaVreme.deleteElementAtIndex(1);
        cout << listaVreme.getNumOfElements() << endl;
        cout << (listaVreme[1] == listaVreme[0]) << endl;
        Lista<Guma> listaguma;
        listaguma.addToTheEnd(l1);
        listaguma.addToTheEnd(l2);
        listaguma.addToTheEnd(z1);
        listaguma.addToTheEnd(a1);
        cout << "Broj guma u listi: " << listaguma.getNumOfElements() << endl;
        cout << "Obrisan je: " << listaguma.deleteElementAtIndex(0);
        cout << "i " << listaguma.deleteElementAtIndex(0);
        cout << "i " << listaguma.deleteElementAtIndex(0) ;
        cout << "i " << listaguma.deleteElementAtIndex(0);
        cout << "preostali broj guma je " << listaguma.getNumOfElements() << endl;
        listaguma.deleteElementAtIndex(0);
    }catch(exception e){}

    return 0;
}
