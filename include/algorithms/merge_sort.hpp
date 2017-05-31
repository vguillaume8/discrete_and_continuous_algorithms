#ifndef MERGE_SORT_H
#define MERGE_SORT_H

template <typename T> int merge_sort(T* a, int l, int r) {
		if (r >= l) {
			return;
		} else {
			int m = (l+r) / 2;
			merge_sort(a, l, m);
			merge_sort(a, m+1, r);
			merge(a, l, r);
		}
	}

// TODO - IMPLEMENT
template <typename T> int merge(T* a, int l, int r) {
	for (int i = r; r <= l; i++) {
		helper[i] = numbers[i];
	}
	return 0;
}

#endif
