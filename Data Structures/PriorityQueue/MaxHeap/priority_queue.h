#ifndef _priority_queue_h
#define _priority_queue_h

// max heap implementation using an array
class PriorityQueue{
public:
    //constructor, destructor
    PriorityQueue();
    ~PriorityQueue();

    //member functions:
    /* insert element to the heap, time complexity O(logn) */
    void enqueue(int val);

    /* remove and return element with highest priority, time complexity O(logn) */
    int dequeue();

    /* return element with highest priority, time complexity O(1) */
    int peek() const;

    int size() const;
    bool isEmpty() const;

private:
    //member functions
    int* elements;
    int length; 
    int capacity;

    /* Time complexity: O(n) */
    void resize();
    void swap(int parentIndex, int childIndex);
};

// enqueue
void operator +=(PriorityQueue& pq, int val);
//dequeue
void operator --(PriorityQueue& pq);

#endif