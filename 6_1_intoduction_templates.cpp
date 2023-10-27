//
// Created by Fin on 27.10.2023.
//6.1 General idea, basic syntax
#include <iostream>
#include <map>

/*int max (int a, int b){
    return a > b ? a : b;
}
int max (double a, double b){
    return a > b ? a : b;
}
std::string max (const std::string& a, const std::string& b){
    return a > b ? a : b;
}*/

template <typename T>
T maximum (T a, T b){
    return a > b ? a : b;
}
template <typename T>
class S{
    template<typename U>
    void f(U u){
        std::cout << u;
    }
};
template <typename T>
using mymap = std::map<T, T>;

template <typename T>
const T pi = 3.1415926535897932385;



int main(){
    mymap<int> m;

    std::cout << maximum(1, 2) << std::endl;
    std::cout << maximum(1.0, 2.0) << std::endl;
    //std::cout << max(S(), S()) << std::endl; // error: no match for 'operator>' (operand types are 'S' and 'S')
}