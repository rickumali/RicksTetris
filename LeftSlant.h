#include "Shape.h"

class LeftSlant : public Shape {
  public:
    LeftSlant();
    int get_piece_type();
    int rotate_left();
    int rotate_right();
    void draw();
};
