#ifndef EDGE_H
#define EDGE_H

#include "Vertex.hpp"
#include <vector>
#include <stdexcept>

class Edge {

  public:
    int weight;
    Vertex u;
    Vertex v;

//------------------------------------------------------------------------------

    Edge(Vertex& u, Vertex& v, int weight) {
      if (u == v) {
        throw std::invalid_argument("Verticies u and v are the same: no self referencing edges allowed\n");
      }

      if (u.num == -1 || v.num == -1) {
        throw std::invalid_argument("Vertex has value -1, must have integer value greater than or equal to 0\n");
      }

      this-> u = Vertex(u.num);
      this-> v = Vertex(v.num);
      this-> weight = weight;
    }

//------------------------------------------------------------------------------

    ~Edge() {
      //delete u;
      //delete v;
    }

//------------------------------------------------------------------------------

    static int find(std::vector<Edge>& edges, Vertex& u, Vertex& v) {
      int n = edges.capacity();
      int index = -1;

      for (int i = 0; i < n; i++) {
        if (edges[i].u == u && edges[i]. v == v) {
          index = i;
          break;
        }

      }

      return index;

    }

//------------------------------------------------------------------------------

    friend bool operator>(const Edge& e, const Edge& f) {
      return e.weight > f.weight;
    }

    friend bool operator>=(const Edge& e, const Edge& f) {
      return e.weight >= f.weight;
    }

    friend bool operator<(const Edge& e, const Edge& f) {
      return e.weight < f.weight;
    }

    friend bool operator<=(const Edge& e, const Edge& f) {
      return e.weight <= f.weight;
    }

    friend bool operator==(const Edge& e, const Edge& f) {
      return (e.u == f.u) && (e.v == f.v) && (e.weight == f.weight);
    }

    friend bool operator!=(const Edge& e, const Edge&f) {
      return (e.u != f.u) || (e.v != f.v) || (e.weight != f.weight);
    }
};

#endif
