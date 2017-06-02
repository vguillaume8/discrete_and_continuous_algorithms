#include <stdio.h>
#include "../include/algorithms/binary_search.hpp"

/*
To compile:
c++ -o ../bin/test_binary_search test_binary_search.cpp

To run:
../bin/./test_binary_search

*/

int main() {
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int length = sizeof(a) / sizeof(a[0]);


  for (int i = 0; i <= length; i++) {
    printf("via BS iterative: %i  is located at index %i\n", i, binary_search_iterative(i, a, length));
    printf("via BS recursive: %i  is located at index %i\n", i, binary_search_recursive(i, a, 0, length-1));
  }

  return 0;
}
