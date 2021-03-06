#include <iostream>
#include "Square.h"
#include "Constants.h"

using namespace std;

/*
 * This piece is also known as "O", "package", "square", or "block".
 *
 * ##
 * ##
 *
 * The simplest of them all, really.
 * 
 */
Square::Square()
  : Shape ()
{
  string square[2] = 
{ "##",
  "##" };

  // TODO: Somewhat broken. Why "1"s in the first parameter? It's the rotatation number, no? 
  // The code ROTATES in the direction specified by the first argument. The "1" means rotate
  // rotate 'right'. SIGH!
  init_shape(1, 2, square);
  init_shape(1, 2, square);
  init_shape(1, 2, square);
  init_shape(1, 2, square);
}

// TODO: Add an operator method to make "--" act like rotate_left()
void Square::rotate_left() 
{
  rotate(-1);
}

// TODO: Add an operator method to make "++" act like rotate_right()
void Square::rotate_right() 
{
  rotate(1);
}

void Square::draw() 
{
  for (int row = 0; row < height(); row++) {
    for (int col = 0; col < width(); col++) {
      cout << shapedata(row, col);
    }
    cout << endl;
  }
}

int Square::get_piece_type()
{
  return(SQUARE);
}

void Square::init_shape(int rotation, int square_size, string in_shape_data[]) {
	// get length of shape_data to get square_size
	rotate(rotation);
	height() = square_size;
	width() = square_size;
  
	for (int i = 0; i < square_size; i++) {
		shapedata() += in_shape_data[i];
	}
}
