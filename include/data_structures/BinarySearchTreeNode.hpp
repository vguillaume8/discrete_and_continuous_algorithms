#ifndef BINARY_SEARCH_TREE_NODE
#define BINARY_SEARCH_TREE_NODE

#include "DataType.hpp" // DataType

/**
* Node in BinarySearchTree
*/
template <class T> class BinarySearchTreeNode: public DataType<T> {
  public:
    // Attributes
    BinarySearchTreeNode<T>* parent;
    BinarySearchTreeNode<T>* left_child;
    BinarySearchTreeNode<T>* right_child;

    // Constructor
    BinarySearchTreeNode(T element, BinarySearchTreeNode<T>* p);

    // Instance methods
    bool insert(T element);
};

//------------------------------------------------------------------------------

/**
* Constructs a node
*/
template <class T> BinarySearchTreeNode<T>::BinarySearchTreeNode(T element, BinarySearchTreeNode<T>* p) {
  parent = p;
  left_child = NULL;
  right_child = NULL;

  DataType<T>::value = element;
}

//------------------------------------------------------------------------------

template <class T> bool BinarySearchTreeNode<T>::insert(T element) {

  // If the value is already in the tree
  if (element == DataType<T>::value) {
    return false;

    // If the value is less than, go left
  } else if (element < DataType<T>::value) {

    // if left child is null, create new node as left child
    if (left_child == NULL) {

      left_child = new BinarySearchTreeNode<T>(element, this);

      return true;

      // Otherwise, attempt to insert one level lower, going left
    } else {

      return left_child->insert(element);
    }

    // If the value is greater than, go right
  } else if (element > DataType<T>::value) {

    // If the right child is null, create a new node as right child
    if (right_child == NULL) {

      right_child = new BinarySearchTreeNode<T>(element, this);

      return true;

      // Otherwise, attempt to insert one level lower, going right
    } else {

      return right_child->insert(element);
    }
  }
}

#endif
