#include <iostream>
#include "LongRow.h"
#include "Constants.h"

using namespace std;

/*
 * LongRow is the piece that looks like this
 *
 * ########
 * ########
 *
 * Just a long row. 
 *
 * AKA "stick", "straight", "long", "line")
 *
 * See http://en.wikipedia.org/wiki/Tetromino
 */

LongRow::LongRow()
  : Shape ()
{
  string longrow0[4] = 
{ "    ",
  "    ",
  "####",
  "    " };
  string longrow1[4] = 
{ "  # ",
  "  # ",
  "  # ",
  "  # " };
  // TODO: Somewhat broken. Why "1"s in the first parameter? It's the rotatation number, no? 
  // The code ROTATES in the direction specified by the first argument. The "1" means rotate
  // rotate 'right'. SIGH!
  init_shape(1,4,longrow0);
  init_shape(1,4,longrow1);
  init_shape(1,4,longrow0);
  init_shape(1,4,longrow1);
}

void LongRow::rotate_left() 
{
  rotate(-1);
}

void LongRow::rotate_right() 
{
  rotate(1);
}

void LongRow::draw()
{
  // NOTE: 4 is the width and height of the "square" containing the shape
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 4; col++) {
      cout << shapedata(row, col);
    }
    cout << endl;
  }
}

int LongRow::get_piece_type()
{
  return(LONG_ROW);
}

void LongRow::init_shape(int rotation, int square_size, string in_shape_data[]) {
	rotate(rotation);
	height() = square_size;
	width() = square_size;
  
	for (int i = 0; i < square_size; i++) {
		shapedata() += in_shape_data[i];
	}
}
