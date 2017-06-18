
#include <iostream>
#include "../include/data_structures/BinarySearchTree.hpp"
#include "../include/util/util.hpp"

int main() {

  std::vector<int> vect;

  vect.push_back(1);
  vect.push_back(0);
  vect.push_back(-1);
  vect.push_back(3);
  vect.push_back(4);
  vect.push_back(10);
  vect.push_back(8);
  vect.push_back(9);
  vect.push_back(2);
  vect.push_back(11);
  vect.push_back(12);

  BinarySearchTree<int> tree(vect);

  std::cout << "size: " << tree.size() << "\n";
  util::println(tree.to_string());

  std::cout << "\n";

  tree.poll();

  std::cout << "size: " << tree.size() << "\n";
  util::println(tree.to_string());

  return 0;
}
