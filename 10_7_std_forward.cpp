// Created by Fin on 26.12.2023.
//
#include "iostream"
#include "cstdint"


template <typename T>
T&& forward(std::remove_reference_t<T>& x){
  static_cast<T&&>(x);
}

template <typename T>
T&& forward(std::remove_reference_t<T>&& x){
  static_cast<T&&>(x);
}

template<typename T>
std::remove_reference_t<T>&& move(T&& x) { // universal reference
  return static_cast<std::remove_reference_t<T>&&>(x);
}

template<typename T, typename Alloc = std::allocator<T>>
class vector {
private:
    T* arr;
    size_t sz;
    size_t cap;
    Alloc alloc;

    using AllocatorTraits = std::allocator_traits<Alloc>;
public:

    vector(const vector& other);

    vector& operator=(const vector& other);

    //TODO: WTF is vector&& other
    vector(vector&& other) noexcept(noexcept(alloc(std::move(other.alloc)))): arr(other.arr), sz(other.sz),
                                                                              cap(other.cap),
                                                                              alloc(std::move(other.alloc)) {
      other.arr = nullptr;
      other.sz = 0;
      other.cap = 0;
    }

    vector& operator=(vector&& other) noexcept(noexcept(alloc(std::move(other.alloc)))) {
      if (this == &other) {
        return *this;
      }
      for (size_t i = 0; i < sz; ++i) {
        (arr + i)->~T();
      }
      alloc.deallocate(arr, cap);
      arr = other.arr;
      sz = other.sz;
      cap = other.cap;
      alloc = std::move(other.alloc);

      other.arr = nullptr;
      other.sz = 0;
      other.cap = 0;
      return *this;
    }

    size_t size() const;

    void resize(size_t new_size);

    size_t capacity() const;

    void reserve(size_t new_cap) {
      if (new_cap <= cap) {
        return;
      }
      //T* newarr = reinterpret_cast<T*>(new uint8_t[new_cap * sizeof(T)]); //TODO: avoid reinterpret_cast
      T* newarr = AllocatorTraits::allocate(alloc, new_cap);
      for (size_t i = 0; i < sz; ++i) {
        try {
          //new(newarr + i) T(std::move(arr[i])); //TODO: avoid copy
          //alloc.construct(newarr + i, std::move(arr[i]));
          AllocatorTraits::construct(alloc, newarr + i, std::move(arr[i]));
        } catch (...) {
          for (size_t j = 0; j < i; ++j) {
            //(newarr + j)->~T();
            //alloc.destroy(newarr + j);
            AllocatorTraits::destroy(alloc, newarr + j);
          }
          //delete[] reinterpret_cast<uint8_t*>(newarr);
          //alloc.deallocate(newarr, new_cap);
          AllocatorTraits::deallocate(alloc, newarr, new_cap);
          throw;
        }
      }
      for (size_t i = 0; i < sz; ++i) {
        (arr + i)->~T();
      }
      //delete[] reinterpret_cast<uint8_t*>(arr);
      AllocatorTraits::deallocate(alloc, newarr, new_cap);
      cap = new_cap;
      arr = newarr;
    }

    void push_back(const T& value) {
      emplace_back(value);
    }

    void push_back(T&& value) {
      emplace_back(std::move(value));
    }

    void pop_back() {
      --sz;
      (arr + sz)->~T();
    }

    template<typename ... Args>
    void emplace_back(const Args&& ... args) {
      if (sz >= cap) {
        reserve(cap * 2);
      }
      AllocatorTraits::construct(alloc, arr + sz, args...); //placement new
      ++sz;
    }

};

template<>
class vector<bool> {
private:
    uint8_t* arr;
    size_t sz;
    size_t cap;

    struct BitReference {
        uint8_t* cell;
        uint8_t bit;

        BitReference& operator=(bool b) {
          //set corresponding bit in cell to b
          return *this;
        }

        operator bool() const {
          return *cell & (1 << bit);
        }

        BitReference& operator=(const BitReference&) = default;
    };

public:
    BitReference operator[](size_t index) {
      return {arr + index / 8, static_cast<uint8_t>(index % 8)};
    }

};

int main() {
  vector<bool> v;
  v[2] = true; // assignment to rvalue

  //vector<int>::iterator it = v.begin();

}
