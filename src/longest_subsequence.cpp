#include <string>
#include <iostream>


void longest_subsequence(std::string str);

/*
To compile:
c++ -o bin/longest_subsequence src/longest_subsequence.cpp

To run:
bin/./longest_subsequence

*/

/*
 * Time: O(n)
 * Space: O(1)
 */
void longest_subsequence(std::string str) {
  int n = str.size();
  char old_streak_char;
  char new_streak_char;
  int old_streak_count;
  int new_streak_count;

  // Start off at first index
  new_streak_char = str[0];
  new_streak_count = 1;

  for (int i = 1; i < n; i++) {

    // If the streak continues...
    if (str[i] == new_streak_char) {
      new_streak_count++;
    }

    // If the sequence ended, or we reached end of string
    if (str[i] != new_streak_char || i == n-1) {
      // std::cout << "Streak ended\n";

      // std::cout << "old count of letter " << old_streak_char << ": " << old_streak_count << "\n";
      // std::cout << "new count of letter " << str[i] << ": " << new_streak_count << "\n\n";

      // If the new streak is longer
      if (new_streak_count >= old_streak_count) {

        // Store new stats
        old_streak_char = new_streak_char;
        old_streak_count = new_streak_count;
      }

      // Reset the character
      new_streak_char = str[i];
      new_streak_count = 1;
    }
  }

  // Edge case of string size 1
  if (n == 1) {
    old_streak_char = str[0];
    old_streak_count = 1;
  }

  std::cout << "\nLongest subsequence in " << str << ": " << old_streak_char << ":" << old_streak_count << "\n";

  return;
}

//------------------------------------------------------------------------------

int main() {

  // Sequence at end
  std::string str = "FRAANNNN";     // Works

  // Sequence in middle
  std::string str5 = "AABBBAA!";    // Works

  // Sequence in beginning
  std::string str6 = "AAABB";       // Works

  // Empty String
  std::string str1 = "";            // Works

  // Single character String
  std::string str2 = "A";           // Works

  // Alternating
  std::string str4 = "ABABAB";      // Does not work

  // Alternating 3
  std::string str7 = "AAABBB";      // Works

  // Test
  longest_subsequence(str);
  longest_subsequence(str1);
  longest_subsequence(str2);
  longest_subsequence(str4);
  longest_subsequence(str5);
  longest_subsequence(str6);
  longest_subsequence(str7);

  return 0;
}
