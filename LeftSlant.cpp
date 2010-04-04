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
 * See: http://tetris.wikia.com/wiki/Nintendo_Rotation_System
 * 
 */
using namespace std;

LeftSlant::LeftSlant()
  : Shape ()
{
  string leftslant0[3] = 
{ "   ",
  "## ",
  " ##" };
  string leftslant1[3] = 
{ "  #",
  " ##",
  " # " };
  // TODO: Somewhat broken. Why "1"s in the first parameter? It's the rotatation number, no? 
  // The code ROTATES in the direction specified by the first argument. The "1" means rotate
  // rotate 'right'. SIGH!
  init_shape(1,3,leftslant0);
  init_shape(1,3,leftslant1);
  init_shape(1,3,leftslant0);
  init_shape(1,3,leftslant1);
}

void LeftSlant::rotate_left() 
{
  rotate(-1);
}

void LeftSlant::rotate_right() 
{
  rotate(1);
}

void LeftSlant::draw()
{
  // The "3" is the height and width of the shape 'square'
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      cout << shapedata(row, col);
    }
    cout << endl;
  }
}

int LeftSlant::get_piece_type()
{
  return(LEFT_SLANT); // This is the constant for a LeftSlant 
}

void LeftSlant::init_shape(int rotation, int square_size, string in_shape_data[]) {
	rotate(rotation);
	height() = square_size;
	width() = square_size;
  
	for (int i = 0; i < square_size; i++) {
	    cout << "in_shape_data: " << in_shape_data[i] << endl;
		shapedata() += in_shape_data[i];
	}

	cout << "shapedata(): " << shapedata() << endl;
}
