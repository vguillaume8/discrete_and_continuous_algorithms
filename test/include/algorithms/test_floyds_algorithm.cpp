#include <stdio.h>
#include "../include/data_structures/deprecated/Vertex.hpp"
#include "../include/data_structures/deprecated/Edge.hpp"
#include "../include/data_structures/deprecated/Graph.hpp"
#include "../include/util/util.hpp"

int main() {

  // Get test graph
  Graph* graph = Graph::get_test_graph();

  // Get the edges and verticies from the graph
  std::vector<Edge> edges = graph->edges;
  std::vector<Vertex> verticies = graph->verticies;

  // Initialize nxn matrix A to all 0s, and P to all -1
  // Get number of verticies
  int n = (int) graph->verticies.capacity();

  // Allocate space for Adjacency matrix and Path matrix
  std::vector< std::vector<int> > A(n, std::vector<int>(n, 0));
  std::vector< std::vector<int> > P(n, std::vector<int>(n, -1));

  // Generate the matricies
  Graph::shortest_path_floyd(*graph, A, P, n, false);

  // Display the Adjacency and Path matrix
  display_NxN_matrix(A, n, 0);
  display_NxN_matrix(P, n, 1);

  // List all shortest paths
  Graph::display_all_paths_shortest_paths(A, P, n);

  return 0;
}
