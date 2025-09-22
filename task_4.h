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

void dijkstraShortestPathPrint4(Graph<std::string> airports, Vertex<std::string> src, Vertex<std::string> dst, int stops_limit){

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
  // make a predecessors vector
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

  std::cout << "Shortest route from " << src.getData() << " to " << dst.getData() << " with ";

  // strings for one print statement (obtained at different times in loop)
  std::string strOne;
  std::string strTwo;
  std::string strThree;

  int path_size;

  while (!heap.isEmpty()){
    // get the min edge
    Edge e = heap.delete_min_distance();
    // shortest path reached: print data
    if (e.dest == i_dest) {
      // if (e.distance == INT_MAX) return;
      std::vector<std::string> path;
      int current = e.dest;
      while (current != i_src) {
        // add current airport to path vector
        path.push_back(vertices[current].getData());
        // get predecessor
        current = predecessors[current];
      }
      path.push_back(src.getData()); // add src to path vector

      // set local variable equal to path size - 2
      path_size = path.size() - 2;

      // add to string one
      strOne = std::to_string(path.size() - 2) + " stops: ";
      // add to string three
      strThree = ". The length is " + std::to_string(e.distance) + ". The cost is " + std::to_string(e.cost);
      // add to string two
      for (int i = path.size() - 1; i >= 0; i--) {
        strTwo += path[i];
        if (i > 0) strTwo += "->";
      }
      break;
    }
    
    if (e.distance == INT_MAX) continue;
    // update distances and costs
    for (int i = 0; i < edges[e.dest].size(); i++){
      Edge edge = edges[e.dest][i];
      if (edge.distance + e.distance < distances[edge.dest]){
        distances[edge.dest] = edge.distance + e.distance;
        costs[edge.dest] = edge.cost + e.cost;
        predecessors[edge.dest] = e.dest;
        heap.decrease_key_distance(edge.dest, Edge(edge.dest, edge.dest, distances[edge.dest], costs[edge.dest]));
      }
    }
  }
  if(strOne == "") return;

  // check if the number of stops is less than stops_limit
  if (path_size > stops_limit) {
    cout << "No such path exists" << endl;
    return;
  }
  
  cout << strOne << strTwo << strThree << endl;
}


void task_4(Graph<std::string> airports, std::string origin, std::string destination, int stops) {
  Vertex<std::string> ogVertex = airports.getVertex(origin);
  Vertex<std::string> dstVertex = airports.getVertex(destination);

  // call the modified Dijkstra's algorithm
  dijkstraShortestPathPrint4(airports, ogVertex, dstVertex, stops);
  airports.clean_visited();
}
#endif