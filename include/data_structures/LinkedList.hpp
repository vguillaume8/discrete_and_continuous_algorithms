#ifndef LINKED_LIST
#define LINKED_LIST

#include <vector>                   // std::vector<T>
#include <string>                   // std::string
#include <stdexcept>                // std::out_of_range
#include "AbstractLinkedList.hpp"   // AbstractLinkedList<T>
#include "../util/util.hpp"         // util::to_string(std::vector<T>)

template <class T> class LinkedList: public AbstractLinkedList<T> {
  public:
    // Constructors
    LinkedList();
    LinkedList(std::vector<T> vect);
    ~LinkedList();

    // Methods from DataStructure
    bool contains(T t);
    bool insert(T t);
    bool empty();
    T peek();
    T poll();
    bool remove(T t);
    int size();
    std::string to_string();
    std::vector<T> to_vector();

    // Methods from AbstractIndexedDataStructure
    T get(int index);
    bool insert(T data, int index);
    bool remove_from_index(int index);
    bool set (T data, int index);
    bool swap(int i, int j);

    // Methods from AbstractLinkedList
    bool add_head(T data);
    bool add_tail(T data);
    bool remove_tail();
    bool remove_head();

    // Static methods
    static LinkedList<T> sort(LinkedList<T> linked_list);

  protected:
    static const std::string CLASS_NAME;

    LinkedListNode<T>* get_node(int index);

  private:
    // Attributes
    LinkedListNode<T>* head;
    LinkedListNode<T>* tail;
};

// Name of class for use in error messages
template <class T> const std::string LinkedList<T>::CLASS_NAME = "LinkedList<T>";

//------------------------------------------------------------------------------

/*
* Constructs an empty list
*/
template <class T> LinkedList<T>::LinkedList() {

  // Set head and tail pointers to null to represent an empty list
  head = NULL;
  tail = NULL;

  // length of empty list is 0
  DataStructure<T>::length = 0;
}

//------------------------------------------------------------------------------

/**
* Constructs a list from a std::vector<T>
*/
template <class T> LinkedList<T>::LinkedList(std::vector<T> vect) {

  // Set head and tail pointers to null to represent an empty list
  head = NULL;
  tail = NULL;

  // length of empty list is 0
  DataStructure<T>::length = 0;

  // Get length of vector
  int n = vect.size();

  // Insert each element from vector to back of linked list
  for (int i = 0; i < n; i++) {
    add_tail(vect[i]);
  }
}

//------------------------------------------------------------------------------

template <class T> LinkedList<T>::~LinkedList() {
  ;
}

//------------------------------------------------------------------------------

/**
* Appends an element to the end of the list
*/
template <class T> bool LinkedList<T>::add_tail(T d) {

  // If the list is empty
  if (empty() == true) {

    // Make the head a new node
    head = new LinkedListNode<T>(d);

    // Set the tail pointer to head to represent a list of length 1
    tail = head;

    // Otherwise, append to the tail node
  } else {
      // Make a new node
      LinkedListNode<T>* node = new LinkedListNode<T>(d);

      // Add it to the end of list
      tail->next = node;

      // Change tail pointer to the newly created node
      tail = node;
  }

  // Increment length
  DataStructure<T>::length++;

  return true;
}

//------------------------------------------------------------------------------

/**
* Prepends an element to the front of the list
*/
template <class T> bool LinkedList<T>::add_head(T d) {

  // If the list is empty
  if (empty() == true) {
    head = new LinkedListNode<T>(d);
    tail = head;

  } else {
      // Make a new node
      LinkedListNode<T>* node = new LinkedListNode<T>(d);

      // Add it to the front of list
      node->next = head;

      // Change head pointer to the newly created node
      head = node;
  }

  // Increment length
  DataStructure<T>::length++;

  return true;
}

//------------------------------------------------------------------------------

/**
* Returns the element at a given index
*/
template <class T> T LinkedList<T>::get(int index) {
  LinkedListNode<T>* node = get_node(index);

  return node->get_value();

}

//------------------------------------------------------------------------------

