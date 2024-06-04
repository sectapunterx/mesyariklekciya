// Created by Fin on 04.06.2024.
// XIII. Lambda functions and elements of functional programming
//13.1 Idea and basic usage of lambda functions (since C++11)
//13.2 Capture lists

#include <algorithm>
#include <set>
#include "iostream"
#include "vector"

struct Compare {
    bool operator()(int x, int y) const noexcept {
      return x < y;
    }
};

struct S {
    int a = 5;

    auto get_function() {
      auto f = [a = a](int x) {
          return x + a;
      };
      return f;
    }

};

int main(){

  S xx{5};
  auto ff = xx.get_function();
  std::cout << ff(10);

  return 0;
  std::vector<int> v = {3, 6, 5, 12, 7};

  int m = 5;
  int count = 0;
  std::string s = "abcde";
  //functor
  auto f = [=, &count, s = std::move(s), mid = std::cref(m)](int x, int y) mutable { // [=], [&], [=, &count]
    ++count;
    std::cout << count << '\n';
    return std::abs(x - m) < std::abs(y - m);
  };
  //std::sort(v.begin(), v.end(), Compare());

  /*std::sort(v.begin(), v.end(), [](int x, int y) {
      return x < y;
  });*/

  std::sort(v.begin(), v.end(), f);

  //std::set<int, decltype(f)> s(f);

  for(auto x: v){
    std::cout << x << ' ';
  }

}
