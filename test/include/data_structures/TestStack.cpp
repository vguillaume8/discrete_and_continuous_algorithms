#include "../include/data_structures/Stack.hpp"
#include "../include/util/util.hpp"
#include <iostream>

int main() {
  Stack<int> stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);

  util::display(stack.to_vector());

  while (stack.size() > 0) {
    std::cout << "size: " << stack.pop() << "\n";
  }

  return 0;
}
