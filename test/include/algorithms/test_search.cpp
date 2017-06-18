#include <iostream>
#include <assert.h>
#include <vector>
#include "../../../include/algorithms/search.hpp"

/**
 * @brief Creates in integer vector of a specified length, where each value
 * at each index matches the index
 * @return The vector
 */
std::vector<int> init_vector(int length);

//------------------------------------------------------------------------------

int main() {

  // Build the vector
  std::vector<int> vect = init_vector(10);
  int length = vect.size();

  // Index should match the value at that index
  for (int i = 0; i < length; i++) {
    assert(i == binary_search_iterative(i, vect));
    assert(i == binary_search_recursive(i, vect, 0, length-1));
  }

  return 0;
}

//------------------------------------------------------------------------------

std::vector<int> init_vector(int length) {
  std::vector<int> vect;

  for (int i = 0; i < length; i++) {
    vect.push_back(i);
  }

  return vect;
}
