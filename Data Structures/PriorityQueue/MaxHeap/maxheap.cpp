#include "priority_queue.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

//constructor
PriorityQueue::PriorityQueue(){
    length = 0;
    capacity = 10;
    elements = new int[10]();
}

//destructor
PriorityQueue::~PriorityQueue(){
    delete[] elements;
}

/* insert element to the heap, time complexity O(logn) */
void PriorityQueue::enqueue(int val){
    //if the array is full, resize
    if(length + 1 > capacity) resize();

    /* Append element to end of list, before bubbling up. 
     * elements will be stored from indices 0 to (length-1) 
     */
    elements[length] = val;

    /* Bubble up until current element is at the root, or 
     * the parent of the curr element is of higher priority.
     * Time complexity: log(n) or log(h), h = height of tree
     */
    int index = length;
    int parentIndex = (int)std::ceil((index/(double)2)) - 1;
    while(index != 0 && elements[parentIndex] < elements[index]){
        swap(parentIndex, index);

        //update pointers for next iteration
        index = parentIndex;
        parentIndex = (int)std::ceil((index/(double)2)) - 1;
    }

    length++;
}

/* remove and return element with highest priority, time complexity O(logn) */
int PriorityQueue::dequeue(){
    if(length == 0){
        //PQ is empty!
        throw std::runtime_error("PQ is empty!");
    }

    //store highest priority ele to return
    int out = elements[0];
    length--; 
    //replace highest priority ele with the last element in arr at the root (index 0) before we bubble down 
    elements[0] = elements[length];

    /* Bubble down until the tree satisfies the ordering property of heap: root of any subtree is of higher priority than its descendents  
     * If current element has no children or is of higher priority than both of its children, ele is at the correct index
     * else, select child with higher priority to swap with element and continue to bubble down 
    */
    int index = 0; //start from root
    int leftChildIndex = (index * 2) + 1;
    int rightChildIndex = (index * 2) + 2;
    while(leftChildIndex < length){ //if boolean expr is false, element does not have children
        //ele has at least a left child
        int maxChildIndex = leftChildIndex;
        if(rightChildIndex < length){
            //if element has a right child and that child is of higher priority than the other, set maxChildIndex to right child and compare with ele
            if(elements[rightChildIndex] > elements[leftChildIndex]){
                maxChildIndex = rightChildIndex;
            }
        }

        if(elements[maxChildIndex] > elements[index]){
            //child is of higher priority than element (parent of child), swap and continue to bubble down
            swap(index, maxChildIndex);
            index = maxChildIndex;
            leftChildIndex = (index * 2) + 1;
            rightChildIndex = (index * 2) + 2;
        } else {
            //element (parent) is of higher priority than both its children, so ele is at the correct index
            return out; 
        }
    }

    //element does not have any children and it's at the correct index
    return out;

}

/* return element with highest priority, time complexity O(1) */
int PriorityQueue::peek() const{
    if(length == 0){
        //PQ is empty!
        throw std::runtime_error("PQ is empty!");
    }
    return elements[0];
}

int PriorityQueue::size() const{
    return length;
}
bool PriorityQueue::isEmpty() const{
    return length == 0;
}

/* Time complexity: O(n) */
void PriorityQueue::resize(){
    capacity *= 2;
    int* newArray = new int[capacity]();

    //copy elements from current arr to new array
    for(int i = 0; i < length; i++){
        newArray[i] = elements[i];
    }

    //release memory allocated for old array
    delete[] elements;
    elements = newArray;
}

void PriorityQueue::swap(int parentIndex, int childIndex){
    int temp = elements[parentIndex];
    elements[parentIndex] = elements[childIndex];
    elements[childIndex] = temp;
}

// enqueue
void operator +=(PriorityQueue& pq, int val){
    pq.enqueue(val);
}

//dequeue
void operator --(PriorityQueue& pq){
    pq.dequeue();
}