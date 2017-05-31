#ifndef EUCLIDS_ALGORITHM_H
#define EUCLIDS_ALGORITHM_H

int gcd_recursive(int n, int m) {
	if (m == 0 || n == m) {
		return n;
	} else {
		return gcd_recursive(m, n%m);
	}
}

//------------------------------------------------------------------------------

int gcd_recursive_2(int n, int m) {
	return (m == 0 || n == m) ? n : gcd_recursive_2(m, n%m);
}

//------------------------------------------------------------------------------

int gcd_recursive_runtime(int n, int m, int c) {
	if (m == 0 || n == m) {
		return c;
	} else {
		return gcd_recursive_runtime(m, n%m, c+1);
	}
}

//------------------------------------------------------------------------------

int gcd_recursive_runtime_2(int n, int m, int c) {
	return (m == 0 || n == m) ? c : gcd_recursive_runtime_2(m, n%m, c+1);
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

//------------------------------------------------------------------------------

int gcd_iterative_runtime(int n, int m) {
	int s;
	int c;

	for (c = 0; true; c++) {
		if (m == 0 || n == m) {
			break;
		}

		s = n;
		n = m;
		m = s%m;
	}
	return c;
}


#endif
