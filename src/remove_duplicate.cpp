/**
 * @brief Given a sorted array, remove the duplicates in place
 *  such that each element appear only once and return the new length.
 *  Do not allocate extra space for another array, you must do this
 *  in place with constant memory.
 * For example,
 *  Given input array nums = [1,1,2],
 *
 *  Your function should return length = 2, with the first two elements
 *  of nums being 1 and 2 respectively. It doesn't matter what you leave
 *  beyond the new length.
 */

#include <vector>
#include <iostream>
#include "../include/util/util.hpp"

template <typename T> void remove_duplicates(std::vector<T>& vect) {
  int n = vect.size();

  for (int i = 0; i < n - 1; i++) {
    if (vect[i] == vect[i+1]) {
      vect.erase(vect.begin() + i);
      n--;
    }
  }
}

//------------------------------------------------------------------------------

int main() {

  std::vector<int> vect {
    1,1,2,3,3,4,5,5,6,7,7,8,9,9,10
  };

  util::display(vect);
  remove_duplicates(vect);
  util::display(vect);

  return 0;
}
