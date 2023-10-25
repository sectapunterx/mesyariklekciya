//
// Created by Fin on 25.10.2023.
//
#include <iostream>

struct Base{
    virtual void f() {
        std::cout << "Base\n";
    }
};
struct Derived: public Base{
    void f() {
        std::cout << "Derived\n";
    }
};
int main(){
    Derived d;
    Base& b = d;
    b.f();
    d.f();
}