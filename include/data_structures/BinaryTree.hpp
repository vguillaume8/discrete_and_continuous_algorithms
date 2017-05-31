#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "VectorStructure.hpp"  // VectorStructure<T>

template <class T> class BinaryTree: public VectorStructure<T> {
  public:

  protected:
    int get_left_child(int index);
    int get_right_child(int index);
    int get_parent(int index);

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

#endif
