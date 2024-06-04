#include <iostream>
#include <memory>
#include <type_traits>
//MVP - Minimum Viable Product

//12.5 custom deleter and allocator problem

//12.6 enable_shared_from_this
//!!!!!!!! PSEUDOCODE !!!!!!!!!!!!!!!!!!!!!!!


template<typename T, typename Deleter = std::default_delete<T>, typename Allocator = std::allocator<T>> // WRONG
//template<typename T>
class shared_ptr {
private:
    template<typename ...Args>
    friend shared_ptr<T> make_shared(Args&& ... args);

    //T* ptr;
    //size_t* count;
    struct Control_block {
        T object;
        size_t shared_count;
        size_t weak_count;
        Deleter del;
        Allocator alloc;
    };
    Control_block* cb;

    shared_ptr(Control_block* pc);

public:
    shared_ptr(T* ptr) : ptr(ptr), count(new size_t(1)) {
      if constexpr (std::is_base_of_v<enable_shared_from_this<T>, T>) {
        ptr->wp = *this;
      }
    }

    shared_ptr(const shared_ptr& other) noexcept: ptr(other.ptr), count(other.count) {
      ++*count;
    }

    shared_ptr(const shared_ptr&& other) noexcept: ptr(other.ptr), count(other.count) {
      other.ptr = nullptr;
      other.count = nullptr;
    }

    //assignment operators
    ~shared_ptr() { // TODO: what if created by make_shared?
      if (!cb) return;
      --cb->shared_count;
      if (cb->weak_count == 0 && cb->shared_count == 0) {
        delete cb;
        return;
      }
      if (cb->shared_count == 0) {
        cb->object.~T();
      }
    }
};

template<typename T>
class unique_ptr {

};

template<typename T>
class weak_ptr {
    struct ControlBlock {
        T object;
        size_t shared_count;
        size_t weak_count;
    };
    T* ptr;
    size_t* count;
    ControlBlock* cb;
public:
    bool expired() const {
      return cb && cb->shared_count == 0;
    }

    ~weak_ptr() {
      if (!cb) return;
      --cb->weak_count;
      if (cb->weak_count == 0 && cb->shared_count == 0) {
        //dealloc, not destroy!!!!!!!!!!!!!!!

      }
    }
};

//12.3 make_shared && make_unique

template<typename T, typename... Args>
unique_ptr<T> make_unique(Args&& ... args) {
  return unique_ptr<T>(new T(std::forward<Args>(args)...)); // Universalnaya ssilka (unique reference)
}

template<typename T, typename Alloc, typename... Args>
auto allocate_shared(Alloc& alloc, Args&& ... args) {
  // ???
}

template<typename T, typename... Args>
shared_ptr<T> make_shared(Args&& ... args) {
  //return shared_ptr<T>(new T(std::forward<Args>(args)...));
  return allocate_shared<T>(std::allocator<T>(), std::forward<Args>(args)...);
}

//12.6

template<typename T>
struct enable_shared_from_this{
  std::weak_ptr<T> wp;

  std::shared_ptr<T> shared_from_this() const{
    return wp.lock();
  }
};

class S: public enable_shared_from_this<S> { //CRTP (Curiously recurring template pattern) - nasledie ot sebya samogo
public:
    std::shared_ptr<S> get_this(){ return shared_from_this(); }
};

int main() {

}

