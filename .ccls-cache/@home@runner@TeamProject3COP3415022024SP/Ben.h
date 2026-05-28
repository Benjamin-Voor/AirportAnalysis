#include "Graph.cpp"
#include "Graph.h"
#include "Vertex.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool isFinOpened(std::fstream *fin) {
  // 2 different ways to check stream for error opening file:
  if (!fin->is_open() || (fin->rdstate() & std::ifstream::failbit) != 0) {
    std::cout << "error: \'airports.csv\' is not opened!" << std::endl;
    return false;
  }
  std::cout << "\'airports.csv\' is successfully opened!" << std::endl;
  return true;
}

Graph<std::string> task_1(std::string *fin) {
  fin->open("airports.csv", std::fstream::in);
  isFinOpened(fin);
  // An entire row of data with commas inside
  // Use stringstream to break it into individual words
  std::string line;

  // Just one variable (is it called a "datum"?)
  // Use stoi() for "string to integer" conversion
  // when we get to distances and costs
  std::string word;

  // read an entire row and
  // store it in a string variable 'line'
  std::getline(&fin, line);

  // Used for breaking words
  std::stringstream s(line);

  std::getline(s, word, ',');
  const std::string ORIGIN_AIRPORT = word;
  std::getline(s, word, ',');
  const std::string DESTINATION_AIRPORT = word;
  std::getline(s, word, ',');
  const std::string ORIGIN_CITY = word;
  std::getline(s, word, ',');
  const std::string DESTINATION_CITY = word;
  std::getline(s, word, ',');
  const std::string DISTANCE = word;
  std::getline(s, word, '\n');
  const std::string COST = word;
  // This one works
  // One line down, 384 more to go!

  // TODO: add graph for cities, too
  Graph<std::string> airports;
  // Graph<std::string> cities;
  // fin = airports.csv

  // TODO: change back to a while loop.
  // Switching between if and while is
  // an easy way to reduce compilation time
  if (getline(&fin, line)) {
    std::stringstream s(line);
    std::getline(s, word, ','); // the first word is the origin airport
    Vertex<std::string> Origin_airport(word); // convert string to vertex
    airports.insert_vertex(Origin_airport); // insert origin airport vertex into
                                            // the graph of all airports

    std::getline(s, word, ','); // the second word is the destination airport
    Vertex<std::string> Destination_airport(word); // convert string to vertex
    airports.insert_vertex(
        Destination_airport); // insert destination airport vertex into the
                              // graph of all airports

    std::getline(s, word, '\"'); // dummy
    std::getline(s, word, '\"');
    // Vertex<std::string> Origin_city(word);

    std::getline(s, word, ',');  // dummy
    std::getline(s, word, '\"'); // dummy
    std::getline(s, word, '\"');
    // std::cout << DESTINATION_CITY << ": " << word << std::endl;
    // Vertex<std::string> Destination_city(word);
    std::getline(s, word, ','); // dummy

    std::getline(s, word, ',');
    int Distance = stoi(word);
    std::getline(s, word, ',');
    int Cost = stoi(word);
    airports.add_edge(Origin_airport, Destination_airport, Distance, Cost);
    // airports_costs.add_edge(Origin_airport, Destination_airport, Cost);

    std::cout << ORIGIN_AIRPORT << ": " << Origin_airport.getData()
              << std::endl;
    std::cout << DESTINATION_AIRPORT << ": " << Destination_airport.getData()
              << std::endl;
    // std::cout << ORIGIN_CITY << ": " << Origin_City.getData() << std::endl;
    std::cout << DISTANCE << ": " << Distance << std::endl;
    std::cout << COST << ": " << Cost << std::endl;

    // TODO: Finish creating graph.
    // Need another vertex for cities
    // Need another edge for costs

    std::cout << std::endl;
  }
  // airports.print();
  fin->close(); // this must happen, rain or shine

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
  fin.close(); // this must happen, rain or shine
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
}