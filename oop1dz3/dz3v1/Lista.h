
#ifndef UNTITLED14_LISTA_H
#define UNTITLED14_LISTA_H
#include <iostream>
#include <exception>
using namespace std;

class GNeispravanIndeks : public exception{
public:
    GNeispravanIndeks() : exception(){
        cout << "Indeks je izvan dozvoljenog opsega!";
    }
    /* ili alternativno
    friend ostream& operator<< (ostream& os, const GNeispravanIndeks&){
        return (os << "Indeks je izvan granica liste!" << endl);
    }*/
};

template<typename T>
class Lista {
    struct Elem{
        T& data;
        Elem* next;
        Elem(T& d) : data(d){
            next = nullptr;
        }
    };
    Elem *first, *last;
    int num_of_elements;
    void copy(const Lista& l);
    void move(Lista& l);
    void erase();

public:
    Lista(){
        first = nullptr;
        last = nullptr;
        num_of_elements = 0;
    }
    Lista(const Lista& l) { copy(l); }
    Lista(Lista&& l) { move(l); }
    Lista& operator= (const Lista& l){
        if(this != &l){
            erase();
            copy(l);
        }
        return *this;
    }
    Lista& operator= (Lista&& l){
        if(this != &l){
            erase();
            move(l);
        }
        return *this;
    }
    ~Lista(){ erase(); }
    Lista& addToTheEnd(T& t){
        last = ((!first) ? first : last->next) = new Elem(t);
        num_of_elements++;
        return *this;
    }
    int getNumOfElements() const{ return num_of_elements;}
    const T& operator[] (int index) const;
    T& operator[] (int index);
    T& deleteElementAtIndex(int index);
};


template<typename T>
T &Lista<T>::deleteElementAtIndex(int index) {
    int i = 1;
    T& t = const_cast<T&>((*this)[index]);
    for(Elem* curr = first; curr; curr = curr->next){
        if(index == 0){
            Elem* old = first;
            first = first->next;
            delete old;
            num_of_elements--;
            return t;
        }else if(index == i && i!=0){
            Elem* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            num_of_elements--;
            return t;
        }else{
            i++;
        }
    }
    return t;
}

template<typename T>
void Lista<T>::erase() {
    while(first){
        Elem* old = first;
        first = first->next;
        delete old;
    }
    last = nullptr;
    num_of_elements = 0;
}

template<typename T>
void Lista<T>::copy(const Lista &l) {
    first = last = nullptr;
    for(Elem* curr = l.first; curr; curr = curr->next){
        last = ((!first) ? first : last->next) = new Elem(curr->data);
    }
    num_of_elements = l.num_of_elements;
}

template<typename T>
T &Lista<T>::operator[](int index) {
    if(index >= num_of_elements || index < 0) throw GNeispravanIndeks();
    int i = 0;
    for(Elem* curr = first; curr; curr = curr->next){
        if(i == index){
            return (curr->data);
        }
        i++;
    }
}

template<typename T>
const T &Lista<T>::operator[](int index) const {
    if(index >= num_of_elements || index < 0) throw GNeispravanIndeks();
    int i = 0;
    for(Elem* curr = first; curr; curr = curr->next){
        if(i == index){
            return (curr->data);
        }
        i++;
    }
}

template<typename T>
void Lista<T>::move(Lista &l) {
    first = l.first;
    last = l.last;
    l.first = l.last = nullptr;
    num_of_elements = l.num_of_elements;
}



#endif //UNTITLED14_LISTA_H
