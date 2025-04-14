#include "linkedlist.h"
#include "list_node.h"
#include <iostream>
#include <string>
#include <stdexcept>

LinkedList::LinkedList(){
    front = nullptr;
    size = 0; 
}

LinkedList::~LinkedList(){
    //delete all ListNodes in linkedlist
    while(front != nullptr){
        ListNode* trash = front; 
        front = front->next; 
        delete trash;
    }
}

// Append element to the end of the list
void LinkedList::add(int value){
    if(front == nullptr){ 
        //list is empty
        front = new ListNode{value, nullptr};
    } else { 
        //non-empty list
        ListNode* current = front; 
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = new ListNode{value, nullptr};
    }
    size++;
}

// void LinkedList::add(int value){
//     addHelper(front, value);
// }

// void LinkedList::addHelper(ListNode*& node, int value){
//     if(node == nullptr){
//         node = new ListNode{value, nullptr};
//         size++;
//     } else {
//         addHelper(node->next, value);
//     }
// }

void LinkedList::addFront(int value){
    // if(front == nullptr){ 
    //     front = new ListNode{value, nullptr};
    // } else {
    //     ListNode* temp = new ListNode{value, front};
    //     front = temp;
    // }

    //shorthand
    front = new ListNode{value, front};
    size++; 
}

int LinkedList::get(int index) const{
    if(index >= size || index < 0){
        //throw exception: index out of bounds
        throw std::out_of_range("Index is out of bounds!");
    } 
    ListNode* current = front;
    int counter = 0; //represents current index
    while(current != nullptr){
        if(counter == index){
            return current->data;
        }
        counter++;
        current = current->next; 
    }
}

void LinkedList::insert(int index, int value){
    if(index > size || index < 0){
        //throw exception: index out of bounds
        throw std::out_of_range("Index is out of bounds!");
    } else if(index == size){ 
        //append to end
        //satisfies empty list case: index = 0 and mem variable size = 0 
        add(value);
    } else {
        if(index == 0){  
            //non-empty list: index 0 insertion
            addFront(value);
            return;
        }

        ListNode* prev = front;
        ListNode* current = front->next;
        int counter = 1; 

        while(current != nullptr){
            if(counter == index){
                prev->next = new ListNode{value, current};
                size++; 
                break;
            }
            counter++;
            prev = current; 
            current = current->next;
        } 
    }
}

bool LinkedList::isEmpty() const{
    return size == 0; 
}

void LinkedList::removeFront(){
    if(front == nullptr){
        //empty list, throw exception
        throw std::runtime_error("List is empty!");
    } else{
        //non-empty list
        ListNode* trash = front; 
        front = front->next; 
        delete trash;
        size--; 
    }
}

void LinkedList::removeBack(){
    if(front == nullptr){
        //empty list, throw exception
        throw std::runtime_error("List is empty!");
    } else if(front->next == nullptr){ 
        //list consists of one node
        removeFront();
    } else {
        //list consists of 2 or more nodes
        ListNode* prev = front;
        ListNode* current = front->next;
        while(current->next != nullptr){
            prev = current; 
            current = current->next;
        }
        prev->next = nullptr;
        delete current;
        size--; 
    }
}

void LinkedList::remove(int index){
    if(index >= size || index < 0){
        //throw exception
        throw std::out_of_range("Index is out of bounds!");
    } else if(index == 0){
        removeFront();
    } else {
        int counter = 1; //represents current index 
        ListNode* current = front->next; 
        ListNode* prev = front;
        
        while(current != nullptr){
            if(index == counter){
                prev->next = current->next;
                delete current;
                size--; 
                return; 
            }
            counter++; 
            prev = current; 
            current = current->next; 
        }
    }
}

int LinkedList::length() const{
    return size; 
}

std::ostream& operator <<(std::ostream& out, const LinkedList& list){
    ListNode* current = list.front; 
    out << "{";
    while(current != nullptr){
        out << std::to_string(current->data) << " ";
        current = current->next; 
    }
    out << "}";
    return out; 
}