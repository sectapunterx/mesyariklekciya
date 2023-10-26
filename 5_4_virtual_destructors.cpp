//
// Created by Fin on 26.10.2023.
//
// 5.4 Virtual destructor problem
#include <iostream>

struct GrandBase{
    virtual void f() = 0;
    virtual ~GrandBase() = 0;
};
GrandBase::~GrandBase() = default;

struct Base: public GrandBase{
    int* a = new int();
    void f() override{
        std::cout << "Base";
    }
    ~Base() override{
        delete a;
        std::cout << "~Base";
    }
};
struct Derived: public Base{
    int* b = new int();
    ~Derived() override{
        delete b;
        std::cout << "~Derived";
    }
};

int main(){
    GrandBase* b = new Derived();
    delete b;
}


