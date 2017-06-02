#include <stdio.h>
#include "../include/algorithms/insertion_sort.hpp"
#include "../include/util/util.hpp"

/*
To compile:
c++ -o ../bin/test_insertion_sort test_insertion_sort.cpp ../src/algorithms/insertion_sort.cpp

To run:
../bin/./test_insertion_sort

*/
int main() {
  double a[10] = {23.1, 10.34, 3.1, 2, 5.1, 6, 7, 8, 2, 0.1};
  int length = sizeof(a) / sizeof(a[0]);
  int c = 0;

  display(a, 0, length-1);
  c = insertion_sort(a, length);
  display(a, 0, length-1);
  printf("insertion_sort # of data comparisons: %i \n", c);

  return 0;
}
