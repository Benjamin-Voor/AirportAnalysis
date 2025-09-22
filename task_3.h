#ifndef TASK_3_H
#define TASK_3_H

#include "Graph.h"
#include "MinHeap.h"

#include <fstream>
#include <iostream>
//#include <climits>
#define INT_MAX 1000

using namespace std;

// Task 3: Find all shortest paths between the given origin airport and all the airports in the destination state. The algorithm should output all the paths and their lengths. The algorithm should provide the appropriate message if no such paths exist. 

void dijkstraShortestPathPrint(Graph<std::string> airports, Vertex<std::string> src, Vertex<std::string> dst){

  // set initial distances
  int i_src = airports.get_vertex_index(src);
  int i_dest = airports.get_vertex_index(dst);

  // if src or dest is not in the graph
  if (i_src == -1 || i_dest == -1) {
    throw std::string("Shortest path: incorrect vertices");
  }

  // make variables for vertices and edges in airports
  std::vector<Vertex<std::string>> vertices = airports.getVertices();
  std::vector<std::vector<Edge>> edges = airports.getEdges();

  // clean visited
  airports.clean_visited();
  // make a distances vector
  std::vector<int> distances(vertices.size());
  // make a costs vector
  std::vector<int> costs(vertices.size());
  // make a vector to store predecessors
  std::vector<int> predecessors(vertices.size(), -1);

  // set initial distances
  for (int i = 0; i < distances.size(); i++){
    distances[i] = (i == i_src) ? 0 : INT_MAX;
  }

  // create Edge heap and insert all edges
  MinHeap<Edge> heap;
  for (int i = 0; i < vertices.size(); i++){
    heap.insert_distance(Edge(i_src, i, distances[i], costs[i]));
  }
  while (!heap.isEmpty()){
    // get the min edge
    Edge e = heap.delete_min_distance();
    // shortest path reached: print data
    if (e.dest == i_dest){
      if (e.distance == INT_MAX) return;
      // backtrack to reconstruct the path
      std::vector<std::string> path;
      int current = e.dest;
      while (current != i_src) {
          path.push_back(vertices[current].getData());
          current = predecessors[current];
      }
      path.push_back(src.getData());
      // Print the path
      for (int i = path.size() - 1; i >= 0; i--) {
          cout << path[i];
          if (i > 0) cout << "->";
      }
      cout << "\t\t" << e.distance << "\t\t\t" << e.cost << endl;
      return;
    }
    if (e.distance == INT_MAX) continue;
    // update distances and costs
    for (int i = 0; i < edges[e.dest].size(); i++){
      Edge edge = edges[e.dest][i];
      if (edge.distance + e.distance < distances[edge.dest]){
        distances[edge.dest] = edge.distance + e.distance;
        costs[edge.dest] = edge.cost + e.cost;
        heap.decrease_key_distance(edge.dest, Edge(edge.dest, edge.dest, distances[edge.dest], costs[edge.dest]));
        // store predecessor
        predecessors[edge.dest] = e.dest;
      }
    }
  }
}


void task_3(Graph<std::string> airports, std::string origin, std::string destinationState) {
  Vertex<std::string> originVertex = airports.getVertex(origin);
  // find all the destination state airports and add them to an array
  vector<Vertex<std::string>> destination_state_airports;
  for(int i = 1; i < airports.getVertices().size(); i++) {
    if(airports.getVertices()[i].getState() == destinationState) {
      destination_state_airports.push_back(airports.getVertices()[i]);
    }
  }
  // use a modified Dijkstra's algorithm that does not stop after finding the shortest path for each destination state airport
  cout << "Path\t\t\tLength\t\tCost" << endl;
  for(Vertex<std::string> dstVertex : destination_state_airports) {
    try{
      // call the modified Dijkstra's algorithm
    dijkstraShortestPathPrint(airports, originVertex, dstVertex);
      } catch (const std::string& e) {
          std::cerr << "Caught an exception: " << e << std::endl;
      } catch (...) {
          std::cerr << "Caught an unknown exception" << std::endl;
      }
  }
  airports.clean_visited();
}
#endif