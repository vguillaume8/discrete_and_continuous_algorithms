#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>                     // std::string
#include <vector>                     // std::vector<T>
#include <stdexcept>                  // std::out_of_range
#include "BinarySearchTreeNode.hpp"   // BinarySearchTreeNode<T>
#include "DataStructure.hpp"          // DataStructure
#include "../util/util.hpp"           // util::to_string(std::vector<T>)

/**
* Binary Search Tree implemented as a linked node tree
*/
template <class T> class BinarySearchTree: public DataStructure<T> {
  public:
    // Constructors
    BinarySearchTree();
    BinarySearchTree(std::vector<T> vect);

    // Public methods from DataStructure
    bool contains(T t);
    bool insert(T t);
    T peek();
    T poll();
    bool remove(T t);
    std::string to_string();
    std::vector<T> to_vector();

    // Instance methods
    std::vector<T> to_vector_in_order();
    std::vector<T> to_vector_pre_order();
    std::vector<T> to_vector_post_order();

    // Static
    static std::vector<T> sort(std::vector<T> vect);

  protected:
    // Protected attributes
    static const std::string CLASS_NAME;

  private:
    // Private attributes
    BinarySearchTreeNode<T>* root_node;

    // Private helper methods
    bool contains(T t, BinarySearchTreeNode<T>* node);
    BinarySearchTreeNode<T>* find(T element, BinarySearchTreeNode<T>* node);
    bool remove(BinarySearchTreeNode<T>* node);
    void to_vector(BinarySearchTreeNode<T>* node, std::vector<T>& vect);
    void to_vector_in_order(BinarySearchTreeNode<T>* node, std::vector<T>& vect);
    void to_vector_pre_order(BinarySearchTreeNode<T>* node, std::vector<T>& vect);
    void to_vector_post_order(BinarySearchTreeNode<T>* node, std::vector<T>& vect);
};

// Name of class for use in error messages
template <class T> const std::string BinarySearchTree<T>::CLASS_NAME = "BinarySearchTree<T>";

//------------------------------------------------------------------------------

/**
* Constructs an empty tree
*/
template <class T> BinarySearchTree<T>::BinarySearchTree() {
  root_node = NULL;
  DataStructure<T>::length = 0;
}

//------------------------------------------------------------------------------

/**
* Constructs a tree provided a std::vector<T> as input.
*/
template <class T> BinarySearchTree<T>::BinarySearchTree(std::vector<T> vect) {

  // Construct empty tree
  root_node = NULL;
  DataStructure<T>::length = 0;

  // Get number of elements in vector
  int n = vect.size();

  // Insert all elements from vector into tree
  for (int i = 0; i < n; i++) {
    insert(vect[i]);
  }
}

//------------------------------------------------------------------------------

/**
* Returns a vector sorted in ascending order (lowest starting at index 0) via
* tree sort.
*/
template <class T> std::vector<T> BinarySearchTree<T>::sort(std::vector<T> vect) {
  BinarySearchTree<T> tree(vect);

  return tree.to_vector_in_order();
}


//------------------------------------------------------------------------------

/**
* Inserts an element into the tree
*/
template <class T> bool BinarySearchTree<T>::insert(T element) {
  bool inserted = false;

  // If the list is empty
  if (DataStructure<T>::empty() == true) {

    // Make new node at root
    root_node = new BinarySearchTreeNode<T>(element, NULL);

    // Increment length
    DataStructure<T>::length++;

    // Insert successful
    inserted = true;

    // If the list is not empty
  } else if (root_node->insert(element) == true) {

    // Increment length
    DataStructure<T>::length++;

    // Insert successful
    inserted = false;

  }

  return inserted;
}

//------------------------------------------------------------------------------

/**
* Returns the value of the root node of the tree without removing it
*/
template <class T> T BinarySearchTree<T>::peek() {

  // If the tree is empty
  if (DataStructure<T>::empty()) {
    std::string message;

    message += CLASS_NAME + "::peek() " + CLASS_NAME + " is empty";

    // Throw error
    throw std::out_of_range(message);
  }

  return root_node->get_value();
}

//------------------------------------------------------------------------------

/**
* Removes and returns the value of the root node of the tree.
*/
template <class T> T BinarySearchTree<T>::poll() {
  T element;

  try {

    // Get the element at the root
    element = peek();

    remove(element);

    // Error thrown if tree is empty
  } catch(std::out_of_range& error) {
    std::string message;

    message += CLASS_NAME + "::poll() " + CLASS_NAME + " is empty\n" + error.what() + "\n";

    // Throw error
    throw std::out_of_range(message);
  }

  return element;
}

//------------------------------------------------------------------------------

/**
* Removes a given element from the tree
*/
template <class T> bool BinarySearchTree<T>::remove(T element) {
  bool removed = false;

  // Find the element
  BinarySearchTreeNode<T>* node = find(element, root_node);

  // If nothing came back
  if (node == NULL) {
    return false;
  }

  // Remove via private remove method
  return remove(node);
}

//------------------------------------------------------------------------------

