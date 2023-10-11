// Created by Fin on 11.10.2023.
// Lecture 11
// 4.4 Casts between base and derived classes.

#include <iostream>


class Base {
public:
    int a = 0;
    Base() = default;
    Base(const Base&) {
        std::cout << "copy Base\n";
    }
};

class Derived: public Base {
    //TODO: Приватное наследование означает, что мы создаем наследника, но он не дает другим считать себя наследником
public:
    int b = 1;
    Derived() = default;
    Derived(const Derived&) {
        std::cout << "copy Derived\n";
    }
};

void g(Derived& d){

}

void f(Base& b){
    //g(b); // error: can't convert Base* to Derived*
}


int main() {
    Derived d;

    Base& b = d;

    static_cast<Derived&>(b); // OK: Derived is derived from Base

    static_cast<Base&>(d); // OK: Derived is derived from Base


    // slicing
    Base* pb = &d; // OK: Derived is derived from Base

    //Derived* pd = pb; //Cannot initialize a variable of type 'Derived *' with an lvalue of type 'Base *'
    
    //Base& br = d; // OK: Derived is derived from Base
    //Derived& dd = br; //error: can't convert Base* to Derived*
    //f(d); // OK: Derived is derived from Base
}