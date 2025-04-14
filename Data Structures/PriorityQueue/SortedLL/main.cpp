#include <iostream>
#include "priority_queue.h"

int main(){
    PriorityQueue pq;
    pq+=5;
    pq.enqueue(9);
    std::cout << "Peek-a-boo: "<< pq.peek() << '\n';
    pq+=4;
    pq.enqueue(6);
    std::cout << "Size: " << pq.size() << '\n';
    while(!pq.isEmpty()){
        std::cout << "Element dequeued: " << pq.dequeue() << '\n';
    }
    std::cout << "Size: " << pq.size() << '\n';
}