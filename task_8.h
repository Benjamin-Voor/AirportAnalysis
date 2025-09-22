#ifndef TASK_8_H
#define TASK_8_H
#include "Graph.h"
#include "MinHeap.h"

#include <fstream>
#include <iostream>
#include <limits>

/*
8) Generate a Minimal Spanning Tree using Kruskal’s algorithm on G_u that you created in the 
previous step. The algorithm will output both the content of the constructed MST and its total cost. 
In this step, for each edge you need to consider the cost as weight to minimize the total cost. If the 
graph is disconnected the algorithm should provide minimum spanning forest consisting of a 
minimum spanning tree for each connected component. 
*/


// finds the root of a subset
int find(std::vector<int>& parent, int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// performs union of two subsets
void Union(std::vector<int>& parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// implements Kruskal's algorithm to find MST
std::pair<Graph<std::string>, double> kruskalMST(const Graph<std::string>& g) {
    int V = g.getVertices().size();
    std::vector<int> parent(V, -1); // parent array to store the parent of each vertex
    MinHeap<Edge> minHeap; // Min-heap to store edges

    // fill the min-heap with all edges from the graph
    const auto& edges = g.getEdges();
    for (int i = 0; i < V; ++i) {
        for (const Edge& edge : edges[i]) {
            minHeap.insert_cost(edge);
        }
    }

  // MST to store the result
  Graph<std::string> MST;
  for(int i = 0; i < g.getVertices().size(); i++){
      MST.insert_vertex(g.getVertices()[i].getData(), g.getVertices()[i].getCity(), g.getVertices()[i].getState());
  }
    double totalCost = 0.0;

    // keep track of the number of edges added to MST
    int edgesAdded = 0;

    // continue until all edges are added or MST is formed
    while (edgesAdded < V - 1 && !minHeap.isEmpty()) {
        Edge minEdge = minHeap.delete_min_cost();
        int x = find(parent, minEdge.src);
        int y = find(parent, minEdge.dest);

        // if including this edge does not cause cycle, include it in MST
        if (x != y) {
            MST.add_edge(g.getVertices()[minEdge.src].getData(), g.getVertices()[minEdge.dest].getData(), minEdge.distance, minEdge.cost);
            totalCost += minEdge.cost;
            Union(parent, x, y);
            edgesAdded++;
        }
    }

    // // check if MST is formed
    // if (edgesAdded < V - 1) {
    //     std::cout << "Error: MST cannot be formed. Graph is disconnected.\n";
    //     return std::make_pair(Graph<std::string>(), std::numeric_limits<double>::infinity());
    // }

    return std::make_pair(MST, totalCost);
}

// prints the MST and its total cost in proper format
void task_8_print(const Graph<std::string>& MST, double totalCost) {
    // print the header
    std::cout << "Minimal Spanning Tree:\n";
    std::cout << "Edge\t\t\t\tWeight\n";

    // store edges in a variable to avoid accessing the temporary object multiple times
    const auto& allEdges = MST.getEdges();

    // iterate over vertices and their edges to print the MST
    for (int i = 0; i < MST.getVertices().size(); ++i) {
        for (const Edge& edge : allEdges[i]) {
            // check if the edge is not going back to a vertex with lower index to avoid duplicates
            if (edge.dest > i) {
                // print edge and its weight
                std::cout << MST.getVertices()[i].getData() << " - " << MST.getVertices()[edge.dest].getData() << "\t\t";
                std::cout << edge.cost << "\n";
            }
        }
    }

    // print the total cost of the MST
    std::cout << "Total Cost of MST: " << totalCost << std::endl;
}

// calls Kruskal's algorithm and prints the result
void task_8(const Graph<std::string>& unweighted_graph) {
    // call Kruskal's algorithm
    std::pair<Graph<std::string>, double> result = kruskalMST(unweighted_graph);
    // print the result in the correct format
    task_8_print(result.first, result.second);
}

#endif