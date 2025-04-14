#include <iostream>
#include "weighted_graph.h"
#include <vector>

void printPath(std::vector<char>& path){
    std::cout << "Shortest path: ";
    for(int i = 0; i < path.size() - 1; i++){
        std::cout << path[i] << " -> ";
    }
    std::cout << path[path.size() - 1] << '\n';    
}

int main(){
    WeightedGraph graph;
    graph.addWeightedEdge('a', 'b', 2);
    graph.addWeightedEdge('a', 'd', 1);
    graph.addWeightedEdge('b', 'd', 3);
    graph.addWeightedEdge('b', 'e', 10);
    graph.addWeightedEdge('d', 'c', 2);
    graph.addWeightedEdge('d', 'e', 2);
    graph.addWeightedEdge('d', 'f', 8);
    graph.addWeightedEdge('d', 'g', 4);
    graph.addWeightedEdge('h', 'a', -6); //Negative weight
    graph.addWeightedEdge('e', 'g', 6);
    graph.addWeightedEdge('c', 'a', 4);
    graph.addWeightedEdge('c', 'f', 5);
    graph.addWeightedEdge('c', 'h', 13);
    graph.addWeightedEdge('e', 'g', 6); //duplicate edge
    graph.addWeightedEdge('g', 'f', 1);
    graph.addWeightedEdge('h', 'i', 6);
    // graph.printGraph();
    std::vector<char> shortestPath = graph.shortestPath('a', 'f');
    if(shortestPath.size() > 0){
        printPath(shortestPath);
    } else {
        std::cout << "No path exists\n";
    }
    

}