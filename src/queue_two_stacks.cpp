#include <iostream>
#include "../include/data_structures/Stack.hpp"

/**
 *
 */
template <class T> class Queue {
  private:
    Stack<T> stack_1;
    Stack<T> stack_2;
    int length = 0;

  public:
    void enqueue(T element) {
      stack_1.push(element);
      this->length++;
    }

    T dequeue() {
      T element;

      // Flip the stack upside down
      while (stack_1.size() > 0) {
        stack_2.push(stack_1.pop());
      }

      // Get the element at the top
      element = stack_2.pop();

      // Flip the stack back over
      while (stack_2.size() > 0) {
        stack_1.push(stack_2.pop());
      }

      this->length--;

      return element;
    }

    int size() {
      return this->length;
    }
};

//------------------------------------------------------------------------------

int main() {

  Queue<int> queue;

  // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
  for (int i = 1; i <= 20; i++) {
    queue.enqueue(i);
  }

  // Remove 1, 2, 3
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();

  // Appened 1
  queue.enqueue(1);

  // 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 1
  while (queue.size()) {
    std::cout << queue.dequeue() << " ";
  }

  std::cout << "\n";

  return 0;
}
