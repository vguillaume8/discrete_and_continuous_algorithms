#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "../../include/util/util.hpp"

int quick_sort(int* a, int l, int r, int c) {

	// Check exit condition
	if (l >= r) {

		// Return count + 1 (add one more (this) recursive call to count)
		return c + 1;
	}

	// Randomly pick pivot point
	int pivot = a[(rand() % (r-l)) + l];
		pivot = a[(l+r)/2];

	printf("left: %i, right: %i, pivot: %i\n", l, r, pivot);
	util::display(a, l, r);

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
	util::display(a, l, r);

	// Return number of recursive calls
	printf("qs_l(%i,%i), qs_r(%i,%i)\n", l, left-1, left, r);

	return quick_sort(a, l, left-1, c) + quick_sort(a, left, r, c);
}

#endif
