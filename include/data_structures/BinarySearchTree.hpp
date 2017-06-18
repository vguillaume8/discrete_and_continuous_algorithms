/**
 * @file BinarySearchTree.hpp
 * @version 1.0
 * @title BinarySearchTree
 * @author Jabari Dash
 * @brief Implementation of a BinarySearchTree via linked BinarySearchTreeNodes.
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>                     // std::string
#include <vector>                     // std::vector<T>
#include <stdexcept>                  // std::out_of_range
#include "DataStructure.hpp"          // DataStructure<T>
#include "BinarySearchTreeNode.hpp"   // BinarySearchTreeNode<T>
#include "../util/util.hpp"           // util::to_string(std::vector<T>)

template <class T> class BinarySearchTree: public DataStructure<T> {
  public:
// Constructors
//------------------------------------------------------------------------------

    /**
     * @brief Constructs an empty tree.
     */
    BinarySearchTree();

    /**
     * @brief Constructs tree from a vector.
     * @param vect Vector of elements that will be inserted into the tree.
     */
    BinarySearchTree(std::vector<T> vect);

// Public methods from DataStructure
//------------------------------------------------------------------------------

    /**
     * @brief Indicates whether or not a specified element is in the tree.
     * @param Specified element to search for.
     * @return Boolean value as to whether or not the tree contains the specified element.
     */
    bool contains(T element);

    /**
     * @bried Inserts a specified element into the tree.
     * @param Specified element to be inserted.
     * @return Boolean value as to whether or not the insertion was successful/
     */
    bool insert(T element);

    /**
     * @brief Returns, but does not remove the root element of the tree.
     * @return Value at the root of the tree.
     */
    T peek();

    /**
     * @brief Returns and removes the root element of the tree.
     * @return Value at the root of the tree.
     */
    T poll();

    /**
     * @brief Removes a specified element from the tree.
     * @param Specified element to be removed.
     * @return Boolean value as to whether or not the element was successfully removed.
     */
    bool remove(T element);

    /**
     * @brief Pre order traversal
     * @return Returns string of elements from the tree in pre order.
     */
    std::string to_string();

    /**
     * @brief Pre order traversal
     * @return Returns vector of elements from the tree in pre order.
     */
    std::vector<T> to_vector();

// Instance methods
//------------------------------------------------------------------------------
    /**
     * @brief In order traversal
     * @return Returns vector of elements from the tree in lexographical order.
     */
    std::vector<T> to_vector_in_order();

    /**
     * @brief Pre order traversal
     * @return Returns vector of elements from the tree in pre order.
     */
    std::vector<T> to_vector_pre_order();

    /**
     * @brief Post order traversal
     * @return Returns vector of elements from the tree in post order.
     */
    std::vector<T> to_vector_post_order();

// Static methods
//------------------------------------------------------------------------------
    /**
     * @brief Implementation of tree sort. Builds a binary tree, and places elements into
     * array in ascending order via in-order traversal.
     * @param vect Vector of elements to be sorted
     * @return Returns a vector of lexographically sorted elements.
     */
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

template <class T> BinarySearchTree<T>::BinarySearchTree() {
  root_node = NULL;
  DataStructure<T>::length = 0;
}

//------------------------------------------------------------------------------

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

template <class T> std::vector<T> BinarySearchTree<T>::sort(std::vector<T> vect) {
  BinarySearchTree<T> tree(vect);

  return tree.to_vector_in_order();
}

//------------------------------------------------------------------------------

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

template <class T> T BinarySearchTree<T>::peek() {

  // If the tree is empty
  if (DataStructure<T>::empty()) {
    std::string message;

    // Error message
    message += CLASS_NAME + "::peek() " + CLASS_NAME + " is empty";

    // Throw error
    throw std::out_of_range(message);
  }

  return root_node->get_value();
}

//------------------------------------------------------------------------------

template <class T> T BinarySearchTree<T>::poll() {
  T element;

  try {

    // Get the element at the root
    element = peek();

    remove(element);

    // Error thrown if tree is empty
  } catch(std::out_of_range& error) {
    std::string message;

    // Error message
    message += CLASS_NAME + "::poll() " + CLASS_NAME + " is empty\n" + error.what() + "\n";

    // Throw error
    throw std::out_of_range(message);
  }

  return element;
}

//------------------------------------------------------------------------------

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

template <class T> bool BinarySearchTree<T>::contains(T element) {
  return contains(element, root_node);
}

//------------------------------------------------------------------------------

template <class T> bool BinarySearchTree<T>::contains(T element, BinarySearchTreeNode<T>* node) {

  // If we cannot find the node, return null
  if (find(element, node) == NULL) {
    return false;
  }

  return true;
}


//------------------------------------------------------------------------------

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

template <class T> std::string BinarySearchTree<T>::to_string() {
  return util::to_string(to_vector());
}

//------------------------------------------------------------------------------

template <class T> std::vector<T> BinarySearchTree<T>::to_vector() {
  std::vector<T> vect;
  to_vector(root_node, vect);

  return vect;
}

//------------------------------------------------------------------------------

template <class T> std::vector<T> BinarySearchTree<T>::to_vector_in_order() {
  std::vector<T> vect;
  to_vector_in_order(root_node, vect);

  return vect;
}
//------------------------------------------------------------------------------

template <class T> std::vector<T> BinarySearchTree<T>::to_vector_pre_order() {
  std::vector<T> vect;
  to_vector_pre_order(root_node, vect);

  return vect;
}

//------------------------------------------------------------------------------

template <class T> std::vector<T> BinarySearchTree<T>::to_vector_post_order() {
  std::vector<T> vect;
  to_vector_post_order(root_node, vect);

  return vect;
}

//------------------------------------------------------------------------------

template <class T> void BinarySearchTree<T>::to_vector(BinarySearchTreeNode<T>* node, std::vector<T>& vect) {
  to_vector_pre_order(node, vect);
}

//------------------------------------------------------------------------------

template <class T> void BinarySearchTree<T>::to_vector_in_order(BinarySearchTreeNode<T>* node, std::vector<T>& vect) {

  if (node != NULL) {
    to_vector_in_order(node->left_child, vect);
    vect.push_back(node->get_value());
    to_vector_in_order(node->right_child, vect);
  }
}

//------------------------------------------------------------------------------

template <class T> void BinarySearchTree<T>::to_vector_pre_order(BinarySearchTreeNode<T>* node, std::vector<T>& vect) {

  if (node != NULL) {
    vect.push_back(node->get_value());
    to_vector_pre_order(node->left_child, vect);
    to_vector_pre_order(node->right_child, vect);
  }
}

//------------------------------------------------------------------------------

template <class T> void BinarySearchTree<T>::to_vector_post_order(BinarySearchTreeNode<T>* node, std::vector<T>& vect) {

  if (node != NULL) {
    to_vector_post_order(node->right_child, vect);
    vect.push_back(node->get_value());
    to_vector_post_order(node->left_child, vect);
  }
}

#endif // BINARY_SEARCH_TREE_H
