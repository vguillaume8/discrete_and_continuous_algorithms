#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

template <typename T> int binary_search_iterative(T x, T* a, int length) {
	int l;
	int r;
	int m;
	int s;

	l = 0;
	r = length;
	s = -1;

	do {
		m = (l+r) / 2;

		if (x == a[m]) {
			s = m;
			break;
		} else if (x < a[m]) {
			r = m-1;
		} else {
			l = m+1;
		}

	} while (r < l == false);

	return s;
}

//------------------------------------------------------------------------------

template <typename T> int binary_search_recursive(T x, T* a, int l, int r) {
	int m = (l+r) / 2;

	if (r < l == false) {
		if (x == a[m]) {
			return m;
		}

		else if (x < a[m]) {
			return binary_search_recursive(x, a, 0, m-1);
		} else  {
			return binary_search_recursive(x, a, m+1, r);
		}
	} else {
		return -1;
	}
}

#endif // BINARY_SEARCH_H
