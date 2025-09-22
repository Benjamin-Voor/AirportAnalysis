#ifndef TASK_1_H
#define TASK_1_H

#include "Graph.cpp" // this is already included in main
// #include "Graph.h" // This is already included in task1.h
#include "Vertex.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool isFinOpened(std::fstream *fin, const std::string file) {
  // 2 different ways to check stream for error opening file:
  if (!fin->is_open() || (fin->rdstate() & std::ifstream::failbit) != 0) {
    std::cout << "error: " << file << " is not opened!" << std::endl;
    return false;
  }
  // std::cout << file << " is successfully opened!" << std::endl;
  return true;
}

Graph<std::string> task_1(const std::string file) {
  // = airports.csv
  // same as infile
  std::fstream fin;
  fin.open(file, std::fstream::in);
  isFinOpened(&fin, file);
  // An entire row of data with commas inside
  // Use stringstream to break it into individual words
  std::string line;

  // Just one variable (is it called a "datum"?)
  // Use stoi() for "string to integer" conversion
  // when we get to distances and costs
  std::string word;

  // read an entire row and
  // store it in a string variable 'line'
  std::getline(fin, line);

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
  // One line down, 384 more to go!

  // TODO: add graph for cities, too
  Graph<std::string> airports;
  // Graph<std::string> cities;
  // fin = airports.csv

  airports.insert_vertex("N/A", "N/A", "N/A");
  
  // TODO: change back to a while loop.
  // Switching between if and while is
  // an easy way to reduce compilation time
  while (getline(fin, line, '\n')) { 
    std::stringstream s(line);

    //Origin_airport
    std::getline(s, word, ',');
    std::string origin_airport = word;

    // Destination_airport
    std::getline(s, word, ',');
    std::string destination_airport = word;

    // Origin_city
    std::getline(s, word, '\"'); // dummy
    std::getline(s, word, ',');
    std::string origin_city = word;

    // Origin_state
    std::getline(s, word, ' '); // dummy
    std::getline(s, word, '\"');
    std::string origin_state = word;

    // Destination_City
    std::getline(s, word, '\"'); // dummy
    std::getline(s, word, ',');
    std::string destination_city = word;

    // Destination_state
    std::getline(s, word, ' '); // dummy
    std::getline(s, word, '\"');
    std::string destination_state = word;
    std::getline(s, word, ','); // dummy

    // Distance
    std::getline(s, word, ',');
    int distance = stoi(word);

    // Cost
    std::getline(s, word, ',');
    int cost = stoi(word);
    
    airports.insert_vertex(origin_airport, origin_city, origin_state);
    airports.insert_vertex(destination_airport, destination_city,
                           destination_state);


    
    airports.add_edge(origin_airport, destination_airport, distance, cost);


    // TODO: comment out for the real deal
    /*
    std::cout << ORIGIN_AIRPORT << ": " << origin_airport << std::endl
              << ORIGIN_CITY << ": " << origin_city << std::endl
              << "Origin_State"
              << ": " << origin_state << std::endl
              << DESTINATION_AIRPORT << ": " << destination_airport << std::endl
              << DESTINATION_CITY << ": " << destination_city << std::endl
              << "Destination_State"
              << ": " << destination_state << std::endl
              << DISTANCE << ": " << distance << std::endl
              << COST << ": " << cost << std::endl;
    */
  }
  // airports.print();
  fin.close(); // this must happen, rain or shine

  return airports;

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
}

#endif