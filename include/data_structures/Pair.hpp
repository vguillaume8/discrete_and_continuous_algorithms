/**
 * @file Pair.hpp
 * @version 1.0
 * @title Pair
 * @author Jabari Dash
 * @brief Pair is to be extended by classes such as 2 Dimensional Cartesian (x, y) pairs, or Edges in Graphs.
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef PAIR_H
#define PAIR_H

#include <string>    // std::string
#include <sstream>   // std::ostringstream

template <class T> class Pair {
  public:

    /** @brief First element. */
    T x;

    /** @brief Seconds element. */
    T y;

    /**
     * @brief Constructs a pair of two elements.
     * @param i First element.
     * @param j Second element.
     */
    Pair(T i, T j);

    /**
     * @brief Get first element.
     * @return First element.
     */
    T get_x();

    /**
     * @brief Get second element.
     * @return Second element.
     */
    T get_y();

    /**
     * @brief Set first element.
     * @param i Value that will be stored into first element.
     */
    void set_x(T i);

    /**
     * @brief Set second element.
     * @param j Value that will be stored into second element.
     */
    void set_y(T j);

    /**
     * @brief Returns printable string.
     * @return String representation of pair.
     */
    std::string to_string();
};

//------------------------------------------------------------------------------

/*
* Constructor
*/
template <class T> Pair<T>::Pair(T i, T j) {
  x = i;
  y = j;
}

//------------------------------------------------------------------------------

template <class T> T Pair<T>::get_x() {
  return x;
}

//------------------------------------------------------------------------------

template <class T> T Pair<T>::get_y() {
  return y;
}

//------------------------------------------------------------------------------

template <class T> void Pair<T>::set_x(T t) {
  x = t;
}

//------------------------------------------------------------------------------

template <class T> void Pair<T>::set_y(T t) {
  y = t;
}

//------------------------------------------------------------------------------

template <class T> std::string Pair<T>::to_string() {
  std::ostringstream out_string_stream;
  std::string str;

  // Use string stream to concatenate, then build into string object
  out_string_stream << "(" << x << ", " << y << ")";
  str = out_string_stream.str();

  // Return string object
  return str;
}

//------------------------------------------------------------------------------

template <class T> std::ostream& operator<<(std::ostream& o, Pair<T>& pair) {
   o << pair.to_string();
   return o;
}

#endif // PAIR_H
