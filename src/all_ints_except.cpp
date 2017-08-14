/**
 * You have a vector of integers, and for each index you
 * want to find the product of every integer except the
 * integer at that index.
 * Write a function getProductsOfAllIntsExceptAtIndex()
 * that takes a vector of integers and returns a vector of the products.
 */

#include <iostream>
#include <vector>
#include "../include/util/util.hpp"

std::vector<int> get_all_products(std::vector<int> vect) {
  int product;
  std::vector<int> new_vect;

  for (int i = 0; vect[i]; i++) {
    product = 1;

    for (int j = 0; vect[j]; j++) {

        i != j ? product *= vect[j] : product;
    }
    new_vect.push_back(product);
  }

  return new_vect;
}

//------------------------------------------------------------------------------

int main() {
  std::vector<int> vect {
    1,7,3,4
  };

  std::vector<int>combinations;
  combinations = get_all_products(vect);

  util::display(combinations);

  return 0;
}
