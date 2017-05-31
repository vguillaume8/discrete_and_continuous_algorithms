#ifndef VERTEX_H
#define VERTEX_H

#include <DataType.hpp>

template <class T> class Vertex: public DataType<T> {
  public:
    Vertex(T v);
};

//------------------------------------------------------------------------------

template <class T> Vertex<T>::Vertex(T v) {
  DataType<T>::value = v;
}

#endif
