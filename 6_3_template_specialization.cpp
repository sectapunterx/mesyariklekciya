//
// Created by Fin on 27.10.2023.
// 6.3 Template specialization
#include <iostream>

template <typename T, typename U>
struct S {
    void f(){
        std::cout << 1;
    }
};

//full explicit specialization
template <>
struct S<int, int> {
    void f(){
        std::cout << 2;
    }
};

//partial specialization
template <typename T>
struct S<T, T> {
    void f(){
        std::cout << 3;
    }
};

template <typename T, typename U = int>
void f(T, U){
    std::cout << 1;
}

template <>
void f(int, int){
    std::cout << 3; // Специализация "прицепилась" к тому что выше (частная специализация от T, U)
}

template <typename T>
void f(T, T){
    std::cout << 2;
}


int main(){
    f(0, 0); // 2
}

