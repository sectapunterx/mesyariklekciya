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

void* operator new(size_t n, const std::nothrow_t&) noexcept{
  std::cout << "Allocating " << n << " bytes non-throwing\n";
  void* ptr = std::malloc(n);
  return ptr;
}

//PLACEMENT NEW NOT OVERLOADABLE
/*void* operator new(size_t n, void* ptr) noexcept{
  std::cout << "Placement new" << n << " bytes\n";
  return ptr;
}*/

void operator delete(void* ptr) noexcept{
  std::cout << "Deallocating\n";
  std::free(ptr);
}

struct S{
    static void* operator new(size_t n){
      std::cout << "Allocating " << n << " bytes for S\n";
      void* ptr = std::malloc(n);
      if(!ptr){
        throw std::bad_alloc();
      }
      return ptr;
    }

    static void operator delete(void* ptr) noexcept{
      std::cout << "Deallocating for S\n";
      std::free(ptr);
    }
};

int main(){
 /* int* p = new(std::nothrow) int(5);
  delete p;*/
  S* p = new S();
  delete p;

  std::vector<S> v(5);
  for(int i = 6; i < 100; ++i){
    v.push_back(S());
  }
}