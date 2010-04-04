#include <iostream>
#include "RightSlant.h"
#include "Constants.h"

/*
 * RightSlant is the piece that looks like this
 *
 *   ####
 * ####
 *
 * This piece is also known as "inverted N", or "S".
 *
 * See: http://tetris.wikia.com/wiki/Nintendo_Rotation_System
 */
using namespace std;

RightSlant::RightSlant()
  : Shape ()
{
  string rightslant0[3] = 
{ "   ",
  " ##",
  "## " };
  string rightslant1[3] = 
{ " # ",
  " ##",
  "  #" };
  // TODO: Somewhat broken. Why "1"s in the first parameter? It's the rotatation number, no? 
  // The code ROTATES in the direction specified by the first argument. The "1" means rotate
  // rotate 'right'. SIGH!
  init_shape(1,3,rightslant0);
  init_shape(1,3,rightslant1);
  init_shape(1,3,rightslant0);
  init_shape(1,3,rightslant1);
}

void RightSlant::rotate_left() 
{
  rotate(-1);
}

void RightSlant::rotate_right() 
{
  rotate(1);
}

void RightSlant::draw()
{
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      // cout << shape_data[rotation][(row*shape_width[rotation])+col];
      cout << shapedata(row, col);
    }
    cout << endl;
  }
}

int RightSlant::get_piece_type()
{
  return(RIGHT_SLANT);
}

void RightSlant::init_shape(int rotation, int square_size, string in_shape_data[]) {
	rotate(rotation);
	height() = square_size;
	width() = square_size;
  
	for (int i = 0; i < square_size; i++) {
	    cout << "in_shape_data: " << in_shape_data[i] << endl;
		shapedata() += in_shape_data[i];
	}

	cout << "shapedata(): " << shapedata() << endl;
}
