/**
 * @file IndexedDataStructure.hpp
 * @version 1.0
 * @title IndexedDataStructure
 * @author Jabari Dash
 * @brief All data structures that have indicies by nature (Linked Lists, Queues) implement this interface
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef ABSTRACT_INDEXED_DATA_STRUCTURE_H
#define ABSTRACT_INDEXED_DATA_STRUCTURE_H

#include "DataStructure.hpp"    // DataStructure<T>

template <class T> class IndexedDataStructure: public DataStructure<T> {
  public:

    /**
     * @brief get Returns the element at the despecified index.
     * @param index Index of the desired element.
     * @return The desired element from the provided index.
     */
    virtual T get(int index) = 0;

    /**
     * @brief insert Inserts the element at the specified index.
     * @param element The element to be inserted.
     * @param index Specified index in which the element will be inserted
     * @return Returns true if the element was inserted successfully, otherwise false.
     */
    virtual bool insert(T element, int index) = 0;

    /**
     * @brief remove_from_index Removes the element at the specified index.
     * @param index Specified index from which the element will be removed
     * @return Returns true if the element was inserted removed, otherwise false.
     */
    virtual bool remove_from_index(int index) = 0;

    /**
     * @brief set Overwrites the value at the specified index with the provideds element.
     * @param element The element to be inserted.
     * @param index Specified index in which the element will be inserted
     * @return Returns true if the element was inserted successfully, otherwise false.
     */
    virtual bool set(T element, int index) = 0;

    /**
    * @brief Swaps the values of two elements by their specified indicies.
    * @param index_a Specified index of the first element to be swapped from.
    * @param index_b Specified index of the second element to be swapped from.
    * @return Returns true if the elements at index_a and index_b were successfully swapped.
    */
    virtual bool swap(int index_a, int index_b) = 0;

  protected:

    /*
    * @brief Indicates whether or not the specified index is within the bounds of the data structure.
    * @param index Specified index.
    * @return Returns true if the index is less than the length of the size and greater than or equal to 0
    * for structures of size greater than 0. If the length is 0 (the structure is empty), false is returned.
    */
    bool in_bounds(int index);
};

//------------------------------------------------------------------------------

template <class T> bool IndexedDataStructure<T>::in_bounds(int index) {

  if (index >= 0 && index < DataStructure<T>::length && DataStructure<T>::length != 0) {
    return true;
  }

  return false;
}

#endif // ABSTRACT_INDEXED_DATA_STRUCTURE_H
