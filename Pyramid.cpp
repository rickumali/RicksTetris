#include <iostream>
#include "Pyramid.h"
#include "Constants.h"

using namespace std;

/*
 * The pyramid.
 *
 *  #
 * ###
 * 
 */
Pyramid::Pyramid()
  : Shape ()
{
  string pyramid0[3] = 
{ " # ",
  "###",
  "   " };
  string pyramid1[3] = 
{ " # ",
  " ##",
  " # " };
  string pyramid2[3] = 
{ "   ",
  "###",
  " # " };
  string pyramid3[3] = 
{ " # ",
  "## ",
  " # " };

  // TODO: Somewhat broken. Why "1"s in the first parameter? It's the rotatation number, no? 
  // The code ROTATES in the direction specified by the first argument. The "1" means rotate
  // rotate 'right'. SIGH!
  init_shape(1,3,pyramid0);
  init_shape(1,3,pyramid1);
  init_shape(1,3,pyramid2);
  init_shape(1,3,pyramid3);
}

void Pyramid::rotate_left() 
{
  rotate(-1);
}

void Pyramid::rotate_right() 
{
  rotate(1);
}

// NOTE: The "3" is a hardcoded.
void Pyramid::draw()
{
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      // cout << shape_data[rotation][(row*3)+col];
      cout << shapedata(row, col);
    }
    cout << endl;
  }
}

int Pyramid::get_piece_type()
{
  return(PYRAMID); // This is the constant for a Pyramid 
}

void Pyramid::init_shape(int rotation, int square_size, string in_shape_data[]) {
	rotate(rotation);
	height() = square_size;
	width() = square_size;
  
	for (int i = 0; i < square_size; i++) {
	    cout << "in_shape_data: " << in_shape_data[i] << endl;
		shapedata() += in_shape_data[i];
	}

	cout << "shapedata(): " << shapedata() << endl;
}
