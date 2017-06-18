#include <iostream>

#include "../include/data_structures/Vertex.hpp"
#include "../include/data_structures/Edge.hpp"
#include "../include/data_structures/Graph.hpp"

int main() {

  Vertex<int> t(1);
  Vertex<int> u(2);
  Vertex<int> v(3);

  Edge<double, int> e(u.value, v.value, 2);
  Edge<double, int> f(t.value, v.value, 3);

  if (v > u) {
    std::cout << v << ">" << u.to_string() << std::endl;
  }

  if (f > e) {
    std::cout << f << " > " << e.to_string() << std::endl;
  }

  return 0;
}
