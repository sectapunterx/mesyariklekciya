//
// Created by Fin on 22.12.2023.
//
#include "iostream"

template<typename T>
std::remove_reference_t<T>&& move(T& x) { // TODO: fix
  return static_cast<std::remove_reference_t<T>&&>(x);
}

template<typename T>
void swap(T& a, T& b){
  T tmp = std::move(a);
  a = std::move(b);
  b = std::move(tmp);
}

struct S {
    void f() &{
      std::cout << "1" << std::endl;
    }
    void f() && {
      std::cout << "2" << std::endl;
    }
};

int main(){
  S s;
  s.f();

  S().f();
}