#include <iostream>
#include "Square.h"
#include "Constants.h"

using namespace std;

/*
 * This piece is also known as "O", "package", "square", or "block".
 * 
 */
Square::Square()
  : Shape ()
{
  shape_height[0] = 2;
  shape_height[1] = 2;
  shape_height[2] = 2;
  shape_height[3] = 2;
  shape_width[0] = 2;
  shape_width[1] = 2;
  shape_width[2] = 2;
  shape_width[3] = 2;
  shape_data[0] = "####";
  shape_data[1] = "####";
  shape_data[2] = "####";
  shape_data[3] = "####";
}

int Square::rotate_left() 
{
  rotate(-1);
}

int Square::rotate_right() 
{
  rotate(1);
}

void Square::draw() 
{
  for (int row = 0; row < shape_height[rotation]; row++) {
    for (int col = 0; col < shape_width[rotation]; col++) {
      cout << shape_data[rotation][(row*shape_width[rotation])+col];
    }
    cout << endl;
  }
}

int Square::get_piece_type()
{
  return(SQUARE);
}
