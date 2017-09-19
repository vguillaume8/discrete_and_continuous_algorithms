import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

class Node<T> {
  public T value;
  public LinkedList< Node<T> > adjacents = new LinkedList< Node<T> >();

  Node(T value) {
    this.value = value;
  }

  @Override
  public String toString() {
    return this.value.toString();
  }
}

//==============================================================================

class Graph<T> {
  public HashMap<T, Node<T> > nodes = new HashMap<T, Node<T> >();

//------------------------------------------------------------------------------

  public boolean addEdge(T source, T destination) {
    if (this.nodes.containsKey(source) && this.nodes.containsKey(destination)) {

      Node<T> src = this.nodes.get(source);
      Node<T> dst = this.nodes.get(destination);

      // Add them as adjacents to each other
      src.adjacents.add(dst);
      dst.adjacents.add(src);

      // Put them back in the set
      nodes.put(source, src);
      nodes.put(destination, dst);

      return true;
    }

    return false;
  }

//------------------------------------------------------------------------------

  public void insert(T value) {
    this.nodes.put(value, new Node<T>(value));
  }

//------------------------------------------------------------------------------

  public boolean hasPathDFS(T source, T destination) {
    return hasPathDFS(this.nodes.get(source),
                      this.nodes.get(destination),
                      new HashSet<T>());
  }

//------------------------------------------------------------------------------

  public boolean hasPathBFS(T source, T destination) {

    // Get the nodes from the HashMap of nodes
    Node<T> src = this.nodes.get(source);
    Node<T> dst = this.nodes.get(destination);

    // Setup queue of nodes to visit, and set of visited nodes
    Queue< Node<T> > nodesToVisit = new LinkedList< Node<T> >();
    HashSet<T> visited = new HashSet<T>();

    // For reuse
    Node<T> node;

    // Add source as first node to visit
    nodesToVisit.add(src);

    // While our queue of nodes to visit is not empty
    while (!nodesToVisit.isEmpty()) {

      // Dequeue
      node = nodesToVisit.remove();

      // If we are at our target node
      if (node.value == dst.value) {
        return true;
      }

      // If we have already visited the node
      if (visited.contains(node.value)) {
        continue;
      }

      // Mark the node as visited
      visited.add(node.value);

      // Mark all children as nodes that need to be visited
      for (Node <T> child : node.adjacents) {
        nodesToVisit.add(child);
      }
    }

    return false;
  }

//------------------------------------------------------------------------------

  public boolean hasPathDFS(Node<T> source, Node<T> destination, HashSet<T> visited) {

    // If we have already visited this node
    if (visited.contains(source.value)) {
      return false;
    }

    // Mark the node as visited
    visited.add(source.value);

    // If we are at the destination
    if (source.value == destination.value) {
      return true;
    }

    // Check all of this children
    for (Node<T> child : source.adjacents) {
      if (hasPathDFS(child, destination, visited)) {
        return true;
      }
    }

    return false;
  }
}

//==============================================================================

public class TestGraph {
  public static <T> void println(Node<T> node) {
    System.out.println(node.value);
  }

//------------------------------------------------------------------------------

  public static <T> void print(Node<T> node) {
    System.out.print(node.value);
  }

//------------------------------------------------------------------------------

  public static void main(String[] args) {
    Graph<Integer> graph = new Graph<Integer>();

    graph.insert(1);
    graph.insert(2);
    graph.insert(3);
    graph.insert(4);
    graph.insert(5);

    graph.addEdge(1, 5);
    graph.addEdge(1, 3);

    System.out.println(graph.hasPathDFS(1, 3));
    System.out.println(graph.hasPathBFS(1, 3));


  }
}
