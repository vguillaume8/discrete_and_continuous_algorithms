#include <stdio.h>
#include "../include/algorithms/bubble_sort.hpp"
#include "../include/util/util.hpp"

/*
To compile:
c++ -o ../bin/test_bubble_sort test_bubble_sort.cpp ../src/util/util.cpp

To run:
../bin/./test_bubble_sort

*/

int main() {
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int length = sizeof(a) / sizeof(a[0]);
  int c = 0;

  c = bubble_sort(a, length);
  display(a,0, length);
  printf("bubble_sort # of data comparisons: %i \n", c);

  c = bubble_sort_descending(a, length);
  display(a,0, length);
  printf("bubble_sort_descending # of data comparisons: %i \n", c);

  c = bubble_sort_optimized(a, length);
  display(a,0, length);
  printf("bubble_sort_optimized # of data comparisons: %i \n", c);

  c = bubble_sort_optimized_descending(a, length);
  display(a,0, length);
  printf("bubble_sort_optimized_descending # of data comparisons: %i \n", c);

  return 0;
}
