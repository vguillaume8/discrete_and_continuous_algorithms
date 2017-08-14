#include <iostream>

/**
 * @brief Compute Fibonacci sequence using dynamic programming, O(n) time, O(1) space
 * @param n The nth fibonacci # that we want
 * @return The nth fibonacci #
 */
int fib(int n) {
  int x = 1;
  int y = 1;
  int f = 1;
  int i = 2;

  if (n == 0) {
    return 0;
  }

  if (n == 1 || n == 2) {
    return 1;
  }

  while (i < n) {
    f = x + y;
    x = y;
    y = f;

    i++;
  }

  return f;
}

//------------------------------------------------------------------------------

/**
 * @brief time O(2^n), space O(1)
 */
int fib_rec(int n) {
  if (n == 0) {
    return 0;
  }

  if (n == 1 || n == 2) {
    return 1;
  }

  return fib_rec(n-1) + fib_rec(n-2);
}

//------------------------------------------------------------------------------

int main() {

  for (int i = 1; i <= 10; i++) {
    std::cout << fib_rec(i) << " " << fib(i) << "\n";
  }

  return 0;
}
