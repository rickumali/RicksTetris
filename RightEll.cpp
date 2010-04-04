#include <iostream>
#include "RightEll.h"
#include "Constants.h"

/*
 * RightEll is the piece that looks like this
 *
 *   ##
 *   ##
 * ####
 *
 * It's also known as "J", "left gun", "inverted L", or "Gamma"
 */
using namespace std;

RightEll::RightEll()
  : Shape ()
{
  string rightell0[3] = 
{ " # ",
  " # ",
  "## " };
  string rightell1[3] = 
{ "   ",
  "###",
  "  #" };
  string rightell2[3] = 
{ " ##",
  " # ",
  " # " };
  string rightell3[3] = 
{ "#  ",
  "###",
  "   " };

  // TODO: Somewhat broken. Why "1"s in the first parameter? It's the rotatation number, no? 
  // The code ROTATES in the direction specified by the first argument. The "1" means rotate
  // rotate 'right'. SIGH!
  init_shape(1,3,rightell0);
  init_shape(1,3,rightell1);
  init_shape(1,3,rightell2);
  init_shape(1,3,rightell3);
}

void RightEll::rotate_left() 
{
  rotate(-1);
}

void RightEll::rotate_right() 
{
  rotate(1);
}

void RightEll::draw()
{
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      cout << shapedata(row, col);
    }
    cout << endl;
  }
}

int RightEll::get_piece_type()
{
  return(RIGHT_ELL); // This is the constant for a RightEll 
}

void RightEll::init_shape(int rotation, int square_size, string in_shape_data[]) {
	rotate(rotation);
	height() = square_size;
	width() = square_size;
  
	for (int i = 0; i < square_size; i++) {
	    cout << "in_shape_data: " << in_shape_data[i] << endl;
		shapedata() += in_shape_data[i];
	}

	cout << "shapedata(): " << shapedata() << endl;
}
