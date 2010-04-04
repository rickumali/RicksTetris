#include "Shape.h"

class LeftEll : public Shape {
  public:
    LeftEll();
    int get_piece_type();
    void rotate_left();
    void rotate_right();
    void draw();
   	void init_shape(int, int, string[]);
};
