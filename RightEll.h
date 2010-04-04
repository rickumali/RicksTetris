#include "Shape.h"

class RightEll : public Shape {
  public:
    RightEll();
    int get_piece_type();
    void rotate_left();
    void rotate_right();
    void draw();
   	void init_shape(int, int, string[]);
};
