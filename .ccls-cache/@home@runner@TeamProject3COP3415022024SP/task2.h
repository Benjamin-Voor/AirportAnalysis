#ifndef TASK2_H
#define TASK2_H
#include "Graph.cpp"
#include "Graph.h"
#include "Vertex.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void task_2(Graph <std::string> airports, std::string origin, std::string destination) {
  // case for no path
  if(origin == destination){
    std::cout << "Path does not exist" << std::endl;
  }
  // take origin vertex and destination vertex
 



  
  
  Vertex<std::string> destinationVertex = airports.getData(destination);
  
  airports.dijkstra(originVertex, destinationVertex);

}

void dijkstra(Vertex<std::string> origin, Vertex<std::string> destination) {
  int i_src = get_vertex_index(src);
  int i_dest = get_vertex_index(dest);

  if (i_src == -1 || i_dest == -1) {
    throw std::string("Shortest path: incorrect vertices");
  }
}
#endif