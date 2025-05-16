#include <iostream>
#include <string>
#include "Lista.h"
#include "NaredbaSelekcije.h"
#include "SelektorKolona.h"
using namespace std;

int main() {
    try{
        Lista<string> kolone;
        Lista<string> kolone1;
        string s[]{"ime", "prezime", "zanimanje"};
        string string1[]{"ime","fakultet"};
        kolone += s[0];
        kolone += s[1];
        kolone += s[2];
        kolone1 += string1[0];
        kolone1 += string1[1];
        Tabela t("Osoba", kolone);
        cout << t.containsColumn("prezime") << endl;
        cout << t.containsColumn("staz") << endl;
        cout << t.contatinsColumns(kolone) << endl;
        cout << t.contatinsColumns(kolone1) << endl;
        SelektorKolona selektorKolona(kolone);
        Selektor* selektor = new SelektorKolona(kolone);
        Selektor* selektor1 = new SelektorKolona(kolone1);
        cout << (*selektor1 == *selektor) << endl;
        NaredbaSelekcije naredbaSelekcije(t, selektorKolona);
        cout << string(naredbaSelekcije);
        Tabela nova("Nova",kolone1);
        NaredbaSelekcije naredbaSelekcije1(nova, selektorKolona);
    }catch(exception e){}
    return 0;
}
