// #include "Graph.cpp"
#include "Graph.h"
//#include "Vertex.h"
#include "task_1.h"
// #include "task_2.h"
#include "task_3.h"
//#include "task_4.h"
//#include "task_5.h"
// #include <fstream>
#include <iostream>
// #include <sstream>
#include <string>

// using namespace std;

/*
File name = main.cpp
Student names =
  Benjamin Voor
  Brian Tran
  Robert Baumgarten
Course number = COP3415.02
Date of last modification = [due date]
*/

int main() {
  // https://www.geeksforgeeks.org/csv-file-management-using-c/#
  const std::string AIRPORTSCSV = "airports.csv";
  Graph<std::string> airports = task_1(AIRPORTSCSV);
  //airports.print();
  

  // task_2(airports, "ATL", "MIA");
  // task_2(airports, "PIT", "ACT");
  
  task_3(airports, "ATL", "FL");
  //task_3(airports, "IAD", "FL");

  // task_4(airports, "IAD", "MIA", 3);
  // task_4(airports, "PIT", "ACT", 2);
  //task_5(airports);

  /*

  Inspiration from testGraphs.cpp
  Vertex<std::string> v("SFO");
  Vertex<std::string> v2("LAX");
  Vertex<std::string> v3("DFW");
  Vertex<std::string> v4("ORD");
  Vertex<std::string> v5("JFK");
  Vertex<std::string> v6("BOS");
  Vertex<std::string> v7("MIA");

  Graph<std::string> airports;

  airports.insert_vertex(v);
  airports.insert_vertex(v2);
  airports.insert_vertex(v3);
  airports.insert_vertex(v4);
  airports.insert_vertex(v5);
  airports.insert_vertex(v6);
  airports.insert_vertex(v7);

  airports.add_edge(v, v2, 337);
  airports.add_edge(v, v3, 1464);
  airports.add_edge(v, v4, 1846);
  airports.add_edge(v, v6, 2704);
  airports.add_edge(v3, v4, 802);
  airports.add_edge(v6, v4, 867);
  airports.add_edge(v5, v6, 187);
  airports.add_edge(v5, v7, 1090);
  airports.add_edge(v6, v7, 1258);
  airports.add_edge(v2, v7, 2342);
  airports.add_edge(v2, v3, 1235);
  airports.add_edge(v7, v3, 1121);
  airports.add_edge(v4, v5, 740);

  airports.print();

  std::cout << '\n';
  std::cout << airports.dijkstra_shortest_path(v7, v);
  */

  return 0;
}