#include <map>
#include "iostream"
#include "vector"

// Created by Fin on 26.12.2023.
// 11. Type deduction
// 11.1 auto keyword (since C++11)

//11.2 decltype(c++11)


template <typename Container>
decltype(auto) getByIndex(Container& cont, size_t index){
  std::cout << 1 << std::endl;
  return cont[index];
}


int main(){
  std::map <int, std::string > m;
  m[1] = "abc";
  m[3] = "aaa";

  int a = 5;
  decltype(a) b; // compile time

  std::vector<int> v = {1, 2, 3};
  getByIndex(v, 1) = 0; // v[1] = 0;

}
