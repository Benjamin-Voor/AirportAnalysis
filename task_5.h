#ifndef TASK_5_H
#define TASK_5_H

#include "Graph.h"
#include "Vertex.h"

#include <iostream>
#include <string>

/*
  Task 5 is complete.
  
  Ben's PSEUDOCODE:
  Task_5:
  START
  
  cout Airport \t\t Connections
  For all vertices[i] {
    c = count
    v = three letter code
    if v is N/A
      continue
    for all vectors in "edges" whose second dimension is the index of the first vertex (i)
      e = current Edge
      if func isEdgeWithAirport
        increment count
    for all vectors in "edges" whose first dimension is the index of the first vertex (i)
      e = current Edge
      if func isEdgeWithAirport
        increment count
  cout three letter code \t\t count
    END
    
  helper func "isEdgeWithAirport":
  START
    get the source of the Edge, as a three letter
    code = e1 get the destination of the Edge, as a three letter code = e2
    if N/A
      return false
    if three letter code equals source or destination
      return true
    else, finally, return false
  END
*/

template <typename T>
bool isEdgeWithAirport(Graph<T> g, Edge e, T v, int i, int j) {
  T e1 = g.getVertices().at(e.src).getData();
  T e2 = g.getVertices().at(e.dest).getData();

  if (e1 == "N/A" || e2 == "N/A") {
    return false;
  }
  // std::cout << "edges[" << i << "][" << j << ']' << std::endl <<
  // "Origin_airport: " << e1 << ", Destination_airport: " << e2 << std::endl;
  if (v == e1 || v == e2) {
    return true;
  }
  return false;
}

template <typename T> 
void task_5(Graph<T> g) {
  // std::cout << "Every paragraph is an edge" << std::endl << std::endl;
  std::cout << std::endl << "Airport\t\tConnections" << std::endl;

  for (int i = 0; i < g.getVertices().size(); i++) {
    // for all vertices

    int c = 0;

    T v = g.getVertices().at(i).getData();
    if (v == "N/A") {
      continue;
    }
    // std::cout << "Vertices[" << i << "] = " << v << std::endl;

    // int v_index = g.get_vertex_index(g.getVertices().at(i));
    // lol this is literally just 'i'

    for (int j = 0; j < g.getEdges().size(); j++) {
      Edge e = g.getEdges().at(j).at(i);
      if (isEdgeWithAirport(g, e, v, i, j)) {
        c++;
      }
    }
    for (int j = 0; j < g.getEdges().at(i).size(); j++) {
      Edge e = g.getEdges().at(i).at(j);
      if (isEdgeWithAirport(g, e, v, i, j)) {
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