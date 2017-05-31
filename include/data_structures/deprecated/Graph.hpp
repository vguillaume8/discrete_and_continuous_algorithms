#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <climits>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Edge.hpp"
#include "Vertex.hpp"
#include "../../../include/util/util.hpp"

class Graph {
  public:

// Instance variables
//------------------------------------------------------------------------------
    std::vector<Edge> edges;
    std::vector<Vertex> verticies;

// Constructors / Destructors
//------------------------------------------------------------------------------
    Graph(std::vector<Edge>& edges, std::vector<Vertex>& verticies) {
      this->edges = edges;
      this->verticies = verticies;
    }


    ~Graph() {
      ;
    }

// Instance functions
//------------------------------------------------------------------------------

    /*
    Returns true if and only if the Graph object's edges list has the egde that
    we are searching for
    */
    bool contains_edge(Edge& edge) {
      int n = this->edges.capacity();
      bool contains = false;

      for (int i = 0; i < n; i++) {
        if (this->edges[i] == edge) {
          contains = true;
          break;
        }
      }
      return contains;
    }

    /*
    Returns true if and only if the Graph object's vertex list has the vertex that
    we are searching for
    */
    bool contains_vertex(Vertex& vertex) {
      int n = this->verticies.capacity();
      bool contains = false;

      for (int i = 0; i < n; i++) {
        if (this->verticies[i] == vertex) {
          contains = true;
          break;
        }
      }
      return contains;
    }

// Static functions
//------------------------------------------------------------------------------

    /*
    Creates a default graph for testing purposes
    */
    static Graph* get_test_graph() {
      std::vector<Vertex> verticies;
      std::vector<Edge> edges;

      // Initialize verticies
      for (int i = 0; i < 6; i++) {
        Vertex v(i);
        verticies.push_back(v);
      }

      // Initialize Edges
      Edge e01(verticies[0], verticies[1], 7);
      Edge e02(verticies[0], verticies[2], 1);
      Edge e04(verticies[0], verticies[4], 2);
      Edge e05(verticies[0], verticies[5], 12);

      Edge e13(verticies[1], verticies[3], 1);
      Edge e15(verticies[1], verticies[5], 4);

      Edge e24(verticies[2], verticies[4], 4);
      Edge e25(verticies[2], verticies[5], 13);

      Edge e34(verticies[3], verticies[4], 3);
      Edge e35(verticies[3], verticies[5], 8);

      Edge e45(verticies[4], verticies[5], 12);

      //Edge e46(verticies[4], verticies[6], 20);

      // Put into vector
      edges.push_back(e01);
      edges.push_back(e02);
      edges.push_back(e04);
      edges.push_back(e05);

      edges.push_back(e13);
      edges.push_back(e15);

      edges.push_back(e24);
      edges.push_back(e25);

      edges.push_back(e34);
      edges.push_back(e35);

      edges.push_back(e45);

      //edges.push_back(e46);

      Graph* graph = new Graph(edges, verticies);

      return graph;
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
        display_NxN_matrix(A, n, 0);
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
          display_NxN_matrix(A, n, 0);
        }
      }
    }


    /*
    * Provided a list of edges, this function returns the original adjacency matrix
    * that will be used with Floyd's
    */
    static void initialize_adjacency_matrix(std::vector<Edge>& edges, std::vector< std::vector<int> >& A, int n) {

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


//------------------------------------------------------------------------------
    /*
    * Display path between vertices i and j, non-inclusive
    */
    static void display_path(std::vector< std::vector<int> >& P, int i, int j) {
      int k = P[i][j];

      if (k == -1) {
        return;
      } else {
        display_path(P, i, k);
        printf("%i, ", k+1);
        display_path(P, k, j);
      }
    }
};

#endif
