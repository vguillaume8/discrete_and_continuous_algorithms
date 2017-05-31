#ifndef BINOMIAL_COEFFICIENT_H
#define BINOMIAL_COEFFICIENT_H

/*
* Recursively returns binomial coefficient of n,m
* Increments counter c, pointer that counts recursive calls
*
* C(n,m) = C(n-1,m) + C(n-1,m-1)
*
*/
unsigned long C(int n, int m, unsigned long& c) {
	unsigned long a;
	unsigned long b;

	// Increment counter
	c++;

	// If we are at exit condition, return 1
	if (m == 0 || n == m) {
		return 1;

	// Else, return C(n-1,m + C(n-1,m-1)
	} else {
		a = C(n-1, m, c);
		b = C(n-1, m-1, c);

		return a + b;
	}
}

#endif
