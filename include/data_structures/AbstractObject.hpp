#ifndef ABSTRACT_OBJECT
#define ABSTRACT_OBJECT

#include <string>

class AbstractObject {
  public:
    virtual std::string to_string() = 0;
};

#endif
