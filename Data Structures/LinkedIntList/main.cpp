#include "linkedlist.h"
#include <iostream>

int main(){
    LinkedList list; 
    // list.removeFront();
    // list.removeBack();
    // list.remove(0);
    list.insert(0, 1000); //{1000}
    list.removeBack(); //{}
    list.add(70); // {70}
    // list.remove(0);
    list.addFront(66); //{66, 70}
    list.insert(0, 2939); //{2939, 66, 70}
    list.removeFront(); //{66, 70}
    list.add(7777); //{66, 70, 7777}
    list.add(5000); //{66, 70, 7777, 5000}
    list.addFront(2030023); //{2030023, 66, 70, 7777, 5000}
    list.insert(5, 10); //{2030023, 66, 70, 7777, 5000, 10}
    // list.removeBack();
    // list.remove(0);
    std::cout << list << '\n';
    std::cout << list.length() << '\n';

    // LinkedList l2; 
    // l2.add(19);
    // l2.add(51);
    // l2.add(91);
    // l2.add(77777);
    // std::cout << l2 << '\n';
    // std::cout << l2.length() << '\n';

}
