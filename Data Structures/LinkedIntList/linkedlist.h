#ifndef _linkedlist_h
#define _linkedlist_h

#include "list_node.h"
#include <iostream>

class LinkedList{
public:
    LinkedList();
    ~LinkedList();

    //member functions 
    void add(int value);
    void addFront(int value);
    int get(int index) const; 
    void insert(int index, int value);
    bool isEmpty() const; 
    void removeFront();
    void removeBack();
    void remove(int index);
    int length() const;

    //declared as 'friend' so it can access private front variable
    friend std::ostream& operator <<(std::ostream& out, const LinkedList& list);

private:
    ListNode* front;
    int size;

    // void addHelper(ListNode*& node, int value);

};

std::ostream& operator <<(std::ostream& out, const LinkedList& list);


#endif