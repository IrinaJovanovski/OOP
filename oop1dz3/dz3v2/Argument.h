#include "Parametar.h"
#include <string>
#ifndef UNTITLED16_ARGUMENT_H
#define UNTITLED16_ARGUMENT_H

template <typename T>
class Argument: public Parametar {
    T value;
public:
    Argument(string n, Type t, T v) : Parametar(n, t){
        value = v;
    }
    T& getValue() const { return value; }
    void write(ostream& os)const override;
};

template<typename T>
void Argument<T>::write(ostream &os) const {
    Parametar::write(os);
    os << " = " << value;
}


#endif //UNTITLED16_ARGUMENT_H
