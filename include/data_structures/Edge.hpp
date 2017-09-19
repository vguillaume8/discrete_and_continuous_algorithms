/**
 * @file data_structures/Edge.hpp
 * @version 1.0
 * @title Edge
 * @author Jabari Dash
 * @brief Weighted Edge in a weighted Graph.
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef EDGE_H
#define EDGE_H

#include <vector>             // std::vector<T>
#include <stdexcept>          // std::invalid_argument
#include "Vertex.hpp"         // Vertex<T>
#include "DataType.hpp"       // DataType<T>
#include "Pair.hpp"           // Pair<T>

template <class T, class M> class Edge: public DataType<T> {
  public:

    // TODO - UTILIZE SUPERCLASS ATTRIBUTES RATHER THAN NEW ONES

    /** @brief First vertex. */
    Vertex<M> *u;

    /** @brief Second vertex. */
    Vertex<M> *v;

    /**
     * @brief Constructs a weighted edge between two verticies
     * @param a Value of first vertex.
     * @param b Value of second vertex.
     * @param w Weight of edge.
     */
    Edge(M a, M b, T weight);

    // TODO - USE FIND FROM util::

    /**
     * @brief Provided a vector of verticies, finds an edge that connects two specified verticies.
     * @param edges Vector of edges to search from.
     * @param u First vertex.
     * @param v Second vertex.
     * @return Index of the edge.
     */
    int find(std::vector< Edge<T,M> > edges, Vertex<M> u, Vertex<M> v);
};

//------------------------------------------------------------------------------

template <class T, class M> Edge<T,M>::Edge(M a, M b, T weight) {
  if (a == b) {
    throw std::invalid_argument("Edge<T,M>::Edge(): Verticies u and v are the same: no self referencing edges allowed\n");
  }

  // Initialized Verticies
  u = new Vertex<M>(a);
  v = new Vertex<M>(b);

  DataType<T>::value = weight;
}

//------------------------------------------------------------------------------

template <class T, class M> int Edge<T,M>::find(std::vector< Edge<T,M> > edges, Vertex<M> u, Vertex<M> v) {
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

/**
 * @brief Operator overload of ==
 * @return True if and only if all instance variables are equal between edge e, and edge f.
 */
template <class T, class M> bool operator==(const Edge<T,M>& e, const Edge<T,M>& f) {
  return (e.u == f.u) && (e.v == f.v) && (e.DataType<T>::value == f.DataType<T>::value);
}

//------------------------------------------------------------------------------

/**
 * @brief Operator overload of !=
 * @return
 */
template <class T, class M> bool operator!=(const Edge<T,M>& e, const Edge<T,M>& f) {
  return (e.u != f.u) || (e.v != f.v) || (e.DataType<T>::value != f.DataType<T>::value);
}

#endif
