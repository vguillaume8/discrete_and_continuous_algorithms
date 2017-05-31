#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

template <class T> int insertion_sort(T* a, int length) {
	int n = 0;

	for (int i = 0; i < length; i++) {
		for (int j = i; j > 0 && a[j-1] > a[j]; j--, n++) {
			T t = a[j];
			a[j] = a[j-1];
			a[j-1] = t;
		}
	}
	return n;
}

#endif
