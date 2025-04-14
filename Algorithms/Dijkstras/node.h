#ifndef _node_h
#define _node_h

struct Node{
    char id;
    int distance;
    
    Node(char id, int distance){
        this->id = id;
        this->distance = distance;
    }
};

#endif