// Created by Fin on 04.12.2023.
//8.2 Idea of iterator

//Input iterator <- Forwards iterator <- Bidirectional iterator <- Random access iterator <- (since c++17) contiguous iterator [vector, std::array, pointer]
//Input iterator: only forward, only 1 time
//Forwards iterator: only forward
//Bidirectional iterator: forward and backward
//Random access iterator: forward, backward, and random access [deque]
//Contiguous iterator: forward, backward, random access, and contiguous [&(*it)+1]
//TODO:
//         | []                | push_back/pop_back    | push_front/pop_front | find             | insert                | erase          | iterator level | iterator invalidation | pointer and reference invalidation|
//vector   | O(1)              | O(1) amort.           | -                    | O(n)             | O(n)                  | O(n)           | contiguous     | Yes                   | Yes                               |
//deque    | O(1)              | O(1) amort.           | O(1) amort           | O(n)             | O(n)                  | O(n)           | random access  | Yes                   | No                                |
//list     | -                 | O(1)                  | O(1)                 | O(n)             | O(1)                  | O(1)           | bidirectional  | No                    | No                                |
//set/map  | O(log_n)          | -                     | -                    | O(logn)          | O(log(n))             | O(log(n)       | bidirectional  | No                    | No                                |
//unordered| O(1) expected     | -                     | -                    | O(1) expected    | O(1) expected         | O(1) expected  | bidirectional  | Yes??                 | No                                |

#include <iterator>
#include "iostream"

template<typename iter>
void process(iter begin, iter end){
    //using iterator_category = std::bidirectional_iterator_tag;
    --end; //because end points to the next element after the last element (end+1)
    typename iter::value_type tmp = *begin;
    *begin = *end;
    *end = tmp;
    std::cout << std::is_same<typename std::iterator_traits<iter>::iterator_category, std::bidirectional_iterator_tag>::value;

}

int main(){
    int x;
    std::cin >> x;
    auto it = std::istream_iterator<int>(std::cin); //input iterator

}