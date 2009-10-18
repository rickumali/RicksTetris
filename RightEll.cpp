#include <iostream>
#include "RightEll.h"
#include "Constants.h"

/*
 * RightEll is the piece that looks like this
 *
 *   ##
 *   ##
 * ####
 *
 * It's also known as "J", "left gun", "inverted L", or "Gamma"
 */
using namespace std;

RightEll::RightEll()
  : Shape ()
{
  shape_height[0] = 3;
  shape_height[1] = 3;
  shape_height[2] = 3;
  shape_height[3] = 3;
  shape_width[0] = 3;
  shape_width[1] = 3;
  shape_width[2] = 3;
  shape_width[3] = 3;
  shape_data[0] = " #  # ## ";
  shape_data[1] = "#  ###   ";
  shape_data[2] = " ## #  # ";
  shape_data[3] = "   ###  #";
}

int RightEll::rotate_left() 
{
  rotate(-1);
}

int RightEll::rotate_right() 
{
  rotate(1);
}

void RightEll::draw(int start_x, int start_y) 
{
  for (int row = 0; row < shape_height[rotation]; row++) {
    for (int col = 0; col < shape_width[rotation]; col++) {
      cout << shape_data[rotation][(row*shape_width[rotation])+col];
    }
    cout << endl;
  }
}

int RightEll::get_piece_type()
{
  return(RIGHT_ELL); // This is the constant for a RightEll 
}
