/**
 * @file BinaryTree.hpp
 * @version 1.0
 * @title BinaryTree
 * @author Jabari Dash
 * @brief BinaryTree Interface
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "VectorStructure.hpp"    // VectorStructure<T>

template <class T> class BinaryTree: public VectorStructure<T> {
  public:

  protected:

    /**
     * @brief Returns the index of the left child of the specified parent index
     * @param parent Specified parent index
     * @return The integer index that corresponds to the left child of the parent index
     */
    int get_left_child(int parent);

    /**
     * @brief Returns the index of the right child of the specified parent index
     * @param parent Specified parent index
     * @return The integer index that corresponds to the right child of the parent index
     */
    int get_right_child(int parent);

    /**
     * @brief Returns the index of the parent of the specified child index
     * @param parent Specified child index
     * @return The integer index that corresponds to the child index
     */
    int get_parent(int child);

  private:
    virtual bool bubble_up(int index) = 0;
    virtual bool bubble_down(int index) = 0;
};

//------------------------------------------------------------------------------

template <class T> int BinaryTree<T>::get_left_child(int index) {
  return 2 * index + 1;
}

//------------------------------------------------------------------------------

template <class T> int BinaryTree<T>::get_right_child(int index) {
  return 2 * index + 2;
}

//------------------------------------------------------------------------------

template <class T> int BinaryTree<T>::get_parent(int index) {
  return (index - 1) / 2;
}

#endif // BINARY_TREE_H
