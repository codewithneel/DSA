#include "priority_queue.h"
#include <iostream>

int main(){
    PriorityQueue pq;
    // pq.dequeue();
    pq+= 778;
    pq.enqueue(-34);
    pq.enqueue(7777);
    pq+= 1001;
    pq.enqueue(57);

    while(!pq.isEmpty()){
        std::cout << pq.dequeue() << '\n';
    }

}