#include <stdio.h>
#include "../include/algorithms/quick_sort.hpp"
#include "../include/util/util.hpp"

/*
To compile:
c++ -o ../bin/test_quick_sort test_quick_sort.cpp

To run:
../bin/./test_quick_sort

*/

int main() {
	int a[6] = {15, 3, 2, 1, 9, 5};
	int a_size = sizeof(a) / sizeof(a[0]);
	int c = 1;

	printf("Unsorted:\n");
	display(a, 0, a_size-1);

	// Perform quicksort on array a, store # of recursive calls
	c = quick_sort(a, 0, a_size-1, c) - 1;

	printf("Sorted:\n");
	display(a, 0, a_size-1);

	printf("# of recursive calls: %i\n", c);

	return 0;
}
