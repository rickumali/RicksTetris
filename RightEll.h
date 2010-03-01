#include "Shape.h"

class RightEll : public Shape {
  public:
    RightEll();
    int get_piece_type();
    int rotate_left();
    int rotate_right();
    void draw();
};
