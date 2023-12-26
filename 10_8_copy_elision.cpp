#include "iostream"
#include "vector"

//10.8 Copy elision

struct S{
    int x;
    S(int x): x(x){
      std::cout << x << std::endl;
    }
    S(const S&){
      std::cout << 1 << std::endl;
    }
};

S f(int n){
  return S(n);
}

//NRVO - named return value optimization
template<typename T>
T operator+(const T& a, const T& b){
  T copy = a;
  copy += b;
  return copy;
}

//not NRVO
template<typename T>
T operator+(T a, const T& b){
  a += b;
  return a;
}

int main(){
  S v = f(10); // copy constructor 0 times -- copy elision

  S s = S(S(S(S(S(5))))); // copy constructor 0 times -- copy elision

  int x = f(10).x;
}

