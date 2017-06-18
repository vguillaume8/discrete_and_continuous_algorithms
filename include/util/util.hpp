/**
 * @file util.hpp
 * @version 1.0
 * @title util
 * @author Jabari Dash
 * @brief Various functions used and reused in other classes
 * @date 06/16/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

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

	/**
	 * @brief Random integer generator between two integers.
	 * @param max Maximum integer bound.
	 * @param min Minimum integer bound.
	 * @return Integer between the minimum and maximum integer values (inclusive).
	 */
	int random_int(int max, int min);

	/**
	 * @brief Returns the maximum value between two values of the same type.
	 * @param a First argument.
	 * @param b Second argument.
	 * @return Maximum value between the two arguments.
	 */
	template <typename T> T max(T a, T b);

	/**
	 * @brief Returns the minimum value between two values of the same type.
	 * @param a First argument.
	 * @param b Second argument.
	 * @return Minimum value between the two arguments.
	 */
	template <typename T> T min(T a, T b);

	/**
	 * @brief Displays an NxN matrix with row and column numbers labeled.
	 * @param A 2-Dimensional nxn integer matrix to be displayed
	 * @param n The number of rows (and columns) in the matrix.
	 * @param extra An extra value to be added to each value in matrix upon printing.
	 */
	void display_NxN_matrix(std::vector< std::vector<int> >& A, int n, int extra);

	/**
	 * @brief A 2-Dimensional nxm integer matrix to be displayed
	 * @param n The number of rows in the matrix.
	 * @param m The number of columns in the matrix.
	 */
	template <typename T> void displayMaxtrix(std::vector< std::vector<T> >& A, int n, int m);

	/**
	 * @brief Prints an array to the console.
	 * @param a Array pointer.
	 * @param start Starting index to start printing from.
	 * @param finish Ending index to stop printing at.
	 */
	template <typename T> void display(T* a, int start, int finish);

	/**
	 * @brief Prints a vector to the console.
	 * @param vect Vector to be printed.
	 */
	template <typename T> void display(std::vector<T> vect);

	/**
	 * @brief Converts a vector to a string (ordering preserved).
	 * @param vect Vector to be converted into a string.
	 * @return String version of the vector.
	 */
	template <typename T> std::string to_string(std::vector<T> vect);

	/**
	 * @brief Prints a value to the console.
	 * @param t Value to be printed.
	 */
	template <typename T> void print(T t);

	/**
	 * @brief Prints a vector to the console.
	 * @param vect Vector to be printed.
	 */
	template <typename T> void print(std::vector<T> vect);

	/**
	 * @brief Prints a value to the console with a new line.
	 * @param t Value to be printed.
	 */
	template <typename T> void println(T t);

	/**
	 * @brief Prints a vector to the console onto a new line.
	 * @param vect Vector to be printed.
	 */
	template <typename T> void println(std::vector<T> vect);

//------------------------------------------------------------------------------

	int random_int(int max, int min) {
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

	void display_NxN_matrix(std::vector< std::vector<int> >& A, int n, int extra) {

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

	template <typename T> void display(std::vector<T>  vect) {
		int i;
		int n = vect.size();

		for (i = 0; i < n; i++) {
			std:: cout << vect[i] << " ";
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

} // end of namespace

#endif // UTIL_H
