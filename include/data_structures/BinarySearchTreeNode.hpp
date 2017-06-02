/**
 * @file BinarySearchTreeNode.hpp
 * @version 1.0
 * @title BinarySearchTreeNode
 * @author Jabari Dash
 * @brief Node in linked binary search tree
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef BINARY_SEARCH_TREE_NODE
#define BINARY_SEARCH_TREE_NODE

#include "DataType.hpp"    // DataType<T>

template <class T> class BinarySearchTreeNode: public DataType<T> {
  public:
    // Attributes
    BinarySearchTreeNode<T>* parent;
    BinarySearchTreeNode<T>* left_child;
    BinarySearchTreeNode<T>* right_child;

    // Constructor

    /**
     * @brief Constructs a tree node
     * @param element The value of that the node will hold.
     * @param p Pointer to parent node.
     */
    BinarySearchTreeNode(T element, BinarySearchTreeNode<T>* p);

    // Instance methods

    /**
     * @brief Inserts an element into the tree.
     * @param element The element to be inserted into the list.
     * @return Bool value that indicates whether or not the element was successfully inserted.
     */
    bool insert(T element);
};

//------------------------------------------------------------------------------

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

      // Recursive call to insert into left child
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

      // Recursive call to insert into right child
      return right_child->insert(element);
    }
  }
}

#endif // BINARY_SEARCH_TREE_NODE_H
