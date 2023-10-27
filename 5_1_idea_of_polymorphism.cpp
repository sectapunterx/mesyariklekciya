//
// Created by Fin on 25.10.2023.
//
#include <iostream>

//5.1 Idea of polymorphism

//virtual function - function that can be overridden in derived classes
//polymorphic type - type with virtual functions
//5.2 Dispatching between virtual and non-virtual methods
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
struct SubDerived: public Derived{
    void f() {
        std::cout << "SubDerived\n";
    }
};

int main(){
    Derived d;
    SubDerived sd;
    Base& b = d;
    Base& sb = sd;
    //d.f();
    sb.f();
    b.f();
}