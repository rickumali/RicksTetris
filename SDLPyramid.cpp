#include "SDLPyramid.h"
#include "putpixel.h"
#include "Constants.h"

using namespace std;

SDLPyramid::SDLPyramid(SDL_Surface *surface_in) : Pyramid()
{
  surface = surface_in;
}

void SDLPyramid::draw(int start_x, int start_y) 
{
    Uint32 color = SDL_MapRGB(surface->format, 0xB3, 0x33, 0xFF);

    start_x *= GRID_SIZE;
    start_y *= GRID_SIZE;
    // NOTE: 3 used to be shape_height[rotation]
    for (int row = 0; row < 3*GRID_SIZE; row++) {
      // NOTE: 3 used to be shape_width[rotation]
      for (int col = 0; col < 3*GRID_SIZE; col++) {
        // NOTE: 3 used to be shape_width[rotation]
        if (shape_data[rotation][((row/GRID_SIZE)*3)+col/GRID_SIZE] == '#') {
           putpixel(surface, adjust_x(col+start_x), adjust_y(row+start_y), color);
        }
      }
    }

    return;
}
