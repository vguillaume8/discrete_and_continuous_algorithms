/**
 * @brief I opened up a dictionary to a page in the middle and started flipping through,
 * looking for words I didn't know. I put each word I didn't know at increasing indices
 * in a huge vector I created in memory. When I reached the end of the dictionary,
 * I started from the beginning and did the same thing until I reached the page I started at.
 * Now I have a vector of words that are mostly alphabetical, except they start
 * somewhere in the middle of the alphabet, reach the end, and then start from the
 * beginning of the alphabet. In other words, this is an alphabetically ordered vector
 * that has been "rotated." For example:
 */

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> words {
  "ptolemaic",
  "retrograde",
  "supplant",
  "undulate",
  "xenoepist",
  "asymptote", // <-- rotates here!
  "babka",
  "banoffee",
  "engender",
  "karpatka",
  "othellolagkage",
};

//------------------------------------------------------------------------------

/**
* @brief Finds the rotation point via modified binary search O(log(n)) time
* @param words Vector of words
* @return Index of rotation point
*/
int rotation_point(const std::vector<std::string>& words) {
  int left = 0;
  int right = words.size() - 1;

  while (left < right) {

      int middle = (left + right) / 2;

      if (words[middle] >= words[0]) {
        left = middle;
      }
      else {
        right = middle;
      }

      if (left + 1 == right) {
        break;
      }
  }

  return right;
}

//------------------------------------------------------------------------------

/**
* @brief Finds the rotation point via linear search O(n) time
* @param words Vector of words
* @return Index of rotation point
*/
int rotation_point_linear(std::vector<std::string> words) {
  int length = words.size();
  int rotation_point = -1;

  for (int j = 1; j < length; j++) {

    if (j > 0 && words[j-1] > words[j]) {
      rotation_point = j;
      break;
    }
  }

  return rotation_point;
}

//------------------------------------------------------------------------------

int main() {

  std::cout << "Rotation point: " << rotation_point(words) << std::endl;

  return 0;
}
