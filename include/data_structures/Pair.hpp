#ifndef PAIR_H
#define PAIR_H

#include <string>
#include <sstream>

template <class T> class Pair {
  public:
    T x;
    T y;

    Pair(T i, T j);

    T get_x();
    T get_y();
    void set_x(T t);
    void set_y(T t);

    // Override
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

/*
* Return pair as string
*/
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

/*
* Operator overload
*/
template <class T> std::ostream& operator<<(std::ostream& o, Pair<T>& pair) {
   o << pair.to_string();
   return o;
}

#endif
