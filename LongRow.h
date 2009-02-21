#include "Shape.h"

class LongRow : public Shape {
  public:
    LongRow();
    int get_piece_type();
    int rotate_left();
    int rotate_right();
    void draw(int, int);
};

