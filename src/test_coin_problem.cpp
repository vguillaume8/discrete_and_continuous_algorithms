#include <stdio.h>
#include <vector>
#include "../include/util/util.hpp"
#include "../include/algorithms/coin_problem.hpp"

/*
To compile:
c++ -o ../bin/test_coin_problem test_coin_problem.cpp

To run:
../bin/./test_coin_problem

*/

int main() {
  int coins[4] = {0, 1, 10, 25};
  int num_coins = sizeof(coins) / sizeof(coins[0]);
  int change = 40;

  // Allocate space
  std::vector< std::vector<int> > C(num_coins+1, std::vector<int>(change+1, 0));
  std::vector< std::vector<int> > D(num_coins+1, std::vector<int>(change+1, 0));

  int min_num_coints = coin_problem(C, D, coins, num_coins, change);

  displayMaxtrix(C, num_coins, change+1);
  displayMaxtrix(D, num_coins, change+1);
  distribution(D, coins, change, num_coins-1);

  return 0;
}
