#include <iostream>
#include "LeftEll.h"
#include "Constants.h"

/*
 * LeftEll is the piece that looks like this
 *
 * ##
 * ##
 * ####
 *
 * It's also known as "L", "gun", or "right gun".
 */
using namespace std;

LeftEll::LeftEll()
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
  shape_data[0] = " #  #  ##";
  shape_data[1] = "   ####  ";
  shape_data[2] = "##  #  # ";
  shape_data[3] = "  ####   ";
}

int LeftEll::rotate_left() 
{
  rotate(-1);
  cout << "LeftEll::rotation = " << rotation << endl;
}

int LeftEll::rotate_right() 
{
  rotate(1);
  cout << "LeftEll::rotation = " << rotation << endl;
}

void LeftEll::draw(int start_x, int start_y) 
{
  for (int row = 0; row < shape_height[rotation]; row++) {
    for (int col = 0; col < shape_width[rotation]; col++) {
      cout << shape_data[rotation][(row*shape_width[rotation])+col];
    }
    cout << endl;
  }
}

int LeftEll::get_piece_type()
{
  return(LEFT_ELL); // This is the constant for a LeftEll 
}
