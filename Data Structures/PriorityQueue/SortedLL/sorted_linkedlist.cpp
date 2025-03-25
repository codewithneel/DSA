#include "priority_queue.h"
#include "list_node.h"
#include <stdexcept>
#include <iostream>

PriorityQueue::PriorityQueue(){
    front = nullptr;
    length = 0;
}

PriorityQueue::~PriorityQueue(){
    //destroy linkedlist
    while(front != nullptr){
        ListNode* trash = front;
        front = front->next;
        // std::cout << trash->data << '\n';
        delete trash;
    }
    // std::cout << "LL destroyed \n";

}

//member functions

/* Time Complexity: O(n) */
void PriorityQueue::enqueue(int val){
    length++;
    if(front == nullptr){
        //list is empty
        front = new ListNode{val, nullptr};
    } else if(val > front->data){
        /*val is the highest priority
         *front -> 9 -> 5 -> 4, insert 10
         *front -> 10 -> 9 -> ...
         */
        front = new ListNode{val, front};
    } else {
        ListNode* prev = front;
        ListNode* current = front->next;
        while(current != nullptr){
            if(val > current->data){
                prev->next = new ListNode{val, current};
                return;
            }
            prev = current;
            current = current->next;
        }
        //val is the lowest priority, append to the end of list
        prev->next = new ListNode{val, nullptr};
    }
}

/* Time complexity: O(1) */
int PriorityQueue::dequeue(){
    if(front == nullptr){
        //list is empty
        throw std::runtime_error("Priority Queue is empty!");
    }
    ListNode* trash = front;
    int out = trash->data;
    front = front->next;
    delete trash;
    length--;
    return out;
}

int PriorityQueue::peek() const{
    if(front == nullptr){
        //list is empty
        throw std::runtime_error("Priority Queue is empty!");
    }
    return front->data;
}

int PriorityQueue::size() const{
    return length;
}

bool PriorityQueue::isEmpty() const{
    return length == 0; 
}

void operator +=(PriorityQueue& pq, int val){
    pq.enqueue(val);
}