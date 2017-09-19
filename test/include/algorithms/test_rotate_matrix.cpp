#include <vector>
#include "../../../include/algorithms/rotate_matrix.hpp"
#include "../../../include/util/util.hpp"


int main() {

  // Define rows as int arrays
  static const int arr1[] = {1, 2, 3, 4};
  static const int arr2[] = {5, 6, 7, 8};
  static const int arr3[] = {9, 10, 11, 12};
  static const int arr4[] = {13, 14, 15, 16};

  // Concert rows to vectors
  std::vector<int> row1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  std::vector<int> row2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  std::vector<int> row3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  std::vector<int> row4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));

  // Declare NxN matrix
  std::vector< std::vector<int> > matrix;

  // Add all the rows
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);
  matrix.push_back(row4);

  // Show the matrix before rotation
  util::display_matrix(matrix);

  util::println("");

  // Rotate the matrix
  rotate_matrix_clockwise(matrix);

  // Show the matrix after rotation
  util::display_matrix(matrix);

  return 0;
}
