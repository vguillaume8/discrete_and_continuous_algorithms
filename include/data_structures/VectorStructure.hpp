#ifndef VECTOR_STRUCTURE_H
#define VECTOR_STRUCTURE_H

#include <stdlib.h>
#include <string>
#include "../util/util.hpp"
#include "DataStructure.hpp"

template <class T> class VectorStructure: public DataStructure<T> {
  public:
    // Abstract methods from DataStructure to implement
    bool contains(T t);
    std::string to_string();
    std::vector<T> to_vector();
    T peek();
    bool pop_back();
    bool push_back(T element);

  protected:
    // Attributes
    std::vector<T> elements;
    static const int ELEMENT_NOT_FOUND = -1;
    static const std::string CLASS_NAME;

    // Instance methods
    int find(T t);
    bool swap(int index_a, int index_b);
};

template <class T> const std::string VectorStructure<T>::CLASS_NAME = "VectorStructure<T>";

//------------------------------------------------------------------------------

/*
* Swaps two elements in vector
*/
template <class T> bool VectorStructure<T>::swap(int index_a, int index_b) {
  int n = DataStructure<T>::size();
  std::string message;

  // Throw error if index a is out of bounds
  if (index_a >= n || index_a < 0) {
    std::string index_a_str = std::to_string(index_a);

    // VectorStructure<T>::swap() VectorStructure<T> is empty
    message += CLASS_NAME + "::swap() index_a: " + index_a_str + " is out of vector bounds\n";

    // Throw error
    throw std::out_of_range(message);

    // Throw error if index a is out of bounds
  } else if (index_b >= n || index_b < 0) {
    std::string index_b_str = std::to_string(index_b);

    // VectorStructure<T>::swap() VectorStructure<T> is empty
    message += CLASS_NAME + "::swap() index_b: " + index_b_str + " is out of vector bounds\n";

    // Throw error
    throw std::out_of_range(message);

    // If both indicies a and b are within the bounds of the vector
  } else {

    // Swap their places
    T temp = elements[index_a];
    elements[index_a] = elements[index_b];
    elements[index_b] = temp;
  }

  return true;
}

//------------------------------------------------------------------------------

template <class T> bool VectorStructure<T>::contains(T t) {
  bool found = false;
  int n = DataStructure<T>::size();

  // Linear search for simplicity
  for (int i = 0; i < n; i++) {
    if (VectorStructure<T>::elements[i] == t) {
      found = true;
      break;
    }
  }

  return found;
}

//------------------------------------------------------------------------------

template <class T> int VectorStructure<T>::find(T t) {
  int index = ELEMENT_NOT_FOUND;
  int n = DataStructure<T>::size();
  T element;

  // Linear search (for simplicity), override for logarithmic search
  for (int i = 0; i < n; i++) {
    element = elements[i];

    // If we find first instance of element
    if (element == t) {
      index = i;
      break;
    }
  }
  return index;
}

//------------------------------------------------------------------------------

template <class T> std::string VectorStructure<T>::to_string() {
  return util::to_string(to_vector());
}

//------------------------------------------------------------------------------

template <class T> std::vector<T> VectorStructure<T>::to_vector() {
  return elements;
}

//------------------------------------------------------------------------------

template <class T> T VectorStructure<T>::peek() {
  if (DataStructure<T>::empty() == true) {
    std::string message;

    // VectorStructure<T>::peek() VectorStructure<T> is empty
    message += CLASS_NAME + "::peek() " + CLASS_NAME + " is empty";

    throw std::out_of_range(message);
  }

  return elements[0];
}

//------------------------------------------------------------------------------

template <class T> bool VectorStructure<T>::pop_back() {
  elements.pop_back();

  // Decrement length
  DataStructure<T>::length--;

  return true;
}

//------------------------------------------------------------------------------

template <class T> bool VectorStructure<T>::push_back(T element) {
  elements.push_back(element);

  // Increment length
  DataStructure<T>::length++;

  return true;
}

#endif
