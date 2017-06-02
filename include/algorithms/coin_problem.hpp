#ifndef COIN_PROBLEM_H
#define COIN_PROBLEM_H

#include <vector>
#include <stdio.h>
#include "../../include/util/util.hpp"


void distribution(std::vector< std::vector<int> >& D, int coins[], int change, int coin_num) {

  for (int i = coin_num; i > 0; i--) {
    for (int j = change; j > 0; j--) {
      int used = D[i][change];

      if (used == 1 && change <= j) {
        printf("%i, ", coins[i]);
        change = change - coins[i];
      }
    }
  }
  printf("\n");
}

//------------------------------------------------------------------------------

int coin_problem(std::vector< std::vector<int> >& C, std::vector< std::vector<int> >& D, int coins[], int num_coins, int change) {
  int previous, current, index;

  for (int j = 1; j <= change; j++) {
    C[1][j] = j / coins[1];
    D[1][j] = 1;
  }

  for (int j = 1; j <= change; j++) {
    for (int i = 2; i < num_coins; i++) {
      previous = C[i-1][j];
      index = j - coins[i];

      if (index < 0) {
        C[i][j] = previous;

      } else {
        current = 1 + C[i][index];

        int choice = util::min(previous, current);

        if (choice == current) {
          D[i][j] = 1;
        }

        C[i][j] = choice;
      }
    }
  }
}

#endif
