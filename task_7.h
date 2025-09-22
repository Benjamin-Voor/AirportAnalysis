#ifndef TASK_7_H
#define TASK_7_H
#include "Graph.h"
#include "MinHeap.h"

#include <fstream>
#include <iostream>
#include <limits>

/* 7) Generate a Minimal Spanning Tree utilizing Prim’s algorithm on G_u that you created in the previous step. The algorithm will output both the content of the constructed MST and its total cost. In this step, for each edge you need to consider the cost as weight to minimize the total cost. In the event of a disconnected graph, the algorithm will appropriately notify that an MST cannot be formed. Note: A connected graph is defined as one where there exists a path between every pair of vertices. */

// perform Prim's algorithm to find the Minimal Spanning Tree (MST)
// returns the MST and its total cost
template<typename T>
std::pair<Graph<std::string>, double> primMST(const Graph<T>& g) {
    // create a priority queue to store edges
    MinHeap<Edge> minHeap;

    // vector to keep track of vertices included in MST
    std::vector<bool> inMST(g.getVertices().size(), false);

    // MST to store the result
    Graph<std::string> MST;
    for(int i = 0; i < g.getVertices().size(); i++){
        MST.insert_vertex(g.getVertices()[i].getData(), g.getVertices()[i].getCity(), g.getVertices()[i].getState());
    }

    // total cost of the MST
    double totalCost = 0.0;

    // choose a starting vertex (assuming the graph is connected)
    int startVertex = 1; // Choosing the first vertex as the starting point

    // mark the start vertex as included in MST
    inMST[startVertex] = true;

    // store edges in a variable to avoid accessing the temporary object multiple times
    const std::vector<std::vector<Edge>>& allEdges = g.getEdges();

    // add all edges connected to the start vertex to the priority queue
    for (const Edge& edge : allEdges[startVertex]) {
      minHeap.insert_cost(edge);
    }

    // repeat until all vertices are included in MST
    while (!minHeap.isEmpty()) {
        // get the minimum cost edge from the priority queue
        Edge minEdge = minHeap.delete_min_cost();

        // if the edge leads to a vertex not in MST, include it in MST
        if (!inMST[minEdge.dest]) {
            MST.add_edge(g.getVertices()[minEdge.src].getData(), g.getVertices()[minEdge.dest].getData(), minEdge.distance, minEdge.cost);
            totalCost += minEdge.cost;

            // mark the destination vertex as included in MST
            inMST[minEdge.dest] = true;

          // add all edges connected to the destination vertex to the priority queue
          for (const Edge& edge : allEdges[minEdge.dest]) {
              if (!inMST[edge.dest]) {
                  minHeap.insert_cost(edge);
              }
          }
        }
    }

    // check if the MST is connected
    // for (bool visited : inMST) {
    //     if (!visited) {
    //         std::cout << "Error: The graph is disconnected. MST cannot be formed.\n";
    //         return std::make_pair(Graph<std::string>(), std::numeric_limits<double>::infinity());
    //     }
    // }

    return std::make_pair(MST, totalCost);
}


void task_7_print(const Graph<std::string>& MST, double totalCost) {
    // print the header
    std::cout << "Minimal Spanning Tree:\n";
    std::cout << "Edge\t\t\tWeight\n";

    // store edges in a variable to avoid accessing the temporary object multiple times
    const std::vector<std::vector<Edge>>& allEdges = MST.getEdges();

    // iterate over vertices and their edges to print the MST
    for (int i = 0; i < MST.getVertices().size(); ++i) {
        const __gnu_cxx::__alloc_traits<std::allocator<std::vector<Edge>>, std::vector<Edge>>::value_type& vertexEdges = allEdges[i];
        for (const Edge& edge : vertexEdges) {
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

// joins other functions so that only task_7() is called in main
void task_7(Graph<std::string> unweighted_graph){
    // set auto result equal to the primMST algorithm on the graph from task 6
    std::pair<Graph<std::string>, double> result = primMST(unweighted_graph);
    // print the result in the correct format
    task_7_print(result.first, result.second);
}

#endif