#include "SDLSquare.h"
#include "Constants.h"
#include "putpixel.h"

/*
 * This piece is also known as "O", "package", "square", or "block".
 * 
 */
SDLSquare::SDLSquare(SDL_Surface *surface_in) : Square() 
{
  surface = surface_in;
}

/*
 * Draws a square on the surface
 * NOTE: Based on:
 *   file:///c:/SDL-1.2.13/docs/html/guidevideo.html#GUIDEVIDEOINTRO
 */
void SDLSquare::draw(int start_x, int start_y) {
    Uint32 color = SDL_MapRGB(surface->format, 0xFF, 0xDE, 0x31);

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

