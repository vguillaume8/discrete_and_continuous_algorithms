#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
  public:
    int num;

    Vertex(int num) {
      this->num = num;
    }

//------------------------------------------------------------------------------

    // Default to -1
    Vertex() {
      this->num = -1;
    }

//------------------------------------------------------------------------------

    ~Vertex() {
      ;
    }

//------------------------------------------------------------------------------

    /*
    * Overload == operator to check equality of verticies by num value
    */
    friend bool operator==(const Vertex &v, const Vertex &u) {
      return (v.num == u.num);
    }

//------------------------------------------------------------------------------

    friend bool operator!=(const Vertex &v, const Vertex &u) {
      return (v.num != u.num);
    }
};

#endif
