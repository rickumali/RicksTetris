#include <iostream>
#include "LongRow.h"
#include "Constants.h"

using namespace std;

LongRow::LongRow()
  : Shape ()
{
  shape_height[0] = 4;
  shape_height[1] = 4;
  shape_height[2] = 4;
  shape_height[3] = 4;
  shape_width[0] = 4;
  shape_width[1] = 4;
  shape_width[2] = 4;
  shape_width[3] = 4;
  shape_data[0] = "        ####    ";
  shape_data[1] = "  #   #   #   # ";
  shape_data[2] = "        ####    ";;
  shape_data[3] = "  #   #   #   # ";
}

int LongRow::rotate_left() 
{
  rotate(-1);
}

int LongRow::rotate_right() 
{
  rotate(1);
}

void LongRow::draw(int start_x, int start_y) 
{
  for (int row = 0; row < shape_height[rotation]; row++) {
    for (int col = 0; col < shape_width[rotation]; col++) {
      cout << shape_data[rotation][(row*shape_width[rotation])+col];
    }
    cout << endl;
  }
}

int LongRow::get_piece_type()
{
  return(LONG_ROW);
}

