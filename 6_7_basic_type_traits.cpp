//
// Created by Fin on 07.11.2023.
//6.7 Basic type traits

#include <iostream>
#include <type_traits>
#include "boost/array.hpp"

//metafunction - структура, которая ведет себя как функция и позволяет узнавать про типы на этапе компиляции

template <int N>
struct Fibbonaci {
    static const int value = Fibbonaci<N-1>::value + Fibbonaci<N-2>::value;
};

template<>
struct Fibbonaci<1>{
    static const int value = 1;
};

template<>
struct Fibbonaci<0>{
    static const int value = 0;
};

template <typename U, typename V>
struct is_same{
    static const bool value = false;
};
template <typename U>
struct is_same<U, U>{
    static const bool value = true;
};

template <typename T>
struct remove_const{
    using type = T;
};

template <typename T>
struct remove_const<const T>{
    using type = T;
};

template <typename U, typename V>
void f(U x, V y){
    typename remove_const<U>::type a;
    //...
    if(is_same<U, V>::value){
        //...
    }
}

template <typename T>
class C{
    C() = delete;
};

int main(){
    //C<std::decay<int*[10][10]>::type> x;
    std::cout << Fibbonaci<30>::value;
}