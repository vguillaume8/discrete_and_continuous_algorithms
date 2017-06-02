#ifndef UTIL_H
#define UTIL_H

#include <climits>     // INT_MAX
#include <cstdlib>     // rand()
#include <vector>      // std::vector<T>
#include <string>      // std::string
#include <sstream>     // std::stringstream
#include <iterator>    // std::ostream_iterator
#include <iostream>    // std::cout, std::endl

namespace util {

	inline int random_int(int max, int min) {
		return min + rand() % (max - min);
	}

//------------------------------------------------------------------------------

	template <typename T> T max(T a, T b) {
	  if (a > b) {
	    return a;
	  } else {
	    return b;
	  }
	}

//------------------------------------------------------------------------------

	template <typename T> T min(T a, T b) {
	  if (a < b) {
	    return a;
	  } else {
	    return b;
	  }
	}

//------------------------------------------------------------------------------

	inline void display_NxN_matrix(std::vector< std::vector<int> >& A, int n, int extra) {

		// Display column numbers
		for (int i = 0; i < n; i++) {
			std::cout << "\t" << i+1 << "\t";
		}

		std::cout << std::endl << " ";

		// Draw line between column number and matrix elements
		for (int i = 0; i < n; i++) {
			std::cout << "---------------";
		}

		std::cout << std::endl;

		// Display matrix
		for (int i = 0; i < n; i++) {

			// Display row numbers
			std::cout << i+1 << "|";

	    for (int j = 0; j < n; j++) {

				// TODO - GENERALIZE
				if (A[i][j] == INT_MAX) {

					std::cout << "\t" << "∞\t";

				} else {

						std::cout << "\t" << A[i][j] + extra << "\t";
				}
	    }
			std::cout << "\n |\n";
	  }

		std::cout << "\n\n\n";
	}

//------------------------------------------------------------------------------

	template <typename T> void displayMaxtrix(std::vector< std::vector<T> >& A, int r, int c) {
	  for (int i = 1; i < r; i++) {
	    for (int j = 1; j < c; j++) {
				std::cout << A[i][j] << " ";
	    }
			std::cout << std::endl;
	  }
		std::cout << std::endl;
	}

//------------------------------------------------------------------------------

	template <typename T> void display(T* a, int start, int finish) {
		int i;

		for (i = start; i <= finish; i++) {
			std:: cout << a[i] << " ";
		}

		std::cout << std::endl << std::endl;
	}

//------------------------------------------------------------------------------

	template <typename T> void display(std::vector<T>  a) {
		int i;
		int n = a.size();

		for (i = 0; i < n; i++) {
			std:: cout << a[i] << " ";
		}

		std::cout << std::endl;
	}

//------------------------------------------------------------------------------

	template <typename T> std::string to_string(std::vector<T> vect) {
		std::stringstream result;
		std::string str;

		// Copy vector into stringstream
		std::copy(vect.begin(), vect.end(), std::ostream_iterator<T>(result, " "));

		// Convert to string
		str = result.str();

		// Remove last trailing space
		str = str.substr(0, str.size()-1);

		return str;
	}

//------------------------------------------------------------------------------

	template <typename T> void print(T t) {
		std::cout << t;
	}

//------------------------------------------------------------------------------

	template <typename T> void print(std::vector<T> vect) {
		display(vect);
	}

//------------------------------------------------------------------------------

	template <typename T> void println(T t) {
		std::cout << t << std::endl;
	}

//------------------------------------------------------------------------------

	template <typename T> void println(std::vector<T> vect) {
		display(vect);
	}

	// end of namespace
}

#endif
