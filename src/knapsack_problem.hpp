/**
 * @file knapsack_problem.hpp
 * @version 1.0
 * @title knapsack_problem
 * @author Jabari Dash
 * @brief Provided a set of weighted objects with numerical values, and a backpack with a weight limit,
 * find the optimal combination of items to fill the backpack such that the sum of the values is maximized,
 * without exceeding the backpack's weight limit.
 * @date 06/16/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef KNAPSACK_PROBLEM_H
#define KNAPSACK_PROBLEM_H

#include <stdio.h>
#include <vector>
#include "../../include/util/util.hpp"
#include "../../include/algorithms/knapsack_problem.hpp"

/**
 * @brief Print the optimal items distribution.
 * @param D Distribution matrix.
 * @param weights List of object weights
 * @param max_weight Weight limit
 * @param object_num DON'T RECALL
 */
void distribution(std::vector< std::vector<int> >& D, int weights[], int max_weight, int object_num);

/**
 * @brief Solve the Knapsack problem using dynamic programming
 * @param K Matrix for keeping track of max weights for all of the combinations
 * @param D Distribution matrix
 * @param weights List of weights
 * @param values List of values
 * @param max_weight Designated weight limit for the bookbag.
 * @param num_values
 * @return Maximum value that the bookbag can hold without exceeding weight limit
 */
int knapsack(std::vector< std::vector<int> >& K, std::vector< std::vector<int> >& D, int weights[], int values[], int max_weight, int num_values);

//------------------------------------------------------------------------------

void distribution(std::vector< std::vector<int> >& D, int weights[], int max_weight, int object_num) {
  if (max_weight < 0 || object_num < 0) {
    printf("\n");
    return;
  }

  // Loop backwards starting at back right hand corner, going row by row,
  // column by column, checking if an object was used
  for (int i = object_num; i > 0; i--) {
    for (int j = max_weight; j > 0; j--) {
      int used = D[i][max_weight];

      // If an objecct was used, and our current weight limit
      // as we are filling the back is not exceeded if we use this object_num
      // put it in the bag, and subtract it's weight from our running (decreasing)
      // limit
      if (used == 1 && max_weight<= j) {
        printf("obj_%i, ", i);
        max_weight = max_weight - weights[i];
      }
    }
  }
  printf("\n");
}

//------------------------------------------------------------------------------

int knapsack(std::vector< std::vector<int> >& K, std::vector< std::vector<int> >& D, int weights[], int values[], int max_weight, int num_values) {
  int previous, index, current;

  // Initialize first row, using only object type 1,
  // The max value for a given entry will be the weight limit (j) divided by the weight
  // of object 1. Ex: For j = 10, and w_1 = 2, and w_1, we can have a max value of
  // 5 in our bag. (this is because we used 5 object 1s), but the I matrix will tell us
  // our distribution
  for (int j = 1; j <= max_weight; j++) {
    K[1][j] = j / weights[1];

    // If at least one object of type 1 was used
    if (K[1][j] > 0) {
      D[1][j] = 1;
    }
  }

  // Initialize all other rows in Knapsack matrix, indexing column by column
  // then row by row. We do this because we are comparing the current values to their
  // previous ones, which are located one row higher, but in the same column.
  for (int j = 1; j <= max_weight; j++) {
    for (int i = 2; i < num_values; i++) {

      // Get previous max value
      previous = K[i-1][j];

      // Compute index to see if we can fit more objects in using the
      // current object type, if index comes back negative, then it does not fit.
      index = j - weights[i];

      // If we compute an index out of bounds, disregard the second option, and pick
      // the previous weight
      if (index < 0 ) {
        K[i][j] = previous;

        // If both using at least one of the new object type fits, we must figure out
        // which will provide more value for us, our previous configuration, or the current
      } else {
        current = values[i] + K[i][ j - weights[i] ];

        // Pick the larger of the two
        int choice = util::max(previous, current);

        if (choice == current) {
          D[i][j] = 1;
        }

        // If we can use either decision
        if (previous == current) {
          //D[i][j] = 2;
        }

        // Keep the larger of the two
        K[i][j] = choice;
      }
    }
  }

  // Return the index in the bottom right hand corner that represents
  // the max value of our knapsack using a combination of objects 1-n
  return K[num_values-1][max_weight];
}

#endif // KNAPSACK_PROBLEM_H
