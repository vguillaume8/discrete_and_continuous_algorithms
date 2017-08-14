#include <vector>
#include "../include/util/util.hpp"

//------------------------------------------------------------------------------

void swap(std::vector<int>& vect, int i, int j) {
  int t = vect[i];
  vect[i] = vect[j];
  vect[j] = t;
}

//------------------------------------------------------------------------------

/**
 * @brief Time O(n), Space (n)
 */
void rotate_3(std::vector<int>& vect, int k) {
  int n = vect.size();
  std::vector<int> vect_2(n);
  int i;
  int j;

  // Take the last k elements, and bring them
  // into front of auxiliary array
  for (i = n-1, j=k-1; i > (n-1)-k; i--, j--) {
    vect_2[j] = vect[i];
  }

  // Take first n-k elements and place them into
  // auxiliary array after the last k elements
  for (j = 0; j <= i; j++) {
    vect_2[j+k] = vect[j];
  }

  // Copy back into original array
  for (i = 0; i < n; i++) {
    vect[i] = vect_2[i];
  }
}

//------------------------------------------------------------------------------

/**
 * @brief Time O(n*k), Space O(1)
 */
void rotate_2(std::vector<int>& vect, int k) {
  int n = vect.size();

  for (int j = 0; j < k; j++) {
    swap(vect, 0, n-1);

    for (int i = n-1; i > 1; i--) {
      swap(vect, i, i-1);
    }
  }
}

//------------------------------------------------------------------------------

/**
 * @brief Time O(n*k), Space O(1)
 */
void rotate(std::vector<int>& vect, int k) {
  int length = vect.size();
  int temp;

  for (int j = 0; j < k; j++) {

    temp = vect[length-1];

    for (int i = length-2; i >= 0; i--) {
      vect[i+1] = vect[i];
    }

    vect[0] = temp;
  }
}

//------------------------------------------------------------------------------

int main() {
  std::vector<int> vect{
    1,2,3,4,5,6,7,8,9
  };

  util::display(vect);
  rotate_3(vect, 1);

  util::display(vect);

  return 0;
}
