// Created by Fin on 20.12.2023.
// 9.5 Alignments
#include "iostream"

struct alignas(std::max_align_t) Pool { // alignas - aligns the struct to the max align
    char arr [100'000];
};


int main(){
  std::cout << alignof(double) << std::endl;
  std::cout << alignof(std::max_align_t) << std::endl;

}