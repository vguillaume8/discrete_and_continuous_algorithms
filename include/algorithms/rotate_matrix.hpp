#ifndef ROTATE_MATRIX_H
#define ROTATE_MATRIX_H

#include <vector>
#include "../util/util.hpp"
#include <iostream>

/**
 * @brief Rotate a matrix 90 degrees clockwise
 * time: O(n^2)
 * space: O(1)
 * for an nxn matrix
 */
template <typename T> void rotate_matrix_clockwise(std::vector< std::vector<T> >& matrix) {
  int n = matrix.size();
  T temp;

  // Row by row, column by column, left to right, top down indexing
  for (int i = 0; i < n; i++) {

    // Flip matrix along main diagonal (transpose)
    for (int j = i+1; j < n; j++) {
      temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }

    // Flip each row horizontally
    for (int j = 0; j < n/2; j++) {
      temp = matrix[i][j];
      matrix[i][j] = matrix[i][n-1-j];
      matrix[i][n-1-j] = temp;
    }
  }
}

//------------------------------------------------------------------------------

/**
 * time: O(n^2)
 * space: O(n^2)
 * for an nxn matrix
 */
template <typename T> void rotate_matrix_counter_clockwise(std::vector< std::vector<T> >& matrix) {
  int n = matrix.size();

  std::vector< std::vector<T> > matrix2;

  // Loop by column, going from right to left
  for (int row = 0; row < n; row++) {
    std::vector<T> vect;

    // Loop by row, going top to bottom
    for (int col = 0; col < n; col++) {

      vect.push_back(matrix[col][n-1-row]);
    }

    matrix2.push_back(vect);
  }

  matrix = matrix2;
}

//------------------------------------------------------------------------------

template <typename T> void rotate_matrix_clockwise1(std::vector< std::vector<T> >& matrix) {
  rotate_matrix_counter_clockwise(matrix);
  rotate_matrix_counter_clockwise(matrix);
  rotate_matrix_counter_clockwise(matrix);
}

#endif // ROTATE_MATRIX_H
