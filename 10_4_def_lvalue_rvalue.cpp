// Created by Fin on 22.12.2023.

/*
1. lvalue and rvalue are properties of expressions, not objects
2. rvalue reference does not mean that the object is rvalue (reference collapsing rules)

   Lvalue                 | Rvalue
* 1. identifier           | 1. literal
* -----------------------if not user defined-----------------------
* 2. binary + += = ...    | 2. binary + - * / % & | << >> < > == != <= >=
* 3. prefix ++ --         | 3. postfix ++ --
* 4. unary *              | 4. unary & ~ !
* 5. operator ? :         | 5. operator  ? :
  (if both lvalue)        |    (if <= 1 is rvalue)
                          |    (true ? ++x : x++) = 1; <- rvalue
                          |
* 6. operator ,           | 6. operator ,
  if right is lvalue      |    if right is rvalue
                          |
  * -----------------------if not user defined-----------------------
* 7. function call        | 7. function call
     (if return type T&)  |    (if return type T or T&&) | T&& is rvalue-reference
* 8. cast-expression      | 8. cast-expression
  <T&>                    |  <T> or <T&&>


 T& is lvalue-reference, T is no-reference, T&& is rvalue-reference

 reference collapsing rules:
  T& & -> T&
  T& && -> T&
  T&& & -> T&
  T&& && -> T&&

 */