template <class T> LinkedListNode<T>* LinkedList<T>::get_node(int index) {
  // If index is out of bounds
  if (AbstractLinkedList<T>::in_bounds(index) == false) {

    // Throw out of range exception
    std::out_of_range err("LinkedList<T>::get_node(int index): Index out of bounds");
    throw err;

    // If the list is empty
  } else if (empty() == true) {
    // Throw out of range exception
    std::out_of_range err("LinkedList<T>::get_node(int index): List is empty");
    throw err;

    // If the list is not empty, and the index is within the bounds of the list
  } else {

    // If we want the first value
    if (index == 0) {

      return head;

      // If we want the last value
    } else if (index == size()-1) {

      return tail;

      // If we want some value thats not the first or the last
    } else {

      // Start at second element (zero offset)
      int i = 1;
      LinkedListNode<T>* node = head;

      // Traverse up to node before the one we want to return
      while (i <= index) {
        node = node->next;
        i++;
      }

      // Return the ith value
      return node;
    }
  }
}

//------------------------------------------------------------------------------

/**
* Inserts the given element at the given index
*/
template <class T> bool LinkedList<T>::insert(T element, int index) {
  LinkedListNode<T>* node;

  try {
    // Get node at index
    node = get_node(index);

    // Create new node
    LinkedListNode<T>* new_node = new LinkedListNode<T>(element);

    // Set new node's next pointer to current node's next node
    new_node->next = node->next;

    // Change current node's next pointer to new node, effectively pushing
    // the previous node that was at index i back 1 position
    node->next = new_node;

    // Increment length
    DataStructure<T>::length++;

    // Index out of bounds
  } catch (std::out_of_range& error) {
    std::string message;

    message += CLASS_NAME + "::insert(T element, int index) " + CLASS_NAME + " is empty\n" + error.what() + "\n";

    // Throw error
    throw std::out_of_range(message);
  }

  return true;
}

//------------------------------------------------------------------------------

/**
* Returns true if the list has zero elements
*/
template <class T> bool LinkedList<T>::empty() {

  // If the list is length 0, and all pointers are null, return true
  if (DataStructure<T>::length == 0 && head == NULL && tail == NULL) {
    return true;

    // Otherwise there is at least one element in the list
  } else {

    return false;
  }
}

//------------------------------------------------------------------------------

/**
* Returns the value at the front of the linked list without removing it
*/
template <class T> T LinkedList<T>::peek() {
  if (empty()) {
    std::string message;

    message += CLASS_NAME + "::peek() " + CLASS_NAME + " is empty";

    // Throw error
    throw std::out_of_range(message);
  }

  return head->get_value();
}

//------------------------------------------------------------------------------

/**
* Returns and removes the value at the front of the linked list.
*/
template <class T> T LinkedList<T>::poll() {
  T element;

  try {
    // If the list is not empty
    // Get value from head
    element = peek();

    // Set head pointer the next of the current head
    head = head->next;

    // Decrement length
    DataStructure<T>::length--;

  } catch (std::out_of_range& error) {
    std::string message;

    message += CLASS_NAME + "::poll() " + CLASS_NAME + " is empty\n" + error.what() + "\n";

    // Throw error
    throw std::out_of_range(message);
  }

  return element;
}

//------------------------------------------------------------------------------

/**
* Removes the first occurent of a given element
*/
template <class T> bool LinkedList<T>::remove(T element) {
  return true;
}

//------------------------------------------------------------------------------

/**
* Removes the element at the given index
*/
template <class T> bool LinkedList<T>::remove_from_index(int index) {

  // If the index is out of bounds
  if (index < 0 || index >= size()) {

    // Throw out of range exception
    std::out_of_range error("LinkedList<T>::remove(int index): Index out of bounds");
    throw error;

    // If the list is not empty
  } else if (empty() == false) {

    // If there is only one element in the list, or we want to remove node
    // at index 0
    if (size() == 1 || index == 0) {

      // Simply remove the head
      remove_head();

      // If the list has more than one element, and we want to remove the node
      // at the lasy index
    } else if(index == size()-1) {

      // Simply remove the tail
      remove_tail();

      // If the node we would like to remove is not at the beginning or the end
      // of the list, and we have more than one element
    } else {

      // Start at second element (zero offset)
      int i = 1;
      LinkedListNode<T>* node = head;

      // Traverse up to node before the one we want to remove
      while (i < index) {
        node = node->next;
        i++;
      }

      // Set the next of the current node equal to the the next of the next node.
      // Effectively removing the ith node from the chain
      node->next = node->next->next;

      // Decrement length
      DataStructure<T>::length--;
    }
  }
}

