#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <vector>
#include "AbstractObject.hpp"

template <class T> class DataStructure: public AbstractObject {
  public:
    virtual bool contains(T t) = 0;
    virtual bool empty();
    virtual bool insert(T t) = 0;
    virtual T peek() = 0;
    virtual T poll() = 0;
    virtual bool remove(T t) = 0;
    virtual int size();
    virtual std::vector<T> to_vector() = 0;

  protected:
    int length = 0;
};

//------------------------------------------------------------------------------

/*
* Returns true if and only if there are 0 elements in the data structure, otherwise, it
* returns false;
*/
template <class T> bool DataStructure<T>::empty() {
  return size() == 0 ? true : false;
}

//------------------------------------------------------------------------------

template <class T> int DataStructure<T>::size() {
  return length;
}

#endif
