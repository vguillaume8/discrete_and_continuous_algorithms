/**
 * @brief Given an array S of n integers,
 are there elements a, b, c in S such that a + b + c = 0?
 Find all unique triplets in the array which gives the sum of zero.

https://leetcode.com/problems/3sum/#/description
 */

#include <iostream>
#include <vector>
#include "../include/util/util.hpp"
#include "../include/algorithms/sort.hpp"

void three_sum(std::vector<int>& vect) {
  int n = vect.size();
  int l;
  int r;
  int s;

  // Sort the vector O(n*log n)
  sort<int>::heap_sort(vect);

  for (int i = 0; i < n-3; i++) {

    if (i > 0 && vect[i] == vect[i-1]) {
      continue;
    }

    l = i+1;
    r = n-1;

    while (l < r) {
      s = vect[i] + vect[l] + vect[r];

      if (s < 0) {
        l++;
      }
      else if (s > 0) {
        r++;

      } else {
        std::cout << vect[l] << " " << vect[r] << " " << vect[i] << "\n";

        while (l < r && vect[l] == vect[l+1]) {
          l++;
        }

        while (l < r && vect[r] == vect[r-1]) {
          r--;
        }

        l++;
        r--;
      }
    }
  }
}

//------------------------------------------------------------------------------

int main() {

  std::vector<int> vect {
    -1, 0, 1, 2, -1, -4
  };

  three_sum(vect);

  return 0;
}
