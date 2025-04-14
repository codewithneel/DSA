#include "priority_queue.h"
#include <stdexcept>

    //constructor, destructor
    PriorityQueue::PriorityQueue(){
        capacity = 10;
        length = 0;
        elements = new int[10]();
    }

    PriorityQueue::~PriorityQueue(){
        delete[] elements;
    }

    //member functions

    /* enqueue: insert element to the end of array
     * Time complexity: O(1)
     */
    void PriorityQueue::enqueue(int val){
        if(length + 1 > capacity) resize();//resize
        elements[length] = val; 
        length++;
    }

    /* dequeue: remove element with highest priority
     * Time complexity: O(n) 
     *
     * Scan through array for max element, grab ele, and then shift
     * all elements to the right of max ele one index to the left
     */
    int PriorityQueue::dequeue(){
        //priorityqueue empty
        if(length == 0){
            //throw exception
            throw std::runtime_error("PQ is empty!");
        }
        int highestPriority = elements[0];
        int index = 0;

        //find max element
        for(int i = 1; i < length; i++){
            if(elements[i] > highestPriority){
                highestPriority = elements[i];
                index = i;
            }
        }  

        //shift elements from i+1 to n to the left 1 index
        for(int i = index + 1; i < length; i++){
            elements[i-1] = elements[i];
        }
        length--;
        return highestPriority;
    }

    /* Peek: return element with highest priority without removing it
     * Time complexity: O(n)
     */
    int PriorityQueue::peek() const{
        //prioritqueue empty
        if(length == 0){
            //throw exception
            throw std::runtime_error("PQ is empty!");
        }
        int highestPriority = elements[0];

        for(int i = 1; i < length; i++){
            if(elements[i] > highestPriority){
                highestPriority = elements[i];
            }
        }
        return highestPriority;
    }

    int PriorityQueue::size() const{
        return length;
    }

    bool PriorityQueue::isEmpty() const{
        return length == 0; 
    }

    /* Resize: replace old array with a new container double its size
     * Time complexity: O(n) 
     */
    void PriorityQueue::resize(){
        capacity *= 2;
        int* newArr = new int[capacity]();

        //copy elements from old array to new array
        for(int i = 0; i < length; i++){
            newArr[i] = elements[i];
        }

        //destroy old array
        delete[] elements;

        //elements points to new array
        elements = newArr; 
    }

    void operator +=(PriorityQueue& pq, int val){
        pq.enqueue(val);
    }