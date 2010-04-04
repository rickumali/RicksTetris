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
  string leftell0[3] = 
{ " # ",
  " # ",
  " ##" };
  string leftell1[3] = 
{ "   ",
  "###",
  "#  " };
  string leftell2[3] = 
{ "## ",
  " # ",
  " # " };
  string leftell3[3] = 
{ "  #",
  "###",
  "   " };

  // TODO: Somewhat broken. Why "1"s in the first parameter? It's the rotatation number, no? 
  // The code ROTATES in the direction specified by the first argument. The "1" means rotate
  // rotate 'right'. SIGH!
  init_shape(1,3,leftell0);
  init_shape(1,3,leftell1);
  init_shape(1,3,leftell2);
  init_shape(1,3,leftell3);
}

void LeftEll::rotate_left() 
{
  rotate(-1);
}

void LeftEll::rotate_right() 
{
  rotate(1);
}

void LeftEll::draw()
{
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      // cout << shape_data[rotation][(row*shape_width[rotation])+col];
      cout << shapedata(row, col);
    }
    cout << endl;
  }
}

int LeftEll::get_piece_type()
{
  return(LEFT_ELL); // This is the constant for a LeftEll 
}

void LeftEll::init_shape(int rotation, int square_size, string in_shape_data[]) {
	rotate(rotation);
	height() = square_size;
	width() = square_size;
  
	for (int i = 0; i < square_size; i++) {
	    cout << "in_shape_data: " << in_shape_data[i] << endl;
		shapedata() += in_shape_data[i];
	}

	cout << "shapedata(): " << shapedata() << endl;
}
