#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "../../include/util/util.hpp"

/*
QUICKSORT

Arguments:

int[] a, array (pointer to array) of integers to be sorted
int l, left bound of array
int r, right bount of array
int c, optional counter that counts the amount of recursive calls

Algorithm:
--------------------------------------------------------------------------

0. Exit condition: If left greater than or equal to  right, do nothing

1. Randomly pick a pivot point in the array

2. Parition the array such that all values less than the pivot element
	 are to the left of all elements greater than the pivot point

	 Ex:

	 Pivot = 6

	 Before 1st partition: {15, 3, 2, 1, 9, 5, 7, 8, 6, 0, 10, 18, 22}

	 // TODO - write correctly
	 After 1st partition: {0, 3, 2, 1, 5, 9, 7, 8, 6, 15, 10, 18, 22}

	 Partition:

	 Condition: While the left most index pointer has not exceeded the value  of the right most index pointer

	 1. Nested Loop: from left of array to first value that is out of place (greater than the pivot)

	 2. Nested Loop: from right of array to first value that is out of place (less than the pivot)

	 3. Swap the two out of place values

	 4. Repeat until the exit condition is met

3. Call quicksort on both the left and right sublists

*/
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
