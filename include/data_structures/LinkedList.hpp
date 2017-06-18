/**
 * @file LinkedList.hpp
 * @version 1.0
 * @title LinkedList
 * @author Jabari Dash
 * @brief Implementation of a Singly LinkedList.
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

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

    /**
     * @brief Constructs an empty list.
     */
    LinkedList();

    /**
     * @brief Constructs a linked list from a vector of elements.
     * @param vect Vector of elements that will be inserted into the list.
     */
    LinkedList(std::vector<T> vect);

    /**
     * @brief Destructor
     */
    ~LinkedList();

    // Methods from DataStructure

    /**
     * @brief Indicates whether the data structure contains a specified element.
     * @param element Specified element to check for.
     * @return True if the structure contains the specified element, otherwise false.
     */
    bool contains(T t);

    /**
     * @brief Inserts a specified element into the data structure.
     * @param element Specified element to be inserted.
     * @return Boolean value indicating whether or not the element was successfully inserted.
     */
    bool insert(T t);

    /**
     * @brief Indicates whether or not the data structure is empty.
     * @return True if the structure has 0 elements, otherwise false.
     */
    bool empty();

    /**
     * @brief Returns, but does not remove the root element of the structure.
     * @return Value at the root of the structure.
     */
    T peek();

    /**
     * @brief Returns and removes the first element of the structure.
     * @return Value at the root of the structure.
     */
    T poll();

    /**
     * @brief Removes a specified element from the structure.
     * @param Specified element to be removed.
     * @return Boolean value as to whether or not the element was successfully removed.
     */
    bool remove(T t);

    /**
     * @brief Determines the size as the number of elements in the structure.
     * @return The number of elements in the structure.
     */
    int size();

    /**
     * @brief
     * @return
     */
    std::string to_string();

    /**
     * @brief Converts the data structure into a printable string.
     * @return String representation of the structure.
     */
    std::vector<T> to_vector();

    // Methods from AbstractIndexedDataStructure

    /**
     * @brief get Returns the element at the despecified index.
     * @param index Index of the desired element.
     * @return The desired element from the provided index.
     */
    T get(int index);

    /**
     * @brief insert Inserts the element at the specified index.
     * @param element The element to be inserted.
     * @param index Specified index in which the element will be inserted
     * @return Returns true if the element was inserted successfully, otherwise false.
     */
    bool insert(T data, int index);

    /**
     * @brief remove_from_index Removes the element at the specified index.
     * @param index Specified index from which the element will be removed
     * @return Returns true if the element was inserted removed, otherwise false.
     */
    bool remove_from_index(int index);

    /**
     * @brief set Overwrites the value at the specified index with the provideds element.
     * @param element The element to be inserted.
     * @param index Specified index in which the element will be inserted
     * @return Returns true if the element was inserted successfully, otherwise false.
     */
    bool set (T data, int index);

    /**
    * @brief Swaps the values of two elements by their specified indicies.
    * @param index_a Specified index of the first element to be swapped from.
    * @param index_b Specified index of the second element to be swapped from.
    * @return Returns true if the elements at index_a and index_b were successfully swapped.
    */
    bool swap(int i, int j);

    // Methods from AbstractLinkedList

    /**
     * @brief Prepends an element to the front of the list.
     * @param element Element to be prepended.
     * @return Bool value that indicates whether or not the insertion was successful or not.
     */
    bool add_head(T data);

    /**
     * @brief Appends an element to the back of the list.
     * @param element Element to be appended.
     * @return Bool value that indicates whether or not the insertion was successful or not.
     */
    bool add_tail(T data);

    /**
     * @brief Removes the last element from the back of the list.
     * @return Bool value that indicates whether or not the removal was successful or not.
     */
    bool remove_tail();

    /**
     * @brief Removes the first element from the front of the list.
     * @return Bool value that indicates whether or not the insertion was removal or not.
     */
    bool remove_head();

    // Static methods

    /**
     * @brief Bubble sorts a LinkedList
     * @param linked_list List to be sorted.
     * @return Returns a LinkedList sorted in ascending order.
     */
    static LinkedList<T> sort(LinkedList<T> linked_list);

  protected:
    /** @brief Name of class. */
    static const std::string CLASS_NAME;

    /**
     * @brief Returns the pointer to a node at a specified index.
     * @param index of specified node.
     * @return Pointer to specified node.
     */
    LinkedListNode<T>* get_node(int index);

  private:
    // Attributes

    /** @brief Pointer to first node in list. */
    LinkedListNode<T>* head;

    /** @brief Pointer to last node in list. */
    LinkedListNode<T>* tail;
};

// Name of class for use in error messages
template <class T> const std::string LinkedList<T>::CLASS_NAME = "LinkedList<T>";

//------------------------------------------------------------------------------

template <class T> LinkedList<T>::LinkedList() {

  // Set head and tail pointers to null to represent an empty list
  head = NULL;
  tail = NULL;

  // length of empty list is 0
  DataStructure<T>::length = 0;
}

//------------------------------------------------------------------------------

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

template <class T> bool LinkedList<T>::remove(T element) {
  return true;
}

//------------------------------------------------------------------------------

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

template <class T> bool LinkedList<T>::insert(T t) {
  add_tail(t);
}

//------------------------------------------------------------------------------

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
