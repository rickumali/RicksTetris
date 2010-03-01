#include "Shape.h"

class Square : public Shape {
  public:
    Square();
    int get_piece_type();
    int rotate_left();
    int rotate_right();
    void draw();
};
