#include "Shape.h"

class LeftEll : public Shape {
  public:
    LeftEll();
    int get_piece_type();
    int rotate_left();
    int rotate_right();
    void draw(int, int);
};
