#include <iostream>

void swap(int& a, int& b) {
  a += b;
  b -= a;
  a += b;
  b *= -1;
}

//------------------------------------------------------------------------------


int main() {
  int a = 1;
  int b = 0;

  std::cout << "a: " << a << "\nb: " << b << "\n\n";
  swap(a, b);

  std::cout << "a: " << a << "\nb: " << b << "\n";

  return 0;
}
