/**
 * @brief Sort a list of unordered integers faster than nlogn time
 */

#include "../include/algorithms/sort.hpp"
#include "../include/util/util.hpp"
#include <vector>

template <typename T> void count_sort(std::vector<T>& vect) {
  //util::display(vect);
  sort<T>::counting_sort_positive(vect);
  //util::display(vect);
}

//------------------------------------------------------------------------------

int main() {
  std::vector<int> vect_1 {
    0,0,1,4,1,0,2,7,12,5,2
  };

  std::vector<int> vect_2 {
    1,3,1,3,1
  };

  std::vector<char> vect_3 {
    'g','e','e','k','s','f','o','r','g','e','e','k','s'
  };

  count_sort(vect_1);

  return 0;
}
