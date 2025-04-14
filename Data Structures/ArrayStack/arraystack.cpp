#include "arraystack.h"
#include <string>
#include <stdexcept>

ArrayStack::ArrayStack(){
    capacity = 10;
    length = 0; 
    elements = new int[capacity](); // () initializes all of the indices to 0
}

ArrayStack::~ArrayStack(){
    // code you want to run as the stack is being destroyed
    delete[] elements;
}

void ArrayStack::push(int n){
    if(length + 1 > capacity) resize(); // out of space
    elements[length] = n;
    length++;
}

int ArrayStack::pop(){
    // return *(elements + (--length));
    if(length == 0){
        // throw exception
        throw std::runtime_error("Stack is empty!");
    }
    int result = elements[length - 1]; 
    elements[length - 1] = 0;
    length--;
    return result;

}

int ArrayStack::peek() const{
    if(length == 0){
        // throw exception
        throw std::runtime_error("Stack is empty!");
    }
    return elements[length - 1];
}

int ArrayStack::size() const{
    return length;
}

bool ArrayStack::isEmpty() const{
    return length == 0;
}

std::string ArrayStack::toString() const{
    std::string output = "{";
    for(int i = length - 1; i >= 0; i--){
        output += " " + std::to_string(elements[i]);
    }
    return output + "}";
}

void ArrayStack::resize(){
    capacity *= 2; 
    int* temp = new int[capacity]();
    for(int i = 0; i < length; i++){
        temp[i] = elements[i];
    }
    delete[] elements; 
    elements = temp;
}

void operator +=(ArrayStack& stack, int n){
    stack.push(n);
}

std::ostream& operator <<(std::ostream& out, ArrayStack& stack){
    out << stack.toString();
    return out;
}