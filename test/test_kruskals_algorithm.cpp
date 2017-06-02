#include "../include/data_structures/Heap.hpp"
#include "../include/data_structures/Edge.hpp"
#include "../include/util/util.hpp"

int main() {
  std::vector< Edge<int, int> > edges;

  // Build list of edges
  Edge<int, int> e0(1,2,1);
  Edge<int, int> e1(3,4,1);
  Edge<int, int> e2(5,6,1);
  Edge<int, int> e3(5,7,2);
  Edge<int, int> e4(2,3,2);
  Edge<int, int> e5(2,4,2);
  Edge<int, int> e6(4,6,3);
  Edge<int, int> e7(3,6,5);
  Edge<int, int> e8(2,5,6);
  Edge<int, int> e9(4,5,11);
  Edge<int, int> e10(1,6,12);
  Edge<int, int> e11(1,7,13);

  // Build List
  edges.push_back(e5);
  edges.push_back(e8);
  edges.push_back(e0);
  edges.push_back(e6);
  edges.push_back(e1);
  edges.push_back(e9);
  edges.push_back(e7);
  edges.push_back(e11);
  edges.push_back(e2);
  edges.push_back(e3);
  edges.push_back(e4);
  edges.push_back(e10);

  // Sort list of edges
  edges = Heap< Edge<int, int> >::sort(edges);

  return 0;
}
