/**
 * @file string_compress.hpp
 * @version 1.0
 * @title string compress
 * @author Jabari Dash
 * @brief Compress a string.
 * compress("a") = "a"
 * compress("aaabbb") = "a3b3"
 * compress("aabbaab") = "a2b2a2b"
 *
 * @date 11/11/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#include <iostream>
#include <string>

/**
 * @brief Returns a compressed version of a specified string
 *
 * @param str Specified string to be compressed
 *
 * @return Compressed version of specified
 *
 */
std::string compress(std::string s) {
  int c = 1;
  int i;
  int n = s.length();
  char p;
  std::string s2 = "";

  // Start tracking
  // the character at
  // location 0 in string
  p = s[0];

  // Loop through string
  // character by character
  for (i = 1; i < n; i++) {

    // Check that the current
    // character matches the previous
    if (s[i] == p) {

      c++;  // If so, increment it's count

      // If the streak ended
    } else {
      s2 += p;          // Append the character we were tracking to string
      s2 += c + '0';    // Append its count to the string
      p = s[i];         // Set new character to track equal to p
      c = 1;            // Reset the count to 1
    }
  }

  // Do it one more time
  // for the last sequence
  s2 += p;
  s2 += c + '0';

  return s2;
}

//------------------------------------------------------------------------------

/**
 Compile:
  g++ -o ../bin/string_compress string_compress.cpp

  To run:
  ../bin/./string_compress
*/
int main() {

  std::string s = "aaabbaabbaab";
  std::string c;

  c = compress(s);

  std::cout << "Original: " << s << "\n";

  std::cout << "Compressed: " << c << "\n";

  return 0;
}
