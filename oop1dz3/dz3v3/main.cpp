#include <iostream>
#include "Polje.h"
#include "Greska.h"
#include "Jedrilica.h"

int main() {
    try{
        Polje p(Polje::A, 10);
        string s[]{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
        cout << s[p.getColumn()] << p.getRow() << endl;
        p = p.getPolje(8, -5);
        cout << s[p.getColumn()] << p.getRow() << endl;
        Polje p2(Polje::G, 7);
        Jedrilica j1(p);
        Jedrilica j2(p2);
        cout << "Preklapanje jedrilica: " << (j1&j2) << endl;
        for(int i = 0; i < j1.getFields().getNumOfElements(); i++){
            cout << s[((j1.getFields())[i]).getColumn()] << ((j1.getFields())[i]).getRow() << endl;
        }
        Polje p3 = p2.getPolje(0, 1);
        Jedrilica j3(p3);
        Figura& j4 = j1.figuraCopy();
        cout << "kopija: " << endl;
        for(int i = 0; i < j4.getFields().getNumOfElements(); i++){
            cout << s[((j4.getFields())[i]).getColumn()] << ((j4.getFields())[i]).getRow() << endl;
        }
        cout << "Preklapanje jedrilica: " << (j1&j3) << endl;
        cout << "Jednake figure: " << (j1&j2) << endl;
        j4.hitField(Polje(Polje::I,5));
        j4.hitField(Polje(Polje::H,5));
        j4.hitField(Polje(Polje::J,5));
        j4.hitField(Polje(Polje::H,6));
        j4.hitField(Polje(Polje::J,6));
        j4.hitField(Polje(Polje::H,4));
        j4.hitField(Polje(Polje::J,4));
        cout << "pogodjena figura : " << j4.hitFigure();
    }catch(exception e){}
    return 0;
}
