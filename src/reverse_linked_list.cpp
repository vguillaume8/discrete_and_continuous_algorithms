/**
 * @brief Reverse a Singly LinkedList inplace
 */

#include "../include/data_structures/LinkedList.hpp"
#include <iostream>
#include <vector>

template <typename T> int size(LinkedListNode<T>* head) {
  LinkedListNode<T>* node = head->next;
  int size = 1;

  while (node != NULL) {
    node = node->next;
    size++;
  }

  return size;
}

//------------------------------------------------------------------------------

/**
 * @brief More elegant solution. Continuously reverse the pointers

NULL A -> B -> C -> D -> E -> F -> G -> H
  P  H    N

NULL <- A <- B -> C -> D -> E -> F -> G -> H
        P  H    N

NULL <- A <- B <- C -> D -> E -> F -> G -> H
             P  H    N

NULL <- A <- B <- C <- D -> E -> F -> G -> H
                  P  H    N

 * @param head Head of LinkedList
 * @returns Head of reverse LinkedList
 */
template <typename T> LinkedListNode<T>* reverse_linked_list(LinkedListNode<T>* head) {
  LinkedListNode<T>* prev = NULL;
  LinkedListNode<T>* next;

  prev = NULL;

  while (head != NULL) {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }

  return prev;
}

//------------------------------------------------------------------------------

/**
 * @brief Reverse a Singly LinkedList in-place via bubble_sort variation
 * @param head Head of LinkedList
 * @return Pointer to from of new list
 */
template <typename T> LinkedListNode<T>* reverse_linked_list_3(LinkedListNode<T>* head) {
  LinkedListNode<T>* node = head;

  // Get size of lis
  int n = size(node);
  T temp;

  // Bubble everything to the back, stopping one index earlier every time
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n-i-1; j++) {
      temp = node->get_value();
      node->set_value(node->next->get_value());
      node->next->set_value(temp);

      node = node->next;
    }

    node = head;
  }

  return node;
}

//------------------------------------------------------------------------------

int main () {

  std::vector<int> vect {
    1,2,3,4,5,6,7,8,9,10
  };

  LinkedList<int> linked_list(vect);
  LinkedListNode<int>* head = linked_list.get_head();

  util::println(head);
  head = reverse_linked_list(head);
  util::println(head);
  return 0;
}
