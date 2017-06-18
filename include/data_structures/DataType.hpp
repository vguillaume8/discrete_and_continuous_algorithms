/**
 * @file DataType.hpp
 * @version 1.0
 * @title DataType
 * @author Jabari Dash
 * @brief Base class to be derived by data types that will be used within a DataStructure.
 * @date 05/31/2017
 * @code
  int main() {

    // Code example
    std::cout << "Hello World" << std::endl;

    return 0;
  }
 * @endcode
 */

#ifndef DATA_TYPE
#define DATA_TYPE

#include <sstream>              // std::ostream
#include <string>               // std::string
#include "AbstractObject.hpp"   // AbstractObject

template <class T> class DataType: public AbstractObject {
  public:

    /**
     * @brief Gives the value of the object back.
     * @return Returns value attribute.
     */
    T get_value();

    /**
     * @brief Sets the value of DataType.
     * @param data The specified data that will be stored into the value field.
     * @return Boolean value that indicates whether or not the value field was successfully set.
     */
    bool set_value(T data);

    /**
     * @brief Returns a printable string representation of the data.
     * @return String representation of data.
     */
    std::string to_string();

  protected:

    /** @brief The value of the data. Example, for DataType<int>, value is an integer. */
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


#endif // DATA_TYPE_H
