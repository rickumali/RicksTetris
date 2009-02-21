#include "Shape.h"

class RightSlant : public Shape {
  public:
    RightSlant();
    int get_piece_type();
    int rotate_left();
    int rotate_right();
    void draw(int, int);
};
