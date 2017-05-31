#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <string>           // std::string
#include <vector>           // std::vector<T>
#include <stdexcept>        // std::out_of_range
#include "BinaryTree.hpp"   // BinaryTree<T>

template <class T> class MaxHeap: public BinaryTree<T> {
  public:
    // Constructors
    MaxHeap();
    MaxHeap(std::vector<T> array);

    // Abstract methods to implement
    bool insert(T t);
    bool remove(T t);
    T poll();

    // Static methods
    static std::vector<T> sort(std::vector<T> array);

  protected:
    static const std::string CLASS_NAME;

  private:
    bool bubble_up(int index);
    bool bubble_down(int index);
};

template <class T> const std::string MaxHeap<T>::CLASS_NAME = "MaxHeap<T>";

//------------------------------------------------------------------------------

template <class T> MaxHeap<T>::MaxHeap() {
  ;
}

//------------------------------------------------------------------------------

template <class T> MaxHeap<T>::MaxHeap(std::vector<T> array) {
  int size = array.size();

    // Build heap
  for (int i = 0; i < size; i++) {
    insert(array[i]);
  }
}

//------------------------------------------------------------------------------

template <class T> bool MaxHeap<T>::remove(T t) {
  bool removed = false;
  int n = BinaryTree<T>::size();
  int i = BinaryTree<T>::find(t);

  // If the list is empty
  if (BinaryTree<T>::empty()) {

    // Throw out of range exception
    std::out_of_range err("MaxHeap<T>::remove(T t): Heap is empty");
    throw err;

    // If the element was not found
  } else if (i == BinaryTree<T>::ELEMENT_NOT_FOUND) {
    removed = false;

    // Element found
  } else {
    BinaryTree<T>::elements[i] = BinaryTree<T>::elements.back();

    BinaryTree<T>::elements.pop_back();

    bubble_down(i);

    removed = true;
  }

  return removed;
}

//------------------------------------------------------------------------------

/*
* Insert node into heap
*/
template <class T> bool MaxHeap<T>::insert(T t) {
  // Add new element onto back of array
  BinaryTree<T>::elements.push_back(t);

  // Restore heap structure
  return bubble_up(BinaryTree<T>::size()-1);
}

//------------------------------------------------------------------------------

template <class T> T MaxHeap<T>::poll() {
  T root = BinaryTree<T>::elements[0];

  remove(root);

  // Return the element that was popped of top of heap
  return root;
}

//------------------------------------------------------------------------------

template <class T> bool MaxHeap<T>::bubble_up(int index) {

  // Indices for tracking child and parent nodes
  int parent;
  int child;

  // Start at back of array
  child = index;

  // While we are still in the bounds of the array, going from right to left
  while (child >= 1 && parent >= 0) {

    // Calculate index of parent
    parent = BinaryTree<T>::get_parent(child);

    // If parent is less than child, swap
    if (BinaryTree<T>::elements[parent] < BinaryTree<T>::elements[child]) {
      BinaryTree<T>::swap(child, parent);
    }

    // Keep track of element that we swap via index
    child = parent;
  }

  return true;
}

//------------------------------------------------------------------------------

template <class T> bool MaxHeap<T>::bubble_down(int index) {
  // Indices for tracking child and parent nodes
  int parent;
  int left_child;
  int right_child;
  int largest;
  int size = BinaryTree<T>::elements.size();

  // Start at front of array
  parent = index;

  while (true) {

    // Get children
    left_child = BinaryTree<T>::get_left_child(parent);
    right_child = BinaryTree<T>::get_right_child(parent);
    largest = parent;

    // If left child is greater than parent
    if (left_child < size && BinaryTree<T>::elements[left_child] > BinaryTree<T>::elements[largest]) {
      largest = left_child;
    }

    // If right child is greater than largest (parent or the left child at this point)
    if (right_child < size && BinaryTree<T>::elements[right_child] > BinaryTree<T>::elements[largest]) {
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

template <class T> std::vector<T> MaxHeap<T>::sort(std::vector<T> array) {

  // Build heap from array
  MaxHeap<T> heap(array);
  int size = array.size();

  // Remove all elements from heap, copying back into array
  for (int i = 0; i < size; i++) {
    array[i] = heap.poll();
  }

  return array;
}

#endif
