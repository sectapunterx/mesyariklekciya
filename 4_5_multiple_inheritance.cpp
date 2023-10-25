// Created by Fin on 11.10.2023.
//4.5 Multiple inheritance.

#include <iostream>
//include clipp from vcpkg



struct Mother {
    int m = 1;
};

struct Father {
    int f = 2;
};

struct Son: public Father, public Mother {
    int s = 3;
};

int main(){
    Father f;

    std::cout << reinterpret_cast<Son&>(f).f << std::endl;
}