/**
* Removes a given node from the tree and restores the binary search tree structure.
*/
template <class T> bool BinarySearchTree<T>::remove(BinarySearchTreeNode<T>* node) {
  bool removed = false;

  // If the node is null, no work to do, return
  if (node == NULL) {
    return false;

    // There is a node to remove
  } else {

    // we are at root, no parent, no children
    if (node->parent == NULL && node->right_child == NULL && node->left_child == NULL) {
      root_node = NULL;

      // Decrement counter
      DataStructure<T>::length--;

      //Remove successful
      removed = true;

      // We are not at a parent, and we need to need to bubble the children node up
      // to replace the node in the middle of the tree
    } else if (node->left_child != NULL || node->right_child != NULL) {

      // If there is a right child
      if (node->right_child != NULL) {

        // Shift all nodes from right up
        while (node->right_child != NULL) {

          // Bring right child node's value up one level
          node->set_value(node->right_child->get_value());

          // Get right left child
          node = node->right_child;
        }

        // Delete the last node after its value has been copied
        node->parent->right_child = NULL;

        // If there is a left child
      } else if (node->left_child != NULL) {

        // Shift all nodes from left up
        while (node->left_child != NULL) {

          // Bring right child node's value up one level
          node->set_value(node->left_child->get_value());

          // Get next left child
          node = node->left_child;
        }

        // Delete the last node after its value has been copied
        node->parent->left_child = NULL;

        // We are at a leaf node (no children)
      }
      // We are at a leaf node, but we do not know if this leaf node is a left child
      // or a right child
    } else {

      // If this node is a left child
      if (node == node->parent->left_child) {

        // Remove the parent's left child
        node->parent->left_child = NULL;
      }

      // If this node is a right child
      else if (node == node->parent->right_child) {

        // Remove the parent's right child
        node->parent->right_child = NULL;
      }
    }

    // If we have made it to this point, the node has been removed and the
    // binary search tree structure has been restored

    // Decrement length
    DataStructure<T>::length--;

    // Removal successful
    removed = true;
  }

  return removed;
}

//------------------------------------------------------------------------------

/**
* Returns true if the tree contains a given element
*/
template <class T> bool BinarySearchTree<T>::contains(T element) {
  return contains(element, root_node);
}

//------------------------------------------------------------------------------

/**
* Returns true if the tree contains a given element.
*/
template <class T> bool BinarySearchTree<T>::contains(T element, BinarySearchTreeNode<T>* node) {

  // If we cannot find the node, return null
  if (find(element, node) == NULL) {
    return false;
  }

  return true;
}


//------------------------------------------------------------------------------

/**
* Finds and returns the pointer of a given element via binary search. NULL is returned
* if the element is not found.
*/
template <class T> BinarySearchTreeNode<T>* BinarySearchTree<T>::find(T element, BinarySearchTreeNode<T>* node) {

  // If we are at a leaf node's child (NULL), we have search as far as we can go
  // and we have not found the element. Thus, we return null
  if (node == NULL || DataStructure<T>::empty()) {
    return NULL;
  }

  // If we found node, return the node pointer
  if (element == node->get_value()) {
    return node;
  }

  // If the element's value is smaller than the current node's value, go left
  if (element < node->get_value()) {
    return find(element, node->left_child);
  }

  // If the element's value is greater than the current node's value, go right
  else if (element > node->get_value()) {
    return find(element, node->right_child);
  }
}

//------------------------------------------------------------------------------

/**
* Returns the tree as a string in pre order
*/
template <class T> std::string BinarySearchTree<T>::to_string() {
  return util::to_string(to_vector());
}

//------------------------------------------------------------------------------

/**
* Returns the tree as a vector in pre order
*/
template <class T> std::vector<T> BinarySearchTree<T>::to_vector() {
  std::vector<T> vect;
  to_vector(root_node, vect);

  return vect;
}

//------------------------------------------------------------------------------

/**
* Returns the tree as a vector in ascending order
*/
template <class T> std::vector<T> BinarySearchTree<T>::to_vector_in_order() {
  std::vector<T> vect;
  to_vector_in_order(root_node, vect);

  return vect;
}
//------------------------------------------------------------------------------

/**
* Returns the tree as a vector in pre order
*/
template <class T> std::vector<T> BinarySearchTree<T>::to_vector_pre_order() {
  std::vector<T> vect;
  to_vector_pre_order(root_node, vect);

  return vect;
}

//------------------------------------------------------------------------------

/**
* Returns the tree as a vector in descending order
*/
template <class T> std::vector<T> BinarySearchTree<T>::to_vector_post_order() {
  std::vector<T> vect;
  to_vector_post_order(root_node, vect);

  return vect;
}

//------------------------------------------------------------------------------

/**
* Returns the tree as a vector in pre order
*/
template <class T> void BinarySearchTree<T>::to_vector(BinarySearchTreeNode<T>* node, std::vector<T>& vect) {
  to_vector_pre_order(node, vect);
}

//------------------------------------------------------------------------------

/**
* In order traversal
*/
template <class T> void BinarySearchTree<T>::to_vector_in_order(BinarySearchTreeNode<T>* node, std::vector<T>& vect) {

  if (node != NULL) {
    to_vector_in_order(node->left_child, vect);
    vect.push_back(node->get_value());
    to_vector_in_order(node->right_child, vect);
  }
}

//------------------------------------------------------------------------------

/**
* Pre order traversal
*/
template <class T> void BinarySearchTree<T>::to_vector_pre_order(BinarySearchTreeNode<T>* node, std::vector<T>& vect) {

  if (node != NULL) {
    vect.push_back(node->get_value());
    to_vector_pre_order(node->left_child, vect);
    to_vector_pre_order(node->right_child, vect);
  }
}

//------------------------------------------------------------------------------

/**
* Post order traversal
*/
template <class T> void BinarySearchTree<T>::to_vector_post_order(BinarySearchTreeNode<T>* node, std::vector<T>& vect) {

  if (node != NULL) {
    to_vector_post_order(node->right_child, vect);
    vect.push_back(node->get_value());
    to_vector_post_order(node->left_child, vect);
  }
}

#endif
