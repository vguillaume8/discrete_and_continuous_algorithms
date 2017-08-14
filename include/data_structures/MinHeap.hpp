/**
 * @file MinHeap.hpp
 * @version 1.0
 * @title MinHeap
 * @author Jabari Dash
 * @brief Implementation of a min heap / priority queue with higher priority to lower values.
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <string>           // std::string
#include <vector>           // std::vector<T>
#include <stdexcept>        // std::out_of_range
#include "BinaryTree.hpp"   // BinaryTree<T>

// For heap insert() see:
// http://www.cs.umd.edu/~meesh/351/mount/lectures/lect14-heapsort-analysis-part.pdf
template <class T> class MinHeap: public BinaryTree<T> {
  public:
    // Constructors

    /**
     * @brief Constructs an empty heap.
     */
    MinHeap();

    /**
     * @brief Constructs a heap from the passed vector.
     * @param vect Vector of values that will populate the heap.
     */
    MinHeap(std::vector<T> array);

// Abstract methods to implement
//------------------------------------------------------------------------------
    /**
     * @brief Inserts a specified element into the data structure.
     * @param element Specified element to be inserted.
     * @return Boolean value indicating whether or not the element was successfully inserted.
     */
    bool insert(T element);

//------------------------------------------------------------------------------

    /**
     * @brief Indicates whether or not the data structure is empty.
     * @return True if the structure has 0 elements, otherwise false.
     */
    bool remove(T element);

//------------------------------------------------------------------------------

    /**
     * @brief Returns and removes the first element of the structure.
     * @return Value at the root of the structure.
     */
    T poll();

// Static methods
//------------------------------------------------------------------------------
    /**
     * @brief Bubble sorts a LinkedList
     * @param linked_list List to be sorted.
     * @return Returns a LinkedList sorted in ascending order.
     */
    static std::vector<T> sort(std::vector<T> array);

  protected:

    /** @brief Name of class. */
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

#endif // MIN_HEAP_H
