#include "SDLRightEll.h"
#include "putpixel.h"
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
SDLRightEll::SDLRightEll(SDL_Surface *surface_in) : RightEll()
{
  surface = surface_in;   
}

void SDLRightEll::draw(int start_x, int start_y) 
{
    Uint32 color = SDL_MapRGB(surface->format, 0x00, 0x90, 0xFF);

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
