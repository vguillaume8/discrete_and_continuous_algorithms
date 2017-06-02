#include <iostream>
#include "../include/data_structures/Heap.hpp"
#include "../include/data_structures/MaxHeap.hpp"
#include "../include/util/util.hpp"

int main() {
  Heap<int> heap;
  MaxHeap<int> min_heap;

  std::vector<int> array;
  array.push_back(15);
  array.push_back(3);
  array.push_back(2);
  array.push_back(1);
  array.push_back(9);
  array.push_back(5);

  // 1 2 3 15 9 5

  std::cout << "unorded: ";
  display(array);

  array = Heap<int>::sort(array);

  std::cout << "ordered descending: ";
  display(array);

  array = MaxHeap<int>::sort(array);

  std::cout << "ordered ascending: ";
  display(array);


  return 0;
}
