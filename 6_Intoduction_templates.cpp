//
// Created by Fin on 27.10.2023.
//6.1 General idea, basic syntax
#include <iostream>

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
T max (T a, T b){
    return a > b ? a : b;
}
template <typename T>
class S{
    T a;
    T b;
};

int main(){
    std::cout << max(1, 2) << std::endl;
    std::cout << max(1.0, 2.0) << std::endl;
    std::cout << max(std::string("1"), std::string("2")) << std::endl;
    //std::cout << max(S(), S()) << std::endl; // error: no match for 'operator>' (operand types are 'S' and 'S')
}