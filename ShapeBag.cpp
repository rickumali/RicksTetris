#include "ShapeBag.h"
#include <cstdlib>

// Constructor
ShapeBag::ShapeBag(): shape_counter(0) {
  for (int i = 0; i < 7; i++)
    shape_array[i] = i+1;
  fisherYatesShuffle(shape_array);
}

// nextshape()
SDLShape *ShapeBag::nextshape() {
  if (--shape_counter < 0) {
    fisherYatesShuffle(shape_array);
    shape_counter = 6;
  }
  return shapes[shape_counter];
}

// addshape()
void ShapeBag::addshape(SDLShape *s) {
  // TODO: Add guard if you add too many
  shapes[shape_counter++] = s;
}

void ShapeBag::fisherYatesShuffle(int ary[])
{
    for(int n=6; n>0; n--)
    {
        int y=rand() % (n+1); //Picks a random number between 0 and n
	std::swap(ary[y], ary[n]); //swaps the randomly selected integer with n
    }
}
