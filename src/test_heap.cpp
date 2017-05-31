#include <iostream>
#include "../include/data_structures/MinHeap.hpp"
#include "../include/data_structures/MaxHeap.hpp"
#include "../include/util/util.hpp"

int main() {
  MinHeap<int> min_heap;
  MaxHeap<int> max_heap;

  // Build min heap
  min_heap.insert(2);
  min_heap.insert(7);
  min_heap.insert(1);
  min_heap.insert(13);
  min_heap.insert(9);

  // Display min heap
  std::cout << "min_heap: ";
  util::display(min_heap.to_vector());
  std::cout <<"\n";

  std::cout << "size: " << min_heap.size() << "\n";

  // Build max heap from min heap
  while (min_heap.size() > 0) {
    std::cout << min_heap.poll() << " ";
  }


  std::cout << std::endl;

  return 0;
}
