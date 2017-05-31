#ifndef LINKED_LIST_NODE
#define LINKED_LIST_NODE

#include "DataType.hpp" // DataType

template <class T> class LinkedListNode: public DataType<T> {
  public:
    // Public attributes
    LinkedListNode* next;

    // Constructors
    LinkedListNode(T d);
};

//------------------------------------------------------------------------------

template <class T> LinkedListNode<T>::LinkedListNode(T t) {
  DataType<T>::value = t;
}

#endif
