// Created by Fin on 29.11.2023.
//7.1 Basic idea and usage examples
#include "iostream"

int f(int a, int b){
    int* p = new(std::nothrow) int[100000]; // nothrow - не бросать исключение, а вернуть nullptr
    if (b == 0){
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}
int main() {
    int x;
    int y;
    std::cin >> x >> y;
    try {
        std::cout << f(x, y) << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;

}