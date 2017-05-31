#ifndef ABSTRACT_LINKED_LIST_H
#define ABSTRACT_LINKED_LIST_H

#include "AbstractIndexedDataStructure.hpp"

template <class T> class AbstractLinkedList: public AbstractIndexedDataStructure<T> {
    public:
      virtual bool add_head(T data) = 0;
      virtual bool add_tail(T data) = 0;
      virtual bool remove_tail() = 0;
      virtual bool remove_head() = 0;
};

#endif
