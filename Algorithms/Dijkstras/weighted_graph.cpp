#include "weighted_graph.h"
#include <iostream>
#include <queue>
#include "node.h"
#include <unordered_set>
#include <climits>
#include <algorithm>

void WeightedGraph::addWeightedEdge(char u, char v, int weight){
    //Non-positive weights and loops are not allowed
    if(weight <= 0 || u == v) return; 

    if(graph.count(u)){
        if(!graph[u].count(v)){
            graph[u].insert({v, weight});
        } else {
            return; //duplicate edge
        }
    } else{
        graph[u] = {{v, weight}};
    }

    if(!graph.count(v)){
        graph[v] = {};
    }
}

//lazy deletion implementation of dijkstra's shortest path algorithm
std::vector<char> WeightedGraph::shortestPath(char u, char v) const{
    if(!graph.count(u) || !graph.count(u) || u == v) return {};
    std::vector<char> prev(26, 0); //Ascii value of char '0' is null
    dijkstra(u, v, prev);
    return reconstructPath(u, v, prev);
}

std::vector<char> WeightedGraph::reconstructPath(char u, char v, std::vector<char>& prev) const{
    if(prev[v - 'a'] == 0) return {}; //no path (v does not exist within the same component as u)
    std::vector<char> path;
    path.push_back(v);
    int at = v - 'a';
    while(prev[at] != 0){
        path.push_back(prev[at]);
        at = prev[at] - 'a';
    }
    reverse(path.begin(), path.end());
    return path;
    
}

//lazy deletion implementation
void WeightedGraph::dijkstra(char u, char v, std::vector<char>& prev) const{
    std::unordered_set<char> visited;
    //Initialize distance of all vertices to infinity except for the source vertex. Distance vector stores the distance of the current shortest path from source to vertex.
    std::vector<int> distance(26, INT_MAX);
    distance[u - 'a'] = 0; 
    std::priority_queue<Node, std::vector<Node>, Comparator> pq; //min heap
    pq.push(Node(u, 0));

    while(!pq.empty()){
        Node curr = pq.top(); //pop has a void return type. Facepalm!
        pq.pop();

        //vertex has already been explored
        if(visited.count(curr.id)){
            continue;
        } 

        visited.insert(curr.id); //when a node has been marked visited, we have obtained the shortest path from source to that vertex
        if(curr.id == v) return; //optimization, found shortest path from u to v, stop search

        //relaxation: explore neighbors
        std::unordered_map<char, int> edges = graph.at(curr.id); //outgoing edges
        for(auto& edge : edges){
            if(visited.count(edge.first)) continue; //neighbor already explored 

            int currentDistance = curr.distance + edge.second; // calculate cost of current path
            if(currentDistance < distance[edge.first - 'a']){ // if the current path is shorter than prev path, update new shortest cost and add to queue
                prev[edge.first - 'a'] = curr.id;
                distance[edge.first - 'a'] = currentDistance;
                pq.push(Node(edge.first, currentDistance));
            }
        }
    }
}

int WeightedGraph::size() const{
    return graph.size();
}

void WeightedGraph::printGraph() const{
    std::cout << "Graph:\n";
    for(auto& pair : graph){
        std::cout << pair.first << ": {";
        for(auto& neighbor: pair.second){
            std::cout << " (" << neighbor.first << "," << neighbor.second << ")";
        }
        std::cout << " }\n";
    }
}