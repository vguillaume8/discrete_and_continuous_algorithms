#include <vector>
#include <climits>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Edge.hpp"
#include "Vertex.hpp"
#include "../../include/util/util.hpp"

// TODO - CLEAN UP

void shortest_path_floyd(Graph& graph, std::vector< std::vector<int> >& A, std::vector< std::vector<int> >& P, int n, bool print_steps);
void initialize_adjacency_matrix(std::vector<Edge>& edges, std::vector< std::vector<int> >& A, int n);
void display_all_paths_shortest_paths(std::vector< std::vector<int> >& A, std::vector< std::vector<int> >& P, int n);
void display_path(std::vector< std::vector<int> >& P, int i, int j);

//------------------------------------------------------------------------------

/*
* Provided a list of edges, this function returns the original adjacency matrix
* that will be used with Floyd's
*/
void initialize_adjacency_matrix(std::vector<Edge>& edges, std::vector< std::vector<int> >& A, int n) {

  /*
  Initialize adjacency matrix A with original path values
  Loop through all indicies in the and see if there is an edge that connects them

  θ(N^2)
  */
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {

      // If we are going down the diagnol, the distance from
      // a vertex from and to itself is 0
      if (i == j) {
        A[i][j] = 0;

      // If i and j are not equal, then we have two verticies that are different
      // and we need to find the weight of the edge that connects them. If there is
      // no edge, the value will come back as infinity
      } else {
        // Make temporary verticies for values i and j, we will check if an edge connects them
        Vertex u(i);
        Vertex v(j);

        // Find the index of the edge that connects the verticies i and j
        int index = Edge::find(edges, u, v);
        int weight = INT_MAX;

        // If an edge was found, change the weight, otherwise leave it as infinity
        // to represent there is no edge between verticies i and j
        if (index != -1) {
          weight = edges[index].weight;
        }

        // Set the weight of the located edge to the corresponding locations
        A[i][j] = weight;
        A[j][i] = weight;
      }
    }
  }
}

//------------------------------------------------------------------------------

/*
Returns the adjacency matrix of shortest paths for all pairs variables
Floyd's algorithm
*/
static void shortest_path_floyd(Graph& graph, std::vector< std::vector<int> >& A, std::vector< std::vector<int> >& P, int n, bool print_steps) {

  // Get original adjacncy matrix, θ(N^2)
  initialize_adjacency_matrix(graph.edges, A, n);

  if (print_steps == true) {
    printf("A_%i\n", 0);
    util::display_NxN_matrix(A, n, 0);
  }

  //Floyd's Algorithm, θ(N^3)
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (A[i][j] > A[i][k] + A[k][j]) {

          // Never swap if the value we are testing is infinity, Must have this extra
          // Check because otherwise, INT_MAX will add to a number, cause overflow,
          // and come back as less than A[i][j] and ruin the table
          if (A[i][k] != INT_MAX && A[k][j] != INT_MAX) {
            A[i][j] = A[i][k] + A[k][j];
            P[i][j] = k;
          }
        }
      }
    }

    if (print_steps == true) {
      printf("A_%i\n", k+1);
      util::display_NxN_matrix(A, n, 0);
    }
  }
}

//------------------------------------------------------------------------------

/*
* Display path between vertices i and j, non-inclusive
*/
void display_path(std::vector< std::vector<int> >& P, int i, int j) {
  int k = P[i][j];

  if (k == -1) {
    return;
  } else {
    display_path(P, i, k);
    printf("%i, ", k+1);
    display_path(P, k, j);
  }
}

//------------------------------------------------------------------------------

static void display_all_paths_shortest_paths(std::vector< std::vector<int> >& A, std::vector< std::vector<int> >& P, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] < INT_MAX) {
          printf("min path from %i to %i, with cost %i:\n", i+1, j+1, A[i][j]);
          printf("%i, ", i+1);
          display_path(P, i, j);
          printf("%i\n\n\n", j+1);
      } else {
        printf("There is no path from %i to %i\n", i+1, j+1);
      }
    }
  }
}
