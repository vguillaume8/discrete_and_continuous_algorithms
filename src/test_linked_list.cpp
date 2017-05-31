#include <iostream>
#include "../include/data_structures/LinkedListNode.hpp"
#include "../include/data_structures/LinkedList.hpp"

template <class T> void display(LinkedList<T>& linked_list);

int main() {

  std::vector<int> vect;

  vect.push_back(10);
  vect.push_back(-3);
  vect.push_back(70);
  vect.push_back(-2);
  vect.push_back(1);
  vect.push_back(-1);
  vect.push_back(7);

  LinkedList<int> linked_list(vect);


  std::cout << linked_list.to_string() << "\n\n";

  linked_list = LinkedList<int>::sort(linked_list);

  std::cout << linked_list.to_string() << "\n\n";

  return 0;
}
