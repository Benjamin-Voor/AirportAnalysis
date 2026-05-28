#ifndef TASK_5_H
#define TASK_5_H

#include "Graph.h"
#include "Queue.cpp"
#include "Queue.h"
#include "Vertex.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/*
  Ben's PSEUDOCODE:
  START
  get size of vertices vector
  IGNORE THIS: make count arr whose size = #vertices. This doesn't work because "variable-size object may not be initialized".
  For all vertices
    initialize count
    get the three letter code = v
    for all vectors in "edges"
      for every Edge in the vector
        get the edge = e
        get the source of the Edge, as a three letter code = e1
        get the destination of the Edge, as a three letter code = e2
        if three letter code equals source or destination
          increment count
          cout v \t count
        finally, cout everything else
    END
*/

/*
  get_vertex_index(v);
  for loop through edges[i]
  for loop through edges[i]
*/

template <typename T>
bool isEdgeWithAirport(Graph<T> g, Edge e, T v) {
  T e1 = g.getVertices().at(e.src).getData();
  T e2 = g.getVertices().at(e.dest).getData();
  if (e1 == "N/A" || e2 == "N/A") {
    return false;
  }
  if (v == e1 || v == e2) {
    return true;
  }
  return false;
}

template <typename T> void task_5(Graph<T> g) {
  // std::cout << "Every paragraph is an edge" << std::endl << std::endl;
  std::cout << "TASK 5: " << std::endl << "Airport\t\tConnections" << std::endl;

  for (int i = 0; i < g.getVertices().size(); i++) {
    // for all vertices
    
    int c = 0;
    
    T v = g.getVertices().at(i).getData();
    if (v == "N/A") {
      continue;
    }

    int v_index = g.get_vertex_index(g.getVertices().at(i));
    
    for (int j = 0; j < g.getEdges().size(); j++) {
      Edge e = g.getEdges().at(j).at(v_index);
      if(isEdgeWithAirport(g,e,v)) {
        c++;
      }
    }
    for (int j =0; j < g.getEdges().at(v_index).size(); j++) {
      Edge e = g.getEdges().at(j).at(v_index);
      if(isEdgeWithAirport(g,e,v)) {
        c++;
      }
    }
      
      
      
      /*
      for (int k = 0; k < g.getEdges().at(j).size(); k++) {
        Edge e = g.getEdges().at(j).at(k);
        T e1 = g.getVertices().at(e.src).getData();
        T e2 = g.getVertices().at(e.dest).getData();
        if (e1 == "N/A" || e2 == "N/A") {
          continue;
        }
        if (v == e1 || v == e2) {
          c++;
          
          std::cout << "Vertices[" << i << "] = " << v << std::endl
                    << "edges[" << j << "][" << k << ']' << std::endl
                    << "Origin_airport: " << e1
                    << ", Destination_airport: " << e2 << std::endl
                    << "count: " << c << std::endl
                    << std::endl;
          
        }
      }
    }
    */
    std::cout << v << "\t\t" << c << std::endl;
  }
}

#endif