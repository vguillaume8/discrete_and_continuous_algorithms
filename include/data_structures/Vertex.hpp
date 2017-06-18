/**
 * @file data_structures/Vertex.hpp
 * @version 1.0
 * @title Vertex
 * @author Jabari Dash
 * @brief Vertex for use in Graphs.
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef VERTEX_H
#define VERTEX_H

#include <DataType.hpp>    // DataType<T>

template <class T> class Vertex: public DataType<T> {
  public:

    /**
     * @brief Constructs a Vertex
     * @param value Value of the vertex (typically numerical).
     */
    Vertex(T valaue);
};

//------------------------------------------------------------------------------

template <class T> Vertex<T>::Vertex(T value) {
  DataType<T>::value = value;
}

#endif // VERTEX_H
