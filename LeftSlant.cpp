#include <iostream>
#include "LeftSlant.h"
#include "Constants.h"

/*
 * LeftSlant is the piece that looks like this
 *
 * ####
 *   ####
 *
 * This piece is also known as "Z", "N", "skew", or "Snake".
 * 
 */
using namespace std;

LeftSlant::LeftSlant()
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
  shape_data[0] = "   ##  ##";
  shape_data[1] = "  # ## # ";
  shape_data[2] = "   ##  ##";
  shape_data[3] = "  # ## # ";
}

int LeftSlant::rotate_left() 
{
  rotate(-1);
}

int LeftSlant::rotate_right() 
{
  rotate(1);
}

void LeftSlant::draw()
{
  for (int row = 0; row < shape_height[rotation]; row++) {
    for (int col = 0; col < shape_width[rotation]; col++) {
      cout << shape_data[rotation][(row*shape_width[rotation])+col];
    }
    cout << endl;
  }
}

int LeftSlant::get_piece_type()
{
  return(LEFT_SLANT); // This is the constant for a LeftSlant 
}
