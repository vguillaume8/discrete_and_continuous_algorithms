/**
 * @file AbstractObject.hpp
 * @version 1.0
 * @title AbstractObject
 * @author Jabari Dash
 * @brief All classes will inherit from this abstract class.
 * @date 05/31/2017
 */

#ifndef ABSTRACT_OBJECT
#define ABSTRACT_OBJECT

#include <string>    // std::string

class AbstractObject {
  public:

    /**
     * @brief Converts object into printable string
     * @return Returns a string representation of the object.
     */
    virtual std::string to_string() = 0;
};

#endif
