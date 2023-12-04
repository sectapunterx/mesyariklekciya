// Created by Fin on 04.12.2023.
//8.3 internals of vector
#include "iostream"
#include "cstdint"
//#include "vector"

template<typename T>
class vector{
private:
    T* arr;
    size_t sz;
    size_t cap;
public:
    size_t size() const;
    void resize(size_t new_size);

    size_t capacity() const;
    void reserve(size_t new_cap){
        if(new_cap <= cap){
            return;
        }
        T* newarr = reinterpret_cast<T*>(new uint8_t[new_cap * sizeof(T)]); //TODO: avoid reinterpret_cast
        for(size_t i = 0; i < sz; ++i){
            try{
                new(newarr + i) T(std::move(arr[i])); //TODO: avoid copy
            } catch (...){
                for(size_t j = 0; j < i; ++j){
                    (newarr + j)->~T();
                }
                delete[] reinterpret_cast<uint8_t*>(newarr);
                throw;
            }
        }
        for(size_t i = 0; i < sz; ++i){
            (arr+i)->~T();
        }
        delete[] reinterpret_cast<uint8_t*>(arr);
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

int main(){

}