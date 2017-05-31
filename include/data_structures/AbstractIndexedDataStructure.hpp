#ifndef ABSTRACT_INDEXED_DATA_STRUCTURE_H
#define ABSTRACT_INDEXED_DATA_STRUCTURE_H

#include "DataStructure.hpp"

template <class T> class AbstractIndexedDataStructure: public DataStructure<T> {
  public:
    virtual T get(int index) = 0;
    virtual bool insert(T data, int index) = 0;
    virtual bool remove_from_index(int index) = 0;
    virtual bool set(T t, int index) = 0;
    virtual bool swap(int index_a, int index_b) = 0;

  protected:
    bool in_bounds(int index);
};

/*
* Returns true if and only if the index passed is within the bounds of the
* index data structure
*/
template <class T> bool AbstractIndexedDataStructure<T>::in_bounds(int index) {
  bool is_in_bounds = false;

  // what about when length == 0

  if (index >= 0 && index < DataStructure<T>::length) {
    is_in_bounds = true;
  }

  return is_in_bounds;
}

#endif
