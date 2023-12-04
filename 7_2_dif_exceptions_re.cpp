// Created by Fin on 29.11.2023.
// 7.2 Difference between exceptions and runtime errors
#include "vector"
#include "iostream"
int main(){
    try {
        std::vector<int> v(10); //RE не только exception, но и error
        //v[100'000] = 1; //RE - программа падает на уровне ОС
        v.at(100'000) = 2; //exception - программа падает на уровне С++
                            //std::out_of_range - исключение, которое бросается в случае выхода за границы вектора
    } catch (...){
        std::cout << "Exception" << std::endl;
    }
}