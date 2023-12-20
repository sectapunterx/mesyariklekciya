// Created by Fin on 18.12.2023.
//9.4 new and delete overload
#include "iostream"
#include "vector"
#include "cstdlib"

void* operator new(size_t n){
  std::cout << "Allocating " << n << " bytes\n";
  void* ptr = std::malloc(n);
  if(!ptr){
    throw std::bad_alloc();
  }
  return ptr;
}

void operator delete(void* ptr) noexcept{
  std::cout << "Deallocating\n";
  std::free(ptr);
}

int main(){
  std::vector<int> v(5);
  for(int i = 6; i < 100; ++i){
    v.push_back(i);
  }
}