/**
 * @file DataStructure.hpp
 * @version 1.0
 * @title DataStructure
 * @author Jabari Dash
 * @brief DataStructure Interface
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <vector>                // std::vector<T>
#include "AbstractObject.hpp"    // AbstractObject

template <class T> class DataStructure: public AbstractObject {
  public:

    /**
     * @brief Indicates whether the data structure contains a specified element.
     * @param element Specified element to check for.
     * @return True if the structure contains the specified element, otherwise false.
     */
    virtual bool contains(T element) = 0;

    /**
     * @brief Indicates whether or not the data structure is empty.
     * @return True if the structure has 0 elements, otherwise false.
     */
    virtual bool empty();

    /**
     * @brief Inserts a specified element into the data structure.
     * @param element Specified element to be inserted.
     * @return Boolean value indicating whether or not the element was successfully inserted.
     */
    virtual bool insert(T element) = 0;

    /**
     * @brief Returns, but does not remove the root element of the structure.
     * @return Value at the root of the structure.
     */
    virtual T peek() = 0;

    /**
     * @brief Returns and removes the first element of the structure.
     * @return Value at the root of the structure.
     */
    virtual T poll() = 0;

    /**
     * @brief Removes a specified element from the structure.
     * @param Specified element to be removed.
     * @return Boolean value as to whether or not the element was successfully removed.
     */
    virtual bool remove(T element) = 0;

    /**
     * @brief Determines the size as the number of elements in the structure.
     * @return The number of elements in the structure.
     */
    virtual int size();

    /**
     * @brief Converts the data structure into a printable string.
     * @return String representation of the structure.
     */
    virtual std::vector<T> to_vector() = 0;

  protected:

    /** @brief Number of elements in the structure. */
    int length = 0;
};

//------------------------------------------------------------------------------

template <class T> bool DataStructure<T>::empty() {
  return size() == 0 ? true : false;
}

//------------------------------------------------------------------------------

template <class T> int DataStructure<T>::size() {
  return length;
}

#endif // DATA_STRUCTURE_H