//------------------------------------------------------------------------------

template <class T> bool LinkedList<T>::remove_tail() {

  // If the list is not empty
  if (empty() == false) {
    LinkedListNode<T>* node = head;

    // Loop until second to last node
    while (node->next != tail) {
      node = node->next;
    }

    // Set second to last node to the tail
    tail = node;

    // Set next pointer to null to represent end of list
    tail->next = NULL;

    // Decrement length
    DataStructure<T>::length--;

    return true;

  } else {
    return false;
  }
}

//------------------------------------------------------------------------------

template <class T> bool LinkedList<T>::remove_head() {

  // Get the value from head
  T t = head->get_value();

  // Take it off
  poll();

}

//------------------------------------------------------------------------------

template <class T> bool LinkedList<T>::set(T data, int index) {

  // If the index is out of bounds
  if (AbstractLinkedList<T>::in_bounds(index) == false) {

    // Throw out of range exception
    throw std::out_of_range("LinkedList<T>::set(T data, int index): Index out of bounds");

  } else {

    // If index is first index
    if (index == 0) {
      head->set_value(data);

      // If index is last index
    } else if (index == size()-1) {
      tail->set_value(data);

      // If index  is somewhere between the second and second to last
    } else {

      int i = 1;
      LinkedListNode<T>* node = head;

      // loop until desired index
      while (i <= index) {
        node = node->next;
        i++;
      }

      // Change the value of the node at the desired index
      node->set_value(data);
    }
  }
}

//------------------------------------------------------------------------------

template <class T> bool LinkedList<T>::swap(int i, int j) {

  // IF i or j are out of bounds of lsit
  if (i < 0 || j < 0 || i >= size() || j >= size()) {

    // Throw out of range exception
    std::out_of_range e("LinkedList<T>::swap(int index): Index out of bounds");
    throw e;

  } else {

    T temp = get(i);
    set(get(j), i);
    set(temp, j);
  }
}

//------------------------------------------------------------------------------

template <class T> LinkedList<T> LinkedList<T>::sort(LinkedList<T> linked_list) {
  int n = linked_list.size();

  // Bubble sort (for simplicity)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {

      // If the previous is greater than the next
      if (linked_list.get(j) > linked_list.get(j+1)) {

        // Swap their places
        linked_list.swap(j, j+1);
      }
    }
  }

  return linked_list;
}

//------------------------------------------------------------------------------

template <class T> bool LinkedList<T>::contains(T t) {
  bool found = false;

  // If the list is not empty
  if (empty() == false) {
    LinkedListNode<T>* node = head;

    // Traverse entire list
    while (node != NULL) {

      // If the current node is equal the value we are searching
      if (node->get_value() == t) {
        found = true;
        break;
      }
    }
  }

  return found;
}

//------------------------------------------------------------------------------

/**
*
*/
template <class T> bool LinkedList<T>::insert(T t) {
  add_tail(t);
}

//------------------------------------------------------------------------------

/**
* Returns the number of elements in the list
*/
template <class T> int LinkedList<T>::size() {

  return DataStructure<T>::length;
}

//------------------------------------------------------------------------------

template <class T> std::string LinkedList<T>::to_string() {
  std::ostringstream out_string_stream;
  std::string str;

  LinkedListNode<int>* node = head;

  // Traverse full list
  while (node != NULL) {

    // Append each node to outstream
    out_string_stream << "|" << node->to_string() << "| -> ";
    node = node->next;
  }

  // Get string from stream
  str = out_string_stream.str();

  return str;
}

//------------------------------------------------------------------------------

template <class T> std::vector<T> LinkedList<T>::to_vector() {
  std::vector<T> vect;

  LinkedListNode<int>* node = head;

  // Traverse full list
  while (node != NULL) {

    // Append each node to vector
    vect.push_back(node->get_value());
    node = node->next;
  }

  return vect;
}

#endif
