/**
 * @brief Reverse an integer
 */

#include <iostream>
#include <math.h>

int main() {

  int o = 123456789;
  int n = o;
  int m = 0;

  // O(n) time, O(1) space
  while (n > 0) {
    m *= 10;        // Shift m over by 1 (magnitude of 10) to make space for incoming digit
    m += n%10;      // Strip off right most digit of n, append to m
    n /= 10;        // Shift n over by 1 (magnitude of 10) to get ride of recently striped off digit
  }

  // Display results
  std::cout << o << "\n";
  std::cout << m << "\n";

  return 0;
}
