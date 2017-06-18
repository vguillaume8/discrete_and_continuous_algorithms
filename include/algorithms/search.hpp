/**
 * @file search.hpp
 * @version 1.0
 * @title search
 * @author Jabari Dash
 * @brief Various searching algorithms.
 * @date 06/16/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef SEARCH_H
#define SEARCH_H

/**
 * @brief Performs a binary search (iteratively) on a vector of sorted (ascending) elements.
 * @param vect Vector of sorted elements.
 * @return The index in which the specified element is located. -1 Is returned if the element is not present.
 */
template <typename T> int binary_search_iterative(T element, std::vector<T> vect);

/**
 * @brief Performs a binary search (recursively) on a vector of sorted (ascending) elements.
 * @param vect Vector of sorted elements.
 * @return The index in which the specified element is located. -1 Is returned if the element is not present.
 */
template <typename T> int binary_search_recursive(T element, std::vector<T> vect, int l, int r);

//------------------------------------------------------------------------------

template <typename T> int binary_search_iterative(T element, std::vector<T> vect) {
	int left;
	int right;
	int middle;
	int index;

	left = 0;
	right = vect.size();
	//right = vect.size() - 1;

	// By default, index is -1, and will be replace by the actual index if the element is found.
	// It will otherwise remain -1 to indicate that the element is not in the vector.
	index = -1;

	do {

		// Compute middle index of vector
		middle = (left + right) / 2;

		// If the specified element is in the middle, return the middle index
		if (element == vect[middle]) {
			index = middle;
			break;

		// If the specified element is smaller than the middle value, continue searching left
		} else if (element < vect[middle]) {
			right = middle - 1;

		// Otherwise, search right
		} else {
			left = middle + 1;
		}

		// While the left and right boundaries have not cross each other
	} while (right < left == false);

	// Return the index of the element
	return index;
}

//------------------------------------------------------------------------------

template <typename T> int binary_search_recursive(T element, std::vector<T> vect, int left, int right) {

	// Compute the middle index of the vector
	int middle = (left + right) / 2;

	// If the left and right boundaries have not crossed each other
	if (left <= right) {

		// If the specified element is in the middle, return the middle index
		if (element == vect[middle]) {
			return middle;
		}

		// If the specified element is smaller than the middle value, continue searching left
		else if (element < vect[middle]) {
			return binary_search_recursive(element, vect, 0, middle-1);

		// Otherwise, search right
		} else  {
			return binary_search_recursive(element, vect, middle+1, right);
		}

	// The left and right boundaries have crossed, and we have not found the element.
	// Return -1 to indicate that the element is not in the vector
	} else {
		return -1;
	}
}

#endif // BINARY_SEARCH_H
