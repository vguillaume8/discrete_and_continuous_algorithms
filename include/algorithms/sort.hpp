#ifndef SORT_H
#define SORT_H

#include <vector>

namespace sort {
  
  std::vector<T> bubble_sort(std::vector<T> a);
  std::vector<T> heap_sort(std::vector<T> a);
  std::vector<T> insertion_sort(std::vector<T> a);
  std::vector<T> merge_sort(std::vector<T> a, int l,int r);
  std::vector<T> merge(std::vector<T> a, int l, int r);
  std::vector<T> quick_sort(std::vector<T> a, int l, int r);

}

#endif // SORT_H
