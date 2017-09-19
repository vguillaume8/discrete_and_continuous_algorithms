/**
 * @file Stack.hpp
 * @version 1.0
 * @title Stack
 * @author Jabari Dash
 * @brief VectorStructure implementation of a Stack.
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef STACK_H
#define STACK_H

#include <string>               // std::string
#include <vector>               // std::vector
#include <stdexcept>            // std::out_of_range
#include "VectorStructure.hpp"  // VectorStructure<T>

template <class T> class Stack: public VectorStructure<T> {
  public:
    // Stack instance methods

    /**
     * @brief Pushes a specified element onto the top of the Stack.
     * @param element Specified element.
     * @return Boolean value that indicates whether or not the operation was successful.
     */
    bool push(T element);

    /**
     * @brief Removes and returns the element at the top of the stack.
     * @return Boolean value that indicates whether or not the operation was successful.
     */
    T pop();

    /**
     * @brief Returns the element at the top of the stack without removing it.
     * @return Boolean value that indicates whether or not the operation was successful.
     */
    T top();

    // Abstract methods from DataStructure to implement

    /**
     * @brief Pushes a specified element onto the top of the Stack.
     * @param element Specified element.
     * @return Boolean value that indicates whether or not the operation was successful.
     */
    bool insert(T element) override;

    /**
     * @brief
     * @param
     * @return
     */
    bool remove(T element) override;

  protected:

    /** @brief Name of class. */
    static const std::string CLASS_NAME;


    /**
     * @brief Returns the element at the top of the stack without removing it.
     * @return Boolean value that indicates whether or not the operation was successful.
     */
    T peek() override;

    /**
     * @brief Removes and returns the element at the top of the stack.
     * @return Boolean value that indicates whether or not the operation was successful.
     */
    T poll() override;

  private:
};

template <class T> const std::string Stack<T>::CLASS_NAME = "Stack<T>";

//------------------------------------------------------------------------------

template <class T> bool Stack<T>::insert(T element) {
  // Push element onto back of vector
  return VectorStructure<T>::push_back(element);
}

//------------------------------------------------------------------------------

template <class T> T Stack<T>::peek() {

  // If the stack is already empty, throw an error
  if (VectorStructure<T>::empty() == true) {
    std::string message;

    message += CLASS_NAME + "::peek() " + CLASS_NAME + " is empty";

    // Throw error
    throw std::out_of_range(message);
  }

  // Get last element from vector
  T element = VectorStructure<T>::elements.back();

  // Return element from top
  return element;
}

//------------------------------------------------------------------------------

template <class T> T Stack<T>::poll() {
  T element;

  try {
    // Get element from top of stack
    element = Stack<T>::peek();

    // Pop it off
    VectorStructure<T>::pop_back();

    // Error thrown if the list is empty
  } catch (std::out_of_range& error) {
    std::string message;

    // Concated error messages
    message += CLASS_NAME + "::poll() " + CLASS_NAME + " is empty\n" + error.what() + "\n";

    // Throw error
    throw std::out_of_range(message);
  }

  return element;
}

//------------------------------------------------------------------------------

template <class T> bool Stack<T>::push(T element) {
  return insert(element);
}

//------------------------------------------------------------------------------

template <class T> T Stack<T>::pop() {
  T element;

  try {
    // Remove element from top of stack
    element = poll();

    // Error thrown by poll() if the stack is empty
  } catch (std::out_of_range& error) {
    std::string message;

    message += CLASS_NAME + "::pop() " + CLASS_NAME + " is empty\n" + error.what() + "\n";

    // Throw an error
    throw std::out_of_range(message);
  }

  return element;
}

//------------------------------------------------------------------------------

template <class T> bool Stack<T>::remove(T element) {

  // Find the index of element
  int index = VectorStructure<T>::find(element);
  bool removed = false;

  // If the element was found
  if (index != VectorStructure<T>::ELEMENT_NOT_FOUND) {

    // Delete it from vector
    VectorStructure<T>::elements.erase(VectorStructure<T>::elements.begin() + index);

    // Removal was successful
    removed = true;
  }

  return removed;
}

//------------------------------------------------------------------------------

template <class T> T Stack<T>::top() {
  T element;

  try {
    // Get the first element in the vector
    element = VectorStructure<T>::peek();

    // If the Vector Structure is empty, an error is thrown
  } catch (std::out_of_range& error) {
    std::string what = "Stack<T>::top() Stack is empty\n";

    // Concate error message from the caught error
    what += error.what();

    throw std::out_of_range(what);
  }

  return element;
}

#endif // STACK_H
