#ifndef ABSTRACT_DATA_TYPE
#define ABSTRACT_DATA_TYPE

#include <sstream>              // std::ostream
#include <string>               // std::string
#include "AbstractObject.hpp"   // AbstractObject

template <class T> class DataType: public AbstractObject {
  public:
    T get_value();
    bool set_value(T data);
    std::string to_string();

  protected:
    T value;
};

//------------------------------------------------------------------------------

template <class T> T DataType<T>::get_value() {
  return value;
}

//------------------------------------------------------------------------------

template <class T> bool DataType<T>::set_value(T t) {
  value = t;
  return true;
}

//------------------------------------------------------------------------------

template <class T> std::string DataType<T>::to_string() {
  std::ostringstream out_string_stream;
  std::string str;

  out_string_stream << value;

  str = out_string_stream.str();

  // Return string object
  return str;
}

//------------------------------------------------------------------------------

template <class T> std::ostream& operator<<(std::ostream& o, DataType<T>& n) {
   o << n.to_string();
   return o;
}

//------------------------------------------------------------------------------

template <class T> bool operator>(DataType<T>& n, DataType<T>& m) {
  return n.get_value() > m.get_value() ? true : false;
}

//------------------------------------------------------------------------------

template <class T> bool operator<(DataType<T>& n, DataType<T>& m) {
  return n.get_value() < m.get_value() ? true : false;
}

//------------------------------------------------------------------------------

template <class T> bool operator>=(DataType<T>& n, DataType<T>& m) {
  return n.get_value() >= m.get_value() ? true : false;
}

//------------------------------------------------------------------------------

template <class T> bool operator<=(DataType<T>& n, DataType<T>& m) {
  return n.get_value() <= m.get_value() ? true : false;
}

//------------------------------------------------------------------------------

template <class T> bool operator==(DataType<T>& n, DataType<T>& m) {
  return n.get_value() == m.get_value() ? true : false;
}

//------------------------------------------------------------------------------

template <class T> bool operator!=(DataType<T>& n, DataType<T>& m) {
  return n.get_value() != m.get_value() ? true : false;
}


#endif
