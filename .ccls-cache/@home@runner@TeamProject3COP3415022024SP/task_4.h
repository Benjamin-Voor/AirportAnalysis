#ifndef TASK_4_H
#define TASK_4_H

#include "Graph.h"
#include "MinHeap.h"

#include <fstream>
#include <iostream>
//#include <climits>
#define INT_MAX 1000

using namespace std;

// Task 4: Find the shortest path between the given origin airport and destination airport with a given number of stops. The algorithm should provide the appropriate message if such path doesn’t exist. 

void dijkstraShortestPathPrint(Graph<std::string> airports, Vertex<std::string> src, Vertex<std::string> dst){

  // TODO: Make a stops variable and keep track of each stop between origin and destination

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

  // set initial distances
  for (int i = 0; i < distances.size(); i++){
    distances[i] = (i == i_src) ? 0 : INT_MAX;
  }

  // create Edge heap and insert all edges
  MinHeap<Edge> heap;
  for (int i = 0; i < vertices.size(); i++){
    heap.insert(Edge(i_src, i, distances[i], costs[i]));
  }

  std::cout << "Shortest route from " << src.getData() << "to " << dst.getData() << "with ";

  int stops = 0;
  std::string strOne;
  std::string strTwo;
  std::string strThree;
  
  while (!heap.isEmpty()){
    // get the min edge
    Edge e = heap.delete_min();
    // shortest path reached: print data
    if (e.dest == i_dest) {
      if (e.distance == INT_MAX) return;
      strOne += (to_string(stops) + " stops: " + src.getData() + "->");
      strThree += (dst.getData() + ". The length is " + to_string(e.distance) + ". The cost is " + to_string(e.cost));
    }
    if (e.distance == INT_MAX) continue;
    // update distances and costs
    for (int i = 0; i < edges[e.dest].size(); i++){
      Edge edge = edges[e.dest][i];
      if (edge.distance + e.distance < distances[edge.dest]){
        distances[edge.dest] = edge.distance + e.distance;
        costs[edge.dest] = edge.cost + e.cost;
        // update string two along with the number of stops
        strTwo += (vertices[edge.dest].getData() + "->");
        stops++;
        heap.decrease_key(edge.dest, Edge(edge.dest, edge.dest, distances[edge.dest], costs[edge.dest]));
      }
    }
  }
  if(strOne == "") return;
  cout << strOne << strTwo << strThree << endl;
}


void task_3(Graph<std::string> airports, std::string origin, std::string destination) {
  Vertex<std::string> ogVertex = airports.getVertex(origin);
  Vertex<std::string> dstVertex = airports.getVertex(destination);

  // call the modified Dijkstra's algorithm
  dijkstraShortestPathPrint(airports, ogVertex, dstVertex);
  airports.clean_visited();
}
#endif