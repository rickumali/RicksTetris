#include <iostream>
#include "Pyramid.h"
#include "Constants.h"

using namespace std;

Pyramid::Pyramid()
  : Shape ()
{
  rotation = 0;
  shape_height[0] = 3;
  shape_height[1] = 3;
  shape_height[2] = 3;
  shape_height[3] = 3;
  shape_width[0] = 3;
  shape_width[1] = 3;
  shape_width[2] = 3;
  shape_width[3] = 3;
  shape_data[0] = " # ###   ";
  shape_data[1] = " #  ## # ";
  shape_data[2] = "   ### # ";
  shape_data[3] = " # ##  # ";
}

int Pyramid::rotate_left() 
{
  rotate(-1);
  cout << "Pyramid::rotation = " << rotation << endl;
}

int Pyramid::rotate_right() 
{
  rotate(1);
  cout << "Pyramid::rotation = " << rotation << endl;
}

void Pyramid::draw(int start_x, int start_y) 
{
  for (int row = 0; row < shape_height[rotation]; row++) {
    for (int col = 0; col < shape_width[rotation]; col++) {
      cout << shape_data[rotation][(row*shape_width[rotation])+col];
    }
    cout << endl;
  }
}

int Pyramid::get_piece_type()
{
  return(PYRAMID); // This is the constant for a Pyramid 
}

