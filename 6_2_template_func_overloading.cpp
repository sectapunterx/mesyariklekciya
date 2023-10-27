//
// Created by Fin on 27.10.2023.
// 6.2 Template function overloading
#include "iostream"

template <typename T, typename U>
void f(T t, U u) {
    std::cout << 1;
}
void f(int x, int y){
    std::cout << 2;
}
void f(int x, double y){
    std::cout << 3;
}

int main(){
    f(1, 1); // 2
    f(1, 1.2); // 3
}