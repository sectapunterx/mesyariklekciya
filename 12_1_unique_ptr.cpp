// Created by Fin on 04.04.2024.
// 12.1 unique_ptr (since C++11)
//RAII - Resource Acquisition Is Initialization (26. 50:33 2022y)
#include <iostream>
#include <memory>

template<typename T>
struct def_del{
    void operator()(T* ptr) const{
      delete ptr;
    }
};

template<typename T, typename Deleter = std::default_delete<T>>
class unique_ptr {
  T* ptr;

public:
    unique_ptr(T* ptr) : ptr(ptr) {}

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr(const unique_ptr&& other) noexcept: ptr(other.ptr) {
      other.ptr = nullptr;
    }

    //assignment operator
    ~unique_ptr() {
      Deleter()(ptr);
    }
};

void f() {
  int* p = new int(5);

  auto pp = unique_ptr<int>(new int(5));

  delete p; // probably memory leak if:
            // 1. exception is thrown or
            // 2. lots of return statements
            // 3. TCP connection (handshake)
}
