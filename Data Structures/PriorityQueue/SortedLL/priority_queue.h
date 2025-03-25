#ifndef _priority_queue_h
#define _priority_queue_h

#include "list_node.h"

class PriorityQueue{
public:
    PriorityQueue();
    ~PriorityQueue();

    //member functions
    void enqueue(int val);
    int dequeue();
    int peek() const;
    int size() const;
    bool isEmpty() const;

private:
    //member variables
    ListNode* front;
    int length;
};

void operator +=(PriorityQueue& pq, int val);

#endif