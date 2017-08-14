#include <iostream>

int sum_ite(int n) {
  int s = 0;

  while (n > 0) {
    s += n%10;
    n /= 10;
  }

  return s;
}

//------------------------------------------------------------------------------

int sum_rec(int n) {
  if (n < 10){
    return n;
  }

  return sum_rec(n/10) + sum_rec(n%10);
}

//------------------------------------------------------------------------------

int main() {
  int n = 1234567;
  int s = 28;

  int t = sum_rec(n);
  int r = sum_ite(n);

  std::cout << s << " = " << t << " = " << r << "\n";

  return 0;
}
