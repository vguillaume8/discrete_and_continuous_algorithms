/**
 * @file sort.hpp
 * @version 1.0
 * @title sort
 * @author Jabari Dash
 * @brief Various sorting algorithms
 * @date 06/16/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef SORT_H
#define SORT_H

#include <vector>
#include "../data_structures/MinHeap.hpp"

template <class T> class sort {
  public:

    /**
     * @bried Sorts a vector in ascending order via Bubble Sort
     * @param vect Vector to be sorted.
     */
    void static bubble_sort(std::vector<T>& vect);

    /**
     * @bried Sorts a vector in ascending order via Bubble Sort
     * @param vect Vector to be sorted.
     */
    void static bubble_sort_optimized(std::vector<T>& vect);

    /**
     * @brief Sorts a vector in ascending order via Counting Sort
     * NOT WORKING
     * @param vect Vector to be sorted.
     */
    void static counting_sort_positive(std::vector<T>& vect);

    /**
     * @bried Sorts a vector in ascending order via Heap Sort
     * @param vect Vector to be sorted.
     */
    void static heap_sort(std::vector<T>& vect);

    /**
     * @bried Sorts a vector in ascending order via Insertion Sort
     * @param vect Vector to be sorted.
     */
    void static insertion_sort(std::vector<T>& vect);

    /**
     * @brief Sorts a vector via Merge Sort.
     * @param a Vector array to be sorted in ascending order.
     * @param low The left most index to start sorting from .
     * @param high The right most index to start sorting from.
     */
    void static merge_sort(std::vector<T>& vect, int low, int high);

    /**
     * @brief Turns a vector that is split in two sorted vectors, into a fully sorted vector.s
     * @param a Vector (split it half into two sorted vectors) that will be merged into a fully sorted vector.
     * @param low The left most index to start merging from ..
     * @param mid Middle inddex that represents the end of left array, and beginning of right array
     * @param high The right most index to start merging from.
     */
    void static merge(std::vector<T>& vect, int low, int mid, int high);

    /**
     * @bried Sorts a vector in ascending order via Quick Sort
     * @param vect Vector to be sorted.
     * @param low Right most index in vector
     * @param high Left most index in vector
     */
    void static quick_sort(std::vector<T>& vect, int low, int high);
};

//------------------------------------------------------------------------------

template <class T> void sort<T>::bubble_sort(std::vector<T>& a) {
  int length = a.size();

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - 1 - i; j++) {
      if (a[j] > a[j+1]) {
        T t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
    }
  }
}

//------------------------------------------------------------------------------

template <class T> void sort<T>::bubble_sort_optimized(std::vector<T>& a) {
  int length = a.size();
  bool swap = true;

  for (int i = 0; swap == true; i++) {
    swap = false;

    for (int j = 0; j < length - 1 - i; j++) {
      if (a[j] > a[j+1]) {
        T t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
        swap = true;
      }
    }
  }
}

//------------------------------------------------------------------------------

template <class T> void sort<T>::counting_sort_positive(std::vector<T>& vect) {
  // TODO - IMPLEMENT CORRECTLY

  std::vector<T> output(vect.size());
  std::vector<T> count(vect[util::max(vect)] + 1);

  // 1. Initialize count vector
  for (int i = 0; i < vect.size(); i++) {
    std::cout << i << ": " <<count[vect[i]] << "->";
    count[vect[i]]++;
    std::cout << count[vect[i]] << "\n";
  }

  // 2. Add previous count to each ith count
  // For hashing purposes
  for (int i = 0; i < count.size()-1; i++) {
    count[i+1] += count[i];
  }

  // 3. Place values into correct spots
  for (int i = 0; i < vect.size(); i++) {
    output[count[vect[i]]] = vect[i];
    count[vect[i]]--;
  }

  std::cout << "\n\n";
  util::display(vect);
  util::display(count);
  util::display(output);
  std::cout << "\n\n";

  // 4. Copy back into original array
  // for (int i = 0; vect[i]; ++i) {
  //   vect[i] = output[i];
  // }
}

//------------------------------------------------------------------------------

template <class T> void sort<T>::heap_sort(std::vector<T>& array) {
  int size = array.size();
  MinHeap<T> heap;

  // Build heap O(n*log n)
  for (int i = 0; i < size; i++) {
    heap.insert(array[i]);
  }

  // Remove all elements from heap, copying back into array
  for (int i = 0; i < size; i++) {
    array[i] = heap.poll();
  }
}

//------------------------------------------------------------------------------

template <class T> void sort<T>::insertion_sort(std::vector<T>& a) {
	int n = 0;
  int length = a.size();

	for (int i = 0; i < length; i++) {
		for (int j = i; j > 0 && a[j-1] > a[j]; j--) {
			T t = a[j];
			a[j] = a[j-1];
			a[j-1] = t;
		}
	}
}

//------------------------------------------------------------------------------

template <class T> void sort<T>::quick_sort(std::vector<T>& a, int l, int r) {

	// Check exit condition
	if (l >= r) {
		return;
	}

	// Randomly pick pivot point
	int pivot = a[(rand() % (r-l)) + l];
		pivot = a[(l+r)/2];

	// Copy left and right bounds, so we still have originals for later
	int left = l;
	int right = r;
	int temp;

	// Partition list, Note, this can be abstracted to a separate method for readability
	while (left <= right) {

		// Find first element to left of pivot that is out of place
		while (a[left] < pivot) {
			left++;
		}

		// Find first element to right of pivot that is out of place
		while (a[right] > pivot) {
			right--;
		}

		// If the left and right have not crossed the pivot each other, swap
		// (essentially, if the values are truely to the left and right of the pivot, respectively)
		if (left <= right) {

			// Swap a[left] and a[right]
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;

			// Move left right pointers in the appropriate direction
			left++;
			right--;
		}
	}

  quick_sort(a, l, left-1);
  quick_sort(a, left, r);
}

//------------------------------------------------------------------------------

  template <class T> void sort<T>::merge(std::vector<T>& a, int low, int mid, int high) {
    int i = low;
    int j = mid+1;
    int k = low;

    // Allocate for auxiliary array
    std::vector<T> c(a.size() * 2);

    // While 'i' hasn't exceeded the mid point, and j hasn't gone off the back
    while (i <= mid && j <= high) {

      // Pick the larger
      if (a[i] < a[j]) {
        c[k] = a[i];
        i++;

      } else {
        c[k] = a[j];
        j++;
      }

      // Increment to next vacant index in auxiliary array
      k++;
    }

    // Get the remaining from the front half
    while (i <= mid) {
      c[k] = a[i];
      k++;
      i++;
    }

    // Get the remaining from the back half
    while (j <= high) {
      c[k] = a[j];
      k++;
      j++;
    }

    // Copy back into original array
    for (int i = low; i < k; i++) {
      a[i] = c[i];
    }
  }

//------------------------------------------------------------------------------

template <class T> void sort<T>::merge_sort(std::vector<T>& a, int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;

    merge_sort(a, low, mid);
    merge_sort(a, mid+1, high);
    merge(a, low, mid, high);
  }
}

#endif // SORT_H
