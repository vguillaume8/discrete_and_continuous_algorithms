#include <iostream>
#include <vector>
#include <string>
#include "../include/util/util.hpp"
#include "../include/algorithms/parenthesis_match.hpp"

/**
 Compile:
  g++ -o ../bin/test_parenthesis_match test_parenthesis_match.cpp

  To run:
  ../bin/./test_parenthesis_match
*/

int main() {
  char open_token  = '(';
  char close_token  = ')';

  std::vector <std::string>  strings;
  std::vector <Pair <int> > index_pairs;
  std::vector <Pair <int> > index_pairs_alternate;

  std::string str = "(Hi I(')m) J(a(b)a)ri";
  std::string str1 = "(((((((((())))))))))";
  std::string str2 = "(((((((()";

  strings.push_back(str);
  strings.push_back(str1);
  strings.push_back(str2);

  for (int i = 0; i < strings.size(); i++) {
    index_pairs = parenthesis_pairs(strings[i], open_token, close_token);
    index_pairs_alternate = parenthesis_pairs_alternate(strings[i], open_token, close_token);

    std::cout << "Method 1: ";
    util::display(index_pairs);

    std::cout << "Method 2: ";
    util::display(index_pairs_alternate);

    std::cout << std::endl;
  }

  return 0;
}
