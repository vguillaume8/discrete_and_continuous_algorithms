/**
 * @file AbstractLinkedList.hpp
 * @version 1.0
 * @title AbstractLinkedList
 * @author Jabari Dash
 * @brief Any implementation of a LinkedList should extended this abstract class.
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef ABSTRACT_LINKED_LIST_H
#define ABSTRACT_LINKED_LIST_H

#include "IndexedDataStructure.hpp"    // IndexedDataStructure<T>

template <class T> class AbstractLinkedList: public IndexedDataStructure<T> {
    public:

      /**
       * @brief Prepends an element to the front of the list.
       * @param element Element to be prepended.
       * @return Bool value that indicates whether or not the insertion was successful or not.
       */
      virtual bool add_head(T element) = 0;

      /**
       * @brief Appends an element to the back of the list.
       * @param element Element to be appended.
       * @return Bool value that indicates whether or not the insertion was successful or not.
       */
      virtual bool add_tail(T element) = 0;

      /**
       * @brief Removes the last element from the back of the list.
       * @return Bool value that indicates whether or not the removal was successful or not.
       */
      virtual bool remove_tail() = 0;

      /**
       * @brief Removes the first element from the front of the list.
       * @return Bool value that indicates whether or not the insertion was removal or not.
       */
      virtual bool remove_head() = 0;
};

#endif // ABSTRACT_LINKED_LIST_H
