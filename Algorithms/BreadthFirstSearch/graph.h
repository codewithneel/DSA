#ifndef _graph_h
#define _graph_h

#include <unordered_map>
#include <unordered_set>
#include <vector>

/*Unweighted, directed graph*/
class Graph{
public:

    /*Inserts directed edge from u to v*/
    void addEdge(char u, char v);

    /*Returns shortest path from u to v. Time complexity: O(V + E)*/
    std::vector<char> shortestPath(char u, char v) const;

    /*Returns the number of vertices in the graph*/
    int size() const;

    /*Prints adjacency list of graph*/
    void printGraph() const; 


private:
    /*Graph is respresented by adjacency list. 
     *Key: vertex
     *Value: list of neighboring vertices (out-going edges)
     */
    std::unordered_map<char, std::unordered_set<char>> graph;

    void bfs(char u, char v, std::vector<char>& prev) const;
};

#endif