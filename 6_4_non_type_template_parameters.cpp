//
// Created by Fin on 28.10.2023.
//6.4 Non-type template parameters
#include <iostream>
#include "vector"

//int, size_t, char, bool, enum, pointer, reference, function, class
template <typename T, template<typename> class Container>
class Stack{
    Container<T> c;
public:

};
int main(){
    Stack<int, std::vector> s;
}
