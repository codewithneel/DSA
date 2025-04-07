#include "graph.h"
#include <iostream>
#include <vector>

void printPath(std::vector<char>& path){
    std::cout << "Shortest path: ";
    for(int i = 0; i < path.size() - 1; i++){
        std::cout << path[i] << " -> ";
    }
    std::cout << path[path.size() - 1] << '\n';    
}

int main(){
    Graph graph;
    graph.addEdge('a', 'c');
    // graph.addEdge('a', 'a');
    // graph.addEdge('c', 'c');
    graph.addEdge('a', 'b');
    graph.addEdge('b', 'a');
    graph.addEdge('b', 'd');
    graph.addEdge('d', 'g');
    graph.addEdge('c', 'g');
    graph.addEdge('c', 'f');
    graph.addEdge('f', 'j');
    graph.addEdge('j', 'h');
    graph.addEdge('g', 'f');
    graph.addEdge('d', 'h');
    graph.addEdge('n', 'p'); //Graph NOT CONNECTED!
    // graph.printGraph();

    std::vector<char> path = graph.shortestPath('d', 'j');
    if(path.size() != 0) {
        printPath(path);
    } else {
        std::cout << "No Path Exists\n"; 
    }

}