#include "Shape.h"

class Pyramid : public Shape {
  public:
    Pyramid();
    int get_piece_type();
    void rotate_left();
    void rotate_right();
    void draw();
   	void init_shape(int, int, string[]);
};
