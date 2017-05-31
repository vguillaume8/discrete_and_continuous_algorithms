#ifndef EDGE_H
#define EDGE_H

#include <vector>             // std::vector<T>
#include <stdexcept>          // invalid_argument
#include "Vertex.hpp"         // Vector
#include "DataType.hpp"       // DataType<T>
#include "Pair.hpp"   // AbstractPair<T>

template <class T, class M> class Edge: public DataType<T> {

  public:
    Vertex<M> *u;
    Vertex<M> *v;

    Edge(M a, M b, T w);
    int find(std::vector< Edge<T,M> > edges, Vertex<M> u, Vertex<M> v);
};

//------------------------------------------------------------------------------

template <class T, class M> Edge<T,M>::Edge(M a, M b, T t) {
  if (a == b) {
    throw std::invalid_argument("Edge<T,M>::Edge(): Verticies u and v are the same: no self referencing edges allowed\n");
  }

  // Initialized Verticies
  u = new Vertex<M>(a);
  v = new Vertex<M>(b);

  DataType<T>::value = t;
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

template <class T, class M> bool operator==(const Edge<T,M>& e, const Edge<T,M>& f) {
  return (e.u == f.u) && (e.v == f.v) && (e.DataType<T>::value == f.DataType<T>::value);
}

//------------------------------------------------------------------------------

template <class T, class M> bool operator!=(const Edge<T,M>& e, const Edge<T,M>&f) {
  return (e.u != f.u) || (e.v != f.v) || (e.DataType<T>::value != f.DataType<T>::value);
}

#endif
