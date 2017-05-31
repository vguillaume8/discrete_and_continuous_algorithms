#include "../../include/data_structures/Stack.hpp"
#include "../../include/data_structures/Pair.hpp"
#include <vector>
#include <string>

/*
* Generic solution
*
* F(n) is O(n) in terms of:
*   data comparisons
*   memory use
*   pushes / pops
*
* Where n is length of array
*/
template <class T> std::vector< Pair <int> > locate_pairs(std::vector<T> array, T open_token, T close_token) {
  std::vector< Pair<int> > index_pairs;
  Stack<int> stack;
  int length = array.size();

  for (int i = 0; i < length; i++) {

    // Push last open token's index onto stack
    if (array[i] == open_token) {
      stack.push(i);

    // Pop last open token's index off of stack
    // and create ordered pair with first found
    // close token's index (i)
    } else if (array[i] == close_token) {
      int x = stack.pop();
      int y = i;

      Pair<int> p(x, y);

      index_pairs.push_back(p);
    }
  }

  return index_pairs;
}

//------------------------------------------------------------------------------

/*
* String / char specific implementation
*/
std::vector< Pair <int> > parenthesis_pairs(std::string str, char open_token, char close_token) {
  std::vector< Pair<int> > index_pairs;
  Stack<int> stack;
  int length = str.length();

  for (int i = 0; i < length; i++) {
    if (str[i] == open_token) {
      stack.push(i);

  } else if (str[i] == close_token) {
      int x = stack.pop();
      int y = i;

      Pair<int> p(x, y);

      index_pairs.push_back(p);
    }
  }

  return index_pairs;
}

//------------------------------------------------------------------------------

/*
* This function was inspired by the partition function in quick sort as
* a proof of concept that there are multiple solutions to this problem
*/
std::vector< Pair<int> > parenthesis_pairs_alternate(std::string str, char open_token, char close_token) {
  std::vector< Pair<int> > index_pairs;
  int length = str.length();
  int l = 0;
  int r = length - 1;

  // As long as the left and right pointers remain within the bounds of the array
  while (r >= 0 && l < length) {

    // Start left and right from left and right most ends of array, respectively
    l = 0;
    r = length - 1;

    // Find first close_token from left to right
    // Do not increment l out of the bounds of the string length
    while (str[l] != close_token && l < length) {
      l++;
    }

    // Find last open_token from right to left
    // Do not increment r out of the bounds of the string length
    while (r >= 0 && (str[r] != open_token || r >= l)) {
      r--;
    }

    // If the left and right index are still within the array bounds
    if (l < length && r >= 0) {

      // If the left pointer points to an open_token
      // and the right pointer points to a close_token
      if (str[l] == close_token && str[r] == open_token) {

        // Create a pair, and add it to the list of pairs
        Pair<int> p(r, l);
        index_pairs.push_back(p);

        // Erase these values where these tokens are so that we
        // do not go into an infinite loop
        // ASSUMES the token is not 'a' or 'b'
        str[l] = 'a';
        str[r] = 'b';
      }
    }
  }

  return index_pairs;
}
