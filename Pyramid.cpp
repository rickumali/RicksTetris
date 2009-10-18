#include <iostream>
#include "Pyramid.h"
#include "Constants.h"

using namespace std;

Pyramid::Pyramid()
  : Shape ()
{
  rotation = 0;
  shape_height[0] = 3; // NOTE: It was 3...it's now 2
  shape_height[1] = 3;
  shape_height[2] = 3; // NOTE: It was 3...it's now 2
  shape_height[3] = 3;
  shape_width[0] = 3;
  shape_width[1] = 3; // NOTE: It was 3...it's now 2
  shape_width[2] = 3;
  shape_width[3] = 3; // NOTE: It was 3...it's now 2
  shape_data[0] = " # ###   ";
  shape_data[1] = " #  ## # ";
  shape_data[2] = "   ### # ";
  shape_data[3] = " # ##  # ";
}

int Pyramid::rotate_left() 
{
  rotate(-1);
}

int Pyramid::rotate_right() 
{
  rotate(1);
}

// NOTE: The "3" is a hardcoded.
void Pyramid::draw(int start_x, int start_y) 
{
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      cout << shape_data[rotation][(row*3)+col];
    }
    cout << endl;
  }
}

int Pyramid::get_piece_type()
{
  return(PYRAMID); // This is the constant for a Pyramid 
}

// Try to account for "ragged" shapes
int Pyramid::get_width_offset()
{
	switch(rotation) {
	case 0:
		return(0);			
		break;
	case 1:
		return(1);			
		break;
	case 2:
		return(0);			
		break;
	case 3:
		return(1);			
		break;
  }
}

