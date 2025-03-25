#include <iostream>
#include "priority_queue.h"

int main(){
    PriorityQueue pq;
    pq.enqueue(90);
    pq.enqueue(7777);
    pq.enqueue(7);
    pq.enqueue(1010);
    pq.enqueue(0);
    pq.enqueue(9999);
    pq.enqueue(10000);
    pq.enqueue(-55);
    pq.enqueue(7);
    pq.enqueue(77777);
    pq.enqueue(888);
    pq.enqueue(8787);

    while(!pq.isEmpty()){
        std::cout << pq.dequeue() << '\n';
    }
}