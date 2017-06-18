/**
 * @file LinkedListNode.hpp
 * @version 1.0
 * @title LinkedListNode
 * @author Jabari Dash
 * @brief Implementation of a Singly LinkedListNode.
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef LINKED_LIST_NODE
#define LINKED_LIST_NODE

#include "DataType.hpp"    // DataType<T>

template <class T> class LinkedListNode: public DataType<T> {
  public:
    // Public attributes

    /** @brief Pointer to the next node. */
    LinkedListNode* next;

    // Constructors

    /** @brief Constructs a Node. */
    LinkedListNode(T d);
};

//------------------------------------------------------------------------------

template <class T> LinkedListNode<T>::LinkedListNode(T t) {
  DataType<T>::value = t;
}

#endif
