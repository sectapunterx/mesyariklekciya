// Created by Fin on 11.12.2023.
// 8.7 internals of std::map
#include <map>
#include "iostream"
#include "gtest/gtest.h"

template<typename T>
struct less {
    bool operator()(const T& a, const T& b) const{
        return a < b;
    }
};

template <typename First, typename Second>
struct pair {
    First first;
    Second second;
};

template <typename Key, typename Value, typename Compare = std::less<Key>>
class map {
    using value_type = pair<const Key, Value>;
private:
    struct BaseNode{
        BaseNode* left;
        BaseNode* right;
        BaseNode* parent;
        bool red;
    };
    struct Node : BaseNode{
        value_type kv;
    };

    BaseNode* leftmost;
    BaseNode* root;
    Compare comp;
public:
    struct iterator{
        BaseNode* node;
        value_type& operator*() const{
            return static_cast<Node*>(node)->kv;
        }
    };
};

int main(){
    std::map<int, std::string> m;
    m[0] = "zero";
    m.insert({1, "one"});

    std::map<int, std::string>::iterator it = m.find(0);
    if(it != m.end()){
        std::cout << it->second;
    }



}