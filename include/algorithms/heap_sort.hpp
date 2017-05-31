#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>
#include "../data_structures/Heap.hpp"

template <class T> static std::vector<T> heap_sort(std::vector<T> array) {
  int size = array.size();
  Heap<T> heap;

  // Build heap
  for (int i = 0; i < size; i++) {
    heap.insert(array[i]);
  }

  // Remove all elements from heap, copying back into array
  for (int i = 0; i < size; i++) {
    array[i] = heap.remove();
  }

  return array;
}

#endif
