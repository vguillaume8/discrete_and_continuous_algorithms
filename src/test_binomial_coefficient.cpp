#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../include/util/util.hpp"
#include "../include/algorithms/binomial_coefficient.hpp"

/*

To compile:
c++ -o ../bin/test_binomial_coefficient test_binomial_coefficient.cpp

To run:
../bin/./test_binomial_coefficient

*/

int main() {
	unsigned long count = 0;
	unsigned long nCm = 0;
	double n2;
	double En;
	int num_tests = 10;
	int n;
	int m;

	printf("n\te(n)\t\te(n)/2^n\n--------------------------------\n");

	// Run find e(n) h amount of times
	for (n = 5; n <= 100; n+=5) {
		// Reset counter
		count = 0;

		/*
		* run nCm(n_i,m_k) where n_k is a randomly generate  values
		* m is in the domain [0, n_i]
		*/
		for (int k = 1; k <= num_tests; k++) {

			// Get random m between 0 and n, inclusive
			m = random_int(n,0);

			// Compute bionomial coefficient
			nCm = C(n, m, count);
		}

		// 2^n
		n2 = pow(2, n);

		// e(n) = 1/10 * (# of recursive calls)
		En = (double) count / (double) num_tests;

		// Print row in table
		printf("%i\t%.1f\t%.2f\n", n, En, En/n2);
	}

	return 0;
}
