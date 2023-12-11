// Created by Fin on 11.12.2023.
//9.1 idea and basic usage of allocators
//allocator - object that manages memory
#include "iostream"
#include "cstdint"

template<typename T, typename Alloc = std::allocator<T>>
class vector{
private:
    T* arr;
    size_t sz;
    size_t cap;
    Alloc alloc;
public:
    size_t size() const;
    void resize(size_t new_size);

    size_t capacity() const;
    void reserve(size_t new_cap){
        if(new_cap <= cap){
            return;
        }
        //T* newarr = reinterpret_cast<T*>(new uint8_t[new_cap * sizeof(T)]); //TODO: avoid reinterpret_cast
        T* newarr = alloc.allocate(new_cap);
        for(size_t i = 0; i < sz; ++i){
            try{
                //new(newarr + i) T(std::move(arr[i])); //TODO: avoid copy
                alloc.construct(newarr + i, std::move(arr[i]));
            } catch (...){
                for(size_t j = 0; j < i; ++j){
                    //(newarr + j)->~T();
                    alloc.destroy(newarr + j);
                }
                //delete[] reinterpret_cast<uint8_t*>(newarr);
                alloc.deallocate(newarr, new_cap);
                throw;
            }
        }
        for(size_t i = 0; i < sz; ++i){
            (arr+i)->~T();
        }
        //delete[] reinterpret_cast<uint8_t*>(arr);
        alloc.deallocate(newarr, new_cap);
        cap = new_cap;
        arr = newarr;
    }

    void push_back(const T& value){
        if(sz >= cap){
            reserve(cap*2);
        }
        new(arr + sz) T(value); //placement new
        //TODO: exception safety
        ++sz;
    }

    void pop_back(){
        --sz;
        (arr + sz)->~T();
    }

};

template<>
class vector<bool>{
private:
    uint8_t *arr;
    size_t sz;
    size_t cap;

    struct BitReference{
        uint8_t *cell;
        uint8_t bit;

        BitReference& operator=(bool b){
            //set corresponding bit in cell to b
            return *this;
        }
        operator bool() const{
            return *cell & (1 << bit);
        }
        BitReference& operator=(const BitReference&) = default;
    };
public:
    BitReference operator[](size_t index){
        return {arr+index/8, static_cast<uint8_t>(index % 8)};
    }

};

int main(){
    //vector<bool> v;
    //v[2] = true; // assignment to rvalue

    //vector<int>::iterator it = v.begin();

}