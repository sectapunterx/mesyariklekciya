//
// Created by Fin on 22.12.2023.
//
#include "iostream"

template<typename T, typename Alloc = std::allocator<T>>
class vector {
private:
    T* arr;
    size_t sz;
    size_t cap;
    Alloc alloc;

    using AllocatorTraits = std::allocator_traits<Alloc>;
public:
    void reserve(int);

    template<typename ... Args>
    void emplace_back(Args&& ... args) { //universal reference
      if (sz >= cap) {
        reserve(cap * 2);
      }
      AllocatorTraits::construct(alloc, arr + sz, std::forward<Args>(args)...); //placement new
      ++sz;
    }

};
