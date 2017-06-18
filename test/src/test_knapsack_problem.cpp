#include <stdio.h>
#include <vector>
#include "../include/util/util.hpp"
#include "../include/algorithms/knapsack_problem.hpp"

/*
To compile:
c++ -o ../bin/test_knapsack_problem test_knapsack_problem.cpp 

To run:
../bin/./test_knapsack_problem

*/

int main() {
  int weights[5] = {0, 2, 3, 4, 7};
  int values[5] = {0, 1, 3, 5, 9};
  int max_weight = 10;
  int num_values = 5;

  // Initialize 5x11 matrix Knapsack and Distribution
  std::vector< std::vector<int> > K(num_values+1, std::vector<int>(max_weight+1, 0));
  std::vector< std::vector<int> > D(num_values+1, std::vector<int>(max_weight+1, 0));

  // Run knapsack problem
  int max_value = knapsack(K, D, weights, values, max_weight, num_values);

  displayMaxtrix(K, num_values, max_weight+1);
  displayMaxtrix(D, num_values, max_weight+1);
  printf("Weight limit: %i\nMax value: %i\n", max_weight, max_value);
  distribution(D, weights, max_weight, num_values-1);

  return 0;
}
