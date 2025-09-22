#ifndef VERTEX_H
#define VERTEX_H

template <typename T>
class Vertex {
public:
    Vertex(const T& d = T(), const T& c = T(), const T& s = T()) : code(d), city(c), state(s), visited(false) {};
    const T& getData() const {return code; } // 3 letter airport code
    const T& getCity() const {return city; } // Full name of city
    const T& getState() const {return state; } // 2 letter state code
    bool getVisited() const {return visited; } // Used for algorithms
    void setVisited(bool v) { visited = v; }

private:
    T code;
    T city;
    T state;
    bool visited;
};

#endif