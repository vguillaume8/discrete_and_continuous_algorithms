#include <iostream>
#include <vector>
#include <string>
#include "../../include/util/util.hpp"
#include "../../src/parenthesis_match.hpp"

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

  // Test string
  std::string str = "(Hi I(')m) J(a(b)a)ri";
  std::string str1 = "(((((((((())))))))))";
  std::string str2 = "(((((((()";

  // Put them into a vector
  strings.push_back(str);
  strings.push_back(str1);
  strings.push_back(str2);

  index_pairs = parenthesis_pairs(strings[0], open_token, close_token);
  index_pairs_alternate = parenthesis_pairs_alternate(strings[0], open_token, close_token);

  util::display(index_pairs);
  util::display(index_pairs_alternate);

  index_pairs = parenthesis_pairs(strings[1], open_token, close_token);
  index_pairs_alternate = parenthesis_pairs_alternate(strings[1], open_token, close_token);

  util::display(index_pairs);
  util::display(index_pairs_alternate);

  index_pairs = parenthesis_pairs(strings[2], open_token, close_token);
  index_pairs_alternate = parenthesis_pairs_alternate(strings[2], open_token, close_token);

  util::display(index_pairs);
  util::display(index_pairs_alternate);

  return 0;
}
