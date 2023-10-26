//
// Created by Fin on 26.10.2023.
//
//5.3 Abstract classes and pure virtual functions
#include <iostream>

class Shape { // abstract class because of pure virtual function
    public:
    virtual double area() const = 0; // pure virtual function because of "= 0"
};
class Square: public Shape {
    public:
    double area() const override {
        return 0.0;
    }
};

int main(){
    Square s;
    Shape& ss = s;
    ss.area();
}
