#include "Shape.h"

class Pyramid : public Shape {
  public:
    Pyramid();
    int get_piece_type();
    int rotate_left();
    int rotate_right();
    void draw(int, int);
};
