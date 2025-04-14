#ifndef _priority_queue_h
#define _priority_queue_h

class PriorityQueue{
public:
    //constructor, destructor
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
    int* elements;
    int capacity;
    int length;

    void resize();
};

//enqueue
void operator +=(PriorityQueue& pq, int val);

#endif