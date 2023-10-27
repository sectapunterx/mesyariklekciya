//
// Created by Fin on 27.10.2023.
// 6.2 Template function overloading
#include "iostream"

template <typename T>
void f(T& t) {
    std::cout << 1;
}
template <typename T>
void f(const T& t){
    std::cout << 2;
}

int main(){
    int x = 0;
    const int& y = x;
    f(y);
}