#include "iostream"
#include "vector"

// Created by Fin on 26.12.2023.
// 11. Type deduction
// 11.1 auto keyword (since C++11)

int main(){
  const auto& x = 5;

  int i = 1;
  auto&& y = i; // universal reference

  std::vector<bool> v (5, false);
  for(size_t it = 0; it < v.size(); ++it){
    std::cout << v[i] << std::endl;
  }
}
