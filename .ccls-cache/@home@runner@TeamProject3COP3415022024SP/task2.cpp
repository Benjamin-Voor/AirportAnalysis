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
    cout << "Path does not exist" << endl;
  }
  // take origin vertex and destination vertex
  // Vertex<std::string> originVertex = airports.getData(origin);
  // Vertex<std::string> destinationVertex = airports.getData(destination);
  // airports.dijkstra_shortest_path(originVertex, destinationVertex);
  
}