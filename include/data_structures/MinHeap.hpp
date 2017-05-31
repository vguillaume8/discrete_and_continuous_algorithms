#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <string>           // std::string
#include <vector>           // std::vector<T>
#include <stdexcept>        // std::out_of_range
#include "BinaryTree.hpp"   // BinaryTree<T>

// For heap insert() see:
// http://www.cs.umd.edu/~meesh/351/mount/lectures/lect14-heapsort-analysis-part.pdf
template <class T> class MinHeap: public BinaryTree<T> {
  public:
    // Constructors
    MinHeap();
    MinHeap(std::vector<T> array);

    // Abstract methods to implement
    bool insert(T element);
    bool remove(T element);
    T poll();

    // Static methods
    static std::vector<T> sort(std::vector<T> array);

  protected:
    static const std::string CLASS_NAME;

  private:
    bool bubble_up(int index);
    bool bubble_down(int index);
};

template <class T> const std::string MinHeap<T>::CLASS_NAME = "MinHeap<T>";

//------------------------------------------------------------------------------

template <class T> MinHeap<T>::MinHeap() {
  ;
}

//------------------------------------------------------------------------------

template <class T> MinHeap<T>::MinHeap(std::vector<T> array) {
  int size = array.size();

  // Build heap via repeated insertion
  for (int i = 0; i < size; i++) {
    insert(array[i]);
  }
}

//------------------------------------------------------------------------------

template <class T> bool MinHeap<T>::remove(T element) {
  bool removed = false;
  int n = BinaryTree<T>::size();
  int i = BinaryTree<T>::find(element);

  // If the list is empty
  if (BinaryTree<T>::empty()) {

    // Throw out of range exception
    std::out_of_range err("MinHeap<T>::remove(T t): Heap is empty");
    throw err;

    // If the element was not found
  } else if (i == BinaryTree<T>::ELEMENT_NOT_FOUND) {
    removed = false;

    // Element found
  } else {
    BinaryTree<T>::elements[i] = BinaryTree<T>::elements.back();

    BinaryTree<T>::pop_back();

    bubble_down(i);

    removed = true;
  }

  return removed;
}

//------------------------------------------------------------------------------

/*
* Insert node into heap
*/
template <class T> bool MinHeap<T>::insert(T element) {

  // Add new element onto back of array
  BinaryTree<T>::push_back(element);

  // Restore heap structure
  return bubble_up(BinaryTree<T>::size()-1);
}

//------------------------------------------------------------------------------

template <class T> bool MinHeap<T>::bubble_up(int index) {
  int parent;
  int child;

  // Start at back of array
  child = index;
  parent = BinaryTree<T>::get_parent(child);

  while (child > 0) {

    // If the parent is greater, swap
    if (BinaryTree<T>::elements[child] < BinaryTree<T>::elements[parent]) {

      // Swap the child and the parent
      BinaryTree<T>::swap(child, parent);

      child = parent;
      parent = BinaryTree<T>::get_parent(child);

    } else {
      break;
    }
  }
  return true;
}

//------------------------------------------------------------------------------

template <class T> bool MinHeap<T>::bubble_down(int index) {

  // Indices for tracking child and parent nodes
  int parent;
  int left_child;
  int right_child;
  int largest;
  int size = BinaryTree<T>::size();

  // Start at front of array
  parent = index;

  while (true) {

    // Get children
    left_child = BinaryTree<T>::get_left_child(parent);
    right_child = BinaryTree<T>::get_right_child(parent);

    // Start with largest being the parent
    largest = parent;

    // If left child is greater than parent
    if (left_child < size && BinaryTree<T>::elements[left_child] < BinaryTree<T>::elements[largest]) {
      largest = left_child;
    }

    // If right child is greater than largest (parent or the left child at this point)
    if (right_child < size && BinaryTree<T>::elements[right_child] < BinaryTree<T>::elements[largest]) {
      largest = right_child;
    }

    // If the index of the largest element has change, then we must swap
    if (largest != parent) {
      BinaryTree<T>::swap(parent, largest);

      parent = largest;

      // If now, we have a valid heap structure, and the largest is at the top
    } else {
      break;
    }
  }
  return true;
}

//------------------------------------------------------------------------------

template <class T> T MinHeap<T>::poll() {
  T root = BinaryTree<T>::elements[0];

  remove(root);

  // Return the element that was popped of top of heap
  return root;
}

//------------------------------------------------------------------------------

template <class T> std::vector<T> MinHeap<T>::sort(std::vector<T> array) {

  // Build heap from array
  MinHeap<T> heap(array);
  int size = heap.size();

  // Remove all elements from heap, copying into array
  for (int i = 0; i < size; i++) {
    array[i] = heap.poll();
  }

  return array;
}

#endif
