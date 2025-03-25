#ifndef _arraystack_h
#define _arraystack_h

#include <string>
#include <iostream>


class ArrayStack{
public:
    /* Constructs a new stack. */
    ArrayStack();

    ~ArrayStack();

    // member methods

    /* Adds the given element on top of the stack. */
    void push(int n);

    /* Removes and returns the top element from the stack. */
    int pop();

    /* Returns the top element from the stack without removing it. */
    int peek() const;

    /* Returns the number of elements in the stack. */
    int size() const;

    /* Returns true if the stack contains no elements; otherwise, false. */
    bool isEmpty() const;

    std::string toString() const;

private:
    // member variables
    int* elements;
    int length;
    int capacity;

    void resize();

};

void operator +=(ArrayStack& stack, int n);
std::ostream& operator <<(std::ostream& out, ArrayStack& stack);


#endif