#include "SDLLeftEll.h"
#include "putpixel.h"
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
SDLLeftEll::SDLLeftEll(SDL_Surface *surface_in) : LeftEll()
{
  surface = surface_in;   
}

void SDLLeftEll::draw(int start_x, int start_y) 
{
    Uint32 color = SDL_MapRGB(surface->format, 0xFF, 0x8C, 0x31);

    start_x *= GRID_SIZE;
    start_y *= GRID_SIZE;
    for (int row = 0; row < shape_height[rotation]*GRID_SIZE; row++) {
      for (int col = 0; col < shape_width[rotation]*GRID_SIZE; col++) {
        if (shape_data[rotation][((row/GRID_SIZE)*shape_width[rotation])+col/GRID_SIZE] == '#') {
           putpixel(surface, adjust_x(col+start_x), adjust_y(row+start_y), color);
        }
      }
    }

    return;
}
