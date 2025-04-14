#ifndef _weighted_graph_h
#define _weighted_graph_h

#include <unordered_map>
#include <vector>
#include "node.h"


class WeightedGraph{
public:
    void addWeightedEdge(char u, char v, int weight);
    std::vector<char> shortestPath(char u, char v) const;
    int size() const;
    void printGraph() const;

private:
    std::unordered_map<char, std::unordered_map<char, int>> graph;
    std::vector<char> reconstructPath(char u, char v, std::vector<char>& prev) const;
    void dijkstra(char u, char v, std::vector<char>& prev) const;
    struct Comparator{
        bool operator ()(Node a, Node b){
            return a.distance > b.distance;
        }
    };
};


#endif