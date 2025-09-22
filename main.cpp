// #include "Graph.cpp"
#include "Graph.h"
//#include "Vertex.h"
#include "task_1.h"
#include "task_2.h"
#include "task_3.h"
#include "task_4.h"
#include "task_5.h"
#include "task_6.h"
#include "task_7.h"
#include "task_8.h"
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
  // airports.print();

  task_2(airports, "ATL", "MIA");
  task_2(airports, "PIT", "ACT");

  task_3(airports, "ATL", "FL");
  task_3(airports, "IAD", "FL");

  task_4(airports, "IAD", "MIA", 3); // too many parameters
  task_4(airports, "PIT", "ACT", 2); // too many parameters
  
  
  Graph<std::string> unweight = task_6(airports);
  
  
  std::cout << "TASK_7: " << std::endl;
  task_7(unweight);
  
  task_8(unweight);
  
  std::cout << "TASK_6: " << std::endl;
  unweight.print();

  //TODO: leave task_5 at the bottom of Main, because it takes the longest to load
  task_5(airports);

  return 0;
}