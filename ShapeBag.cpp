#include "ShapeBag.h"
#include <cstdlib>

// Constructor
// Add the numbers 0 through 6 into an array, then shuffle that array
// using fisherYatesShuffle()
ShapeBag::ShapeBag(): shape_counter(0) {
  srand(time(0)); //seed rand() to the amount of seconds since midnight
  for (int i = 0; i < 7; i++)
    shape_array[i] = i;
  fisherYatesShuffle(shape_array);
}

// nextshape()
//
// It's assumed the shape_counter is more than 0 (in other words, addshape()
// increments shape_counter). We count down from the shape_counter, and 
// return the shape at the randomized index, indicated by shape_array[shape_counter]
SDLShape *ShapeBag::nextshape() {
  if (--shape_counter < 0) {
    fisherYatesShuffle(shape_array);
    shape_counter = 6;
  }
  return shapes[shape_array[shape_counter]];
}

// addshape()
//
// TODO: It would be NICE to initialize all the shapes in the bag here.
// Maybe the best approach would be to add another argument for the "Surface"
void ShapeBag::addshape(SDLShape *s) {
  // TODO: Add guard if you add too many
  shapes[shape_counter++] = s;
}

void ShapeBag::fisherYatesShuffle(int ary[])
{
    for(int n=6; n>0; n--)
    {
        int y=rand() % (n+1);      // Picks a random number between 0 and n
	std::swap(ary[y], ary[n]); // swaps the randomly selected integer with n
    }
}
