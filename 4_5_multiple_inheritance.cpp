// Created by Fin on 11.10.2023.
//4.5 Multiple inheritance.

#include <iostream>

struct Mother {
    int m = 1;
};

struct Father {
    int f = 2;
};

struct Son: public Mother, public Father {
    int s = 3;
};

int main(){
    Son s;
    std::cout << &s << std::endl;

    Father* pf = &s;

    std::cout << pf << std::endl;
}
