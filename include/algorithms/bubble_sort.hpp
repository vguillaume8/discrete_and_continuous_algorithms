#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

template <typename T> int bubble_sort(T* a, int length) {
  int n = 0;

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - 1 - i; j++, n++) {
      if (a[j] > a[j+1]) {
        T t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
    }
  }
  return n;
}

//------------------------------------------------------------------------------

template <typename T> int bubble_sort_descending(T* a, int length) {
  int n = 0;

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - 1 - i; j++, n++) {
      if (a[j] < a[j+1]) {
        T t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
    }
  }
  return n;
}

//------------------------------------------------------------------------------

template <typename T> int bubble_sort_optimized(T* a, int length) {
  int n = 0;
  bool swap = true;

  for (int i = 0; swap == true; i++) {
    swap = false;

    for (int j = 0; j < length - 1 - i; j++, n++) {
      if (a[j] > a[j+1]) {
        T t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
        swap = true;
      }
    }
  }
  return n;
}

//------------------------------------------------------------------------------

template <typename T> int bubble_sort_optimized_descending(T* a, int length) {
  int n = 0;
  bool swap = true;

  for (int i = 0; swap == true; i++) {
    swap = false;

    for (int j = 0; j < length - 1 - i; j++, n++) {
      if (a[j] < a[j+1]) {
        T t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
        swap = true;
      }
    }
  }
  return n;
}

#endif
