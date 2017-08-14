#include <iostream>
#include <climits>

int divide_bitwise(int divident, int divisor) {

  return 0;
}

//------------------------------------------------------------------------------

int divide(int dividend, int divisor) {
  int quotient = 0;

  // If a fraction is passed
  if (dividend < divisor) {
    return quotient;
  }

  // Repeated subtraction, keeping track of how many times
  while(dividend > 0) {
    dividend -= divisor;
    quotient++;
  }

  // If there is a remainder, we went over by 1 iteration
  if (dividend != 0) {
    quotient--;
  }

  return quotient;
}

//------------------------------------------------------------------------------

int main() {

  int x = 10;
  int y = 10;

  std::cout << x << "/" << y << " = " << divide(x,y) << std::endl;

  return 0;
}
