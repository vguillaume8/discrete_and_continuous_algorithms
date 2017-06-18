#include "../../../include/algorithms/sort.hpp"
#include <assert.h>

template <typename T> bool is_sorted(std::vector<T>& vect) {
  bool sorted = true;
  int n = vect.size();

  for (int i = 0; i < n-1; i++) {
    if (vect[i] > vect[i+1]) {
      sorted = false;
      break;
    }
  }
  return sorted;
}

//------------------------------------------------------------------------------

template <typename T> bool test_bubble_sort(std::vector<T> vect) {
  sort<T>::bubble_sort(vect);

  assert(is_sorted(vect));
  return true;
}

//------------------------------------------------------------------------------


template <typename T> bool test_insertion_sort(std::vector<T> vect) {
  sort<T>::insertion_sort(vect);

  assert(is_sorted(vect));
  return true;
}

//------------------------------------------------------------------------------

template <typename T> bool test_heap_sort(std::vector<T> vect) {
  sort<T>::heap_sort(vect);

  assert(is_sorted(vect));
  return true;
}

//------------------------------------------------------------------------------

template <typename T> bool test_merge_sort(std::vector<T> vect) {
  sort<T>::merge_sort(vect, 0 , vect.size()-1);

  assert(is_sorted(vect));
  return true;
}

//------------------------------------------------------------------------------

template <typename T> bool test_quick_sort(std::vector<T> vect) {
  sort<T>::quick_sort(vect, 0, vect.size()-1);

  assert(is_sorted(vect));
  return true;
}

int main() {
  std::vector<int> vect;

  vect.push_back(0);
  vect.push_back(12);
  vect.push_back(-1);
  vect.push_back(10);
  vect.push_back(11);
  vect.push_back(2);

  std::cout << "bubble_sort: " << test_bubble_sort(vect) << "\n";
  std::cout << "insertion_sort: " << test_insertion_sort(vect) << "\n";
  std::cout << "heap_sort: " << test_heap_sort(vect) << "\n";
  std::cout << "merge_sort: " << test_merge_sort(vect) << "\n";
  std::cout << "quick_sort: " << test_quick_sort(vect) << "\n";

  return 0;
}
