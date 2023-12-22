// Created by Fin on 21.12.2023.
// 10. Move semantics and rvalue references
// 10.1 Motivation of move semantics
#include "iostream"
#include "vector"

template<typename T>
void swap(T& a, T& b){
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

template<typename T>
T operator+(T a, const T& b){
    a += b;
    return std::move(a);
}

int main(){
  std::string s = "Hello";
  throw s; // since c++11 throw is std::move by default

  std::vector<std::string> v;
  v.push_back("Hello"); // push_back is std::move by default

  v.emplace_back("Hello"); // doesnt create a temporary object

}
