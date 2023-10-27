//
// Created by Fin on 26.10.2023.
//

//RTTI - Run Time Type Information
//5.5 RTTI and dynamic_cast
#include <iostream>

struct Granny{
    virtual void f() {
        std::cout << 1;
    };
    virtual ~Granny() = 0;
};
Granny::~Granny() = default;

struct Mother: public Granny{
    /*void f() override{
        std::cout << 2;
    }*/
};
struct Father: public Granny{
    /*void f() override{
        std::cout << 3;
    }*/
};
struct Son: public Mother, public Father{
    /*void f() override{
        std::cout << 4;
    }*/
};

int main(){
    Mother* pm = new Mother();
    dynamic_cast<Son*>(pm);
}