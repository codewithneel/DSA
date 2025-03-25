#include "arraystack.h"
#include <iostream>

int main(){
    ArrayStack stack;
    stack.push(99);
    stack.push(-145);
    stack += 77777777;

    std::cout << stack << '\n';
}