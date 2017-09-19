#include <vector>
#include <iostream>

#include "../include/data_structures/Stack.hpp"
#include "../include/util/util.hpp"

/*
To compile:
c++ -o bin/spiderman_no_web src/spiderman_no_web.cpp

To run:
bin/./spiderman_no_web

*/

bool is_hoppable(std::vector<int>& towers) {
  int n = towers.size();
  bool hoppable = false;

  // Start at first tower
  int current = 0;
  int max = 0;

  do {

    // Start checking from the next tower
    max = current+1;

    // Find the move with that maintains highest altitude
    for (int j = current+1; j < towers[current] + current + 1; j++) {

      // If j went off the end of the array
      if (j >= n) {
        break;
      }

      // Keep track of local max height tower
      if (towers[j] >= towers[max]) {
        max = j;
      }
    }

    //std::cout << "Max " << towers[max] << " found @ index: " << max << "\n";

    // If we found a new max
    if (max != current) {

      // If we made it off the last tower
      if (current >= n-1) {
        //std::cout << "made it to the end\n";
        hoppable = true;
        break;
      }

      // If the building is short enough, jump to it
      if (towers[max] <= towers[current]) {
        //std::cout << "jumping from " << current << " to " << max << "\n";
        current = max;
      }

      // Building too tall
      else {
        //std::cout << "breaking cuz building too tall\n";
        break;
      }

    }

  } while (true);

  return hoppable;
}

//------------------------------------------------------------------------------

int main() {

  // Generally works, edge case. Is 0 a valid height? Essentially, can I walk straight old_streak_count
  // of the array at height 0, or is 0 something like lava?

  // Currently the algorithm does not continue consecutive 0s as invalid.

  // NOTE - This algorithm does not allow jumping UP. only vertically and down, more
  // general problem would be "minimum jumps to end of array problem"

  // https://www.youtube.com/watch?v=kHWy5nEfRIQ

  // This implementation is slightly modified

  // NOTE - Not an optimal solution

  static const int arr[] = {4, 2, 0, 0, 3, 2, 1, 0, 0};
  std::vector<int> towers (arr, arr + sizeof(arr) / sizeof(arr[0]) );

  util::display(towers);

  if (is_hoppable(towers)) {
    std::cout << "is hoppable\n";
  } else {
    std::cout << "is NOT hoppable\n";
  }

  return 0;
}
