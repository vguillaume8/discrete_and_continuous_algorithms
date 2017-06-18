#include <stdio.h>
#include "../include/algorithms/euclids_algorithm.hpp"

/*
To compile:
c++ -o ../bin/test_euclids_algorithm test_euclids_algorithm.cpp

To run:
../bin/./test_euclids_algorithm

*/

int main() {
	for (int m = 0; m < 100; m++) {
		printf("%i, %i, %i\n",
				gcd_recursive_runtime(100, m, 0),
				gcd_recursive_runtime_2(100, m, 0),
				gcd_iterative_runtime(100, m));
	}

  return 0;
}
