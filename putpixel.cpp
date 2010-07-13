#include "SDL/SDL.h"
#include "Constants.h"
/*
 * Set the pixel at (x, y) to the given value
 * NOTE: The surface must be locked before calling this!
 * NOTE: This is from: 
 *   file:///c:/SDL-1.2.13/docs/html/guidevideo.html#GUIDEVIDEOINTRO
 */
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + (y+GRID_Y_OFFSET) * surface->pitch + (x+GRID_X_OFFSET) * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}

/*
 * This helper function adjusts the row so that its within the 
 * correct boundaries. NOTE: The height is hardcoded (22).
 */
int adjust_y(int row)
{
  if (row < 0) {
    return(0);
  } else if (row > 22*GRID_SIZE) {
    return(22*GRID_SIZE);
  } else {
    return(row);
  }
}

/*
 * This helper function adjusts the columns so that its within the 
 * correct boundaries. NOTE: The width is hardcoded here (10).
 */
int adjust_x(int col)
{
  if (col < 0) {
    return(0);
  } else if (col > 10*GRID_SIZE) {
    return(10*GRID_SIZE);
  } else {
    return(col);
  }
}
