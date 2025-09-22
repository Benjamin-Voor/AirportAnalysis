#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"
#include "Vertex.h"
#include <string>
#include <vector>

template <typename T> class Graph {
public:
  Graph() {}

  void insert_vertex(std::string code, std::string city, std::string state);
  void add_edge(const std::string src, const std::string dest, int distance,
                int cost); // connect ver1 with ver2

  void print() const;

  Vertex<std::string> getVertex(std::string name);
  int get_vertex_index(const Vertex<T> &ver);
  std::vector<std::vector<Edge>> getEdges() const;
  std::vector<Vertex<T>> getVertices() const;
  void clean_visited();

  void DFS(Vertex<T> &ver);
  void BFS(Vertex<T> &ver);
  int dijkstra_shortest_path(const Vertex<T> &src, const Vertex<T> &dest);

private:
  std::vector<Vertex<T>> vertices;      // nodes
  std::vector<std::vector<Edge>> edges; // connections

  void DFS_helper(Vertex<T> &ver);
};

#endif
