#include <iostream>


//4.3 Constructors and Destructors calls order.
struct A {
    A () { std::cout << "A"; }
    ~A () { std::cout << "~A"; }
};
struct B {
    B () { std::cout << "B"; }
    ~B () { std::cout << "~B"; }
};
struct Base{
    int x = 0;
    A a;
    Base () { std::cout << "Base"; }
    explicit Base(int x) : x(x) { std::cout << "Base" << x; }
    ~Base () { std::cout << "~Base"; }
};
struct Derived: public Base{
    int y = 0;
    B b;
    Derived () { std::cout << "Derived"; }
    Derived (int x, int y): Base(x), y(y) { std::cout << "Derived" << x << y; }
    //TODO: Derived (int x, int y): y(y), Base(x) { } -- WARNING: the order of initialization is important!
    ~Derived () { std::cout << "~Derived"; }
};


int main() {
    //4.3 Constructors and Destructors calls order.
    Derived d(1,2);
}
