#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Edge.hpp"
#include "Vertex.hpp"

// difference between abstract class and interfaces
// https://www.youtube.com/watch?v=nNwZN3mOVcw
// https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm

template <class T, class M> class Graph {
  public:
    T weight;

    std::vector< Edge<T,M> > edges;
    std::vector< Vertex<M> > verticies;

    Graph(std::vector< Edge<T,M> > edges, std::vector< Vertex<M> > verticies);

    T get_weight();
    bool is_connected();
    bool contains_edge(Edge<T,M> edge);
    bool contains_vertex(Vertex<T> vertex);
};

//------------------------------------------------------------------------------

template <class T, class M> Graph<T,M>::Graph(std::vector< Edge<T,M> > e, std::vector< Vertex<M> > v) {
  edges = e;
  verticies = v;
}

//------------------------------------------------------------------------------

template <class T, class M> T Graph<T,M>::get_weight() {
  T sum;
  int size;

  size = edges.size();

  // Sum all of the weights of the graph
  for (int i = 0; i < size; i++) {
    sum += edges[i].weight;
  }

  return sum;
}

//------------------------------------------------------------------------------

template <class T, class M> bool is_connected() {

  // TODO - Implement, maybe with disjoint union set, breadth first or depth first search

  return true;
}

//------------------------------------------------------------------------------

/*
Returns true if and only if the Graph object's edges list has the egde that
we are searching for
*/
template <class T, class M> bool Graph<T,M>::contains_edge(Edge<T,M> edge) {
  int n = edges.capacity();
  bool contains = false;

  for (int i = 0; i < n; i++) {
    if (edges[i] == edge) {
      contains = true;
      break;
    }
  }
  return contains;
}

//------------------------------------------------------------------------------

/*
Returns true if and only if the Graph object's vertex list has the vertex that
we are searching for
*/
template <class T, class M> bool Graph<T,M>::contains_vertex(Vertex<T> vertex) {
  int n = verticies.capacity();
  bool contains = false;

  for (int i = 0; i < n; i++) {
    if (verticies[i] == vertex) {
      contains = true;
      break;
    }
  }
  return contains;
}

#endif
