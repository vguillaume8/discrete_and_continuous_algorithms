/**
 * @file mathematical.hpp
 * @version 1.0
 * @title sort
 * @author Jabari Dash
 * @brief Various mathematical algorithms
 * @date 06/16/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef MATHEMATICAL_H
#define MATHEMATICAL_H

/*
* @bried Recursively returns binomial coefficient of n,m. Increments counter c, pointer that counts recursive calls.
* @param n Larger number
* @param m m >= n
* @return C(n,m) = C(n-1,m) + C(n-1,m-1)
*/
unsigned long C(int n, int m);

/**
 * @brief Recursively computes the greatest common denominator between two numbers.
 * @param n First number
 * @param m Second number (n less than or equal to m)
 * @return Greatest common denominator between n and m
 */
int gcd_recursive(int n, int m);

/**
 * @brief Iteratively computes the greatest common denominator between two numbers.
 * @param n First number
 * @param m Second number (n less than or equal to m)
 * @return Greatest common denominator between n and m
 */
int gcd_iterative(int n, int m);

//------------------------------------------------------------------------------

unsigned long C(int n, int m) {
	unsigned long a;
	unsigned long b;

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

int gcd_recursive(int n, int m) {
	if (m == 0 || n == m) {
		return n;
	} else {
		return gcd_recursive(m, n%m);
	}
}

//------------------------------------------------------------------------------

int gcd_iterative(int n, int m) {
	int s;

	while (true) {
		if (m == 0 || n == m) {
			break;
		}

		s = n;
		n = m;
		m = s%m;
	}
	return n;
}

#endif // MATHEMATICAL_H
