/**
 * @brief https://www.interviewcake.com/question/cpp/reverse-words
 */

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "../include/util/util.hpp"

void swap(std::string& message, int i, int j) {
  char temp = message[j];
  message[j] = message[i];
  message[i] = temp;
}

//------------------------------------------------------------------------------

void reverse_word(std::string& message, int start, int stop) {

  int i = start;
  int j = stop;

  while (i < j) {
    swap(message, i, j);
    i++;
    j--;
  }
}

//------------------------------------------------------------------------------

void reverse_message(std::string& message, int start, int stop) {

  // Reverse the entire string
  reverse_word(message, 0, stop-1);

  for (int i = 0; i < stop; i++) {
    if (message[i] == ' ') {
      reverse_word(message, start, i-1);
      start = i+1;
    }
  }

  reverse_word(message, start, stop-1);
}

//------------------------------------------------------------------------------

int main() {
  std::string expected = "if into the security recordings you go only pain will you find";
  std::string message = "find you will pain only go you recordings security the into if";

  util::println(message);
  reverse_message(message, 0, message.size());
  util::println(message);

  if (message == expected) {
    util::println("Success");
  } else {
    util::println("Fail");
  }

  return 0;
}
