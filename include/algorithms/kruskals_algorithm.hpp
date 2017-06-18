/**
 * @file kruskals_algorithm.hpp
 * @version 1.0
 * @title kruskals_algorithm
 * @author Jabari Dash
 * @brief Given a connected weighted graph, find the minimum spanning tree.
 * @date 06/16/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef KRUSKALS_ALGORITHM_H
#define KRUSKALS_ALGORITHM_H

#include <iostream>
#include "../data_structures/Heap.hpp"
#include "../data_structures/Graph.hpp"
#include "../data_structures/Edge.hpp"
#include "../data_structures/Vertex.hpp"

/**
 * @brief Determines whether or not a graph is connected (cyclic).
 * @param graph The graph to be operated on/
 * @return True if conencted, otherwise false.
 */
template <template T> bool is_connected(Graph<T> graph);

/**
 * @brief
 * @param
 * @return
 */
template <template T> T size(Edge<T> edge);

/**
 * @brief
 * @param
 * @return
 */
template <template T> T find(Edge<T> edge);

/**
 * @brief 
 * @param
 * @return
 */
void kruskals_algorithm();

//------------------------------------------------------------------------------

template <template T> bool is_connected(Graph<T> graph) {
  return true;
}

//------------------------------------------------------------------------------

template <template T> T size(Edge<T> edge) {

}

//------------------------------------------------------------------------------

template <template T> T find(Edge<T> edge) {

}

//------------------------------------------------------------------------------

void kruskals_algorithm() {

}

#endif // KRUSKALS_ALGORITHM_H
