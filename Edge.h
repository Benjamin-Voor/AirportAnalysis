#ifndef EDGE_H
#define EDGE_H

class Edge {
public:
  Edge(int src = 0, int dest = 0, int distance = 0, int cost = 0)
      : src(src), dest(dest), distance(distance), cost(cost) {}
  // renamed "weight" to "distance", and added field "cost"

bool operator<(const Edge &other) const {
  return this->cost < other.cost;
}
bool operator<=(const Edge &other) const {
  return this->cost <= other.cost;
}
bool operator>(const Edge &other) const {
  return this->distance > other.distance;
}
bool operator>=(const Edge &other) const {
  return this->distance >= other.distance;
}

  int src;
  int dest;
  int distance;
  int cost;
};

#endif
