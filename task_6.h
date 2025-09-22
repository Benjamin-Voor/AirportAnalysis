#ifndef TASK_6_H
#define TASK_6_H
#include "Graph.h"
#include "MinHeap.h"

#include <fstream>
#include <iostream>

/* Task 6 is complete.
CREATE NEW GRAPH
GO THROUGH NEW EDGES ADJACENCY MATRIX
CHECK EACH EDGE, IF THERE IS AN EDGE THAT EXISTS
CHECK TO SEE IF THE REVERSE FLIGHT EDGE EXISTS
IF IT DOES, CHANGE THE COST OF THE EDGE THAT'S MORE
TO THE COST OF THE CHEAPER EDGE
IF IT DOESN'T EXIST, CREATE THE REVERSE EDGE FLIGHT
*/

Graph<std::string> task_6(Graph<std::string> g) {
  Graph<std::string> unweighted = g;
  std::vector<Vertex<std::string>> v = unweighted.getVertices();
  std::vector<std::vector<Edge>> e = unweighted.getEdges();

  for (int i = 1; i < e.size(); i++) {
    for (int j = 1; j < e[i].size(); j++) {
      if (e[i][j].dest != 0) {
        if (e[j][i].dest != 0) {
          if (e[i][j].cost > e[j][i].cost) {
            e[i][j].cost = e[j][i].cost;
          } else {
            e[j][i].cost = e[i][j].cost;
          }
        } else {
          unweighted.add_edge(v[j].getData(), v[i].getData(), e[i][j].distance,
                              e[i][j].cost);
        }
      }
    }
  }
  return unweighted;
}
#endif