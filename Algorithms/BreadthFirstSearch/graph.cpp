#include "graph.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <iostream>


void Graph::addEdge(char u, char v){
    if(u == v) return; //loop not allowed

    //vertex u does not exist
    if(!graph.count(u)){
        graph[u] = {v};
    } else {
        //vertex u exists, insert vertex v into adjacency list 
        graph[u].insert(v);
    }

    //if vertex v does not exist, create new key
    if(!graph.count(v)){
        graph[v] = {};
    }
}

std::vector<char> Graph::shortestPath(char u, char v) const{
    //if u or v do not exist in graph, 
    //or if starting vertex is equal to destination, do nothing
    if(!graph.count(u) || !graph.count(v) || u == v) return {};

    std::vector<char> prev(26, 0); //Ascii value 0 represents NULL
    //Perform bfs with u as source vertex
    bfs(u, v, prev);

    
    int ind = v - 'a';
    //if v does not have a parent, path from u -> v does not exist (v could be in a separate component)
    if(prev[ind] == 0) return {};

    std::vector<char> path;
    path.push_back(v);
    while(prev[ind] != 0){ //construct path in reverse order
        path.push_back(prev[ind]); //add vertex to path
        ind = prev[ind] - 'a'; //update pointer to parent of current vertex; climbing up the tree
    }

    std::reverse(path.begin(), path.end());
    return path;
}

/*Breadth first search:
 *vertex u is the source vertex
 *track parent node of node visited -> BFS traversal of a graph represents a tree
 */
void Graph::bfs(char u, char v, std::vector<char>& prev) const{
    std::unordered_set<char> visited;
    std::queue<char> q;

    //push source vertex into queue and mark visited
    q.push(u);
    visited.insert(u);

    while(!q.empty()){
        char cur = q.front(); //explore vertex
        for(char neighbor : graph.at(cur)){ //for each unvisited neigbor:
            if(!visited.count(neighbor)){
                prev[neighbor - 'a'] = cur; //set parent of neighbor to cur vertex
                if(neighbor == v) return; //optimization step
                q.push(neighbor);
                visited.insert(neighbor); //mark visited 
            }
        }
        q.pop();
    }
}

int Graph::size() const{
    return graph.size();
}

void Graph::printGraph() const{
    std::cout << "Graph:\n";
    for(auto& pair : graph){
        std::cout << pair.first << ": { ";
        for(char neighbor : pair.second){
            std::cout << neighbor << " ";
        }
        std::cout << "}\n";
    }
} 