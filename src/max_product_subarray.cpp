#include <iostream>
#include <vector>
#include "../include/util/util.hpp"
#include "../include/algorithms/sort.hpp"
#include "../include/data_structures/Stack.hpp"


// https://leetcode.com/problems/maximum-product-subarray/#/solutions

std::vector<int>* max_product_noncontiguous(std::vector<int>& vect) {
  std::vector<int>* vect_2 = new std::vector<int>();

  // O(n*log n)
  sort<int>::heap_sort(vect);

  for (int i = vect.size()-1; vect[i] >= 1; i--) {
    vect_2->push_back(vect[i]);
  }

  return vect_2;
}

//------------------------------------------------------------------------------

/**
 * @brief Ignores negative numbers
 * time O(n), space O(n)
 */
std::vector<int> max_product_contiguous(std::vector<int>& vect) {
  int f_max = 0;
  int t_max = 1;

  int c = 0;    // Count number of multiplications
  int x = 0;    // start subarray index (inclusive)
  int y = 0;    // stop subarray index (not inclusive)

  for (int i = 0; i < vect.size(); i++) {

    // Keep multiplying while vect[i] is positive
    // count number of multiplications
    if (vect[i] > 0) {
      t_max *= vect[i];
      c++;

    // Otherwise, resert the running max
    // And start our count over
    } else {
      c = 0;
      t_max = 1;
    }

    // If running max is larger than old, save new
    // And count backwards 'c-1' steps to find where subarray started
    if (t_max > f_max) {
      f_max = t_max;
      y = i;
      x = y-c+1;
    }
  }

  std::cout << "max prod:" << f_max << "\n";

  std::vector<int>::const_iterator first = vect.begin() + x;
  std::vector<int>::const_iterator last = vect.begin() + y + 1;
  std::vector<int> vect_2(first, last);

  return vect_2;
}

//------------------------------------------------------------------------------

// TODO - UNSOLVED
int main() {
  std::vector<int> vect {
    -1,8,7,0,1,2,8,0
  };

  util::display(vect);

  std::vector<int> vect_2 = max_product_contiguous(vect);
  std::cout << "Max vect: ";
  util::display(vect_2);

  return 0;
}
