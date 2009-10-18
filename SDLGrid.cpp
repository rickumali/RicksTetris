#include "SDLGrid.h"
#include "Constants.h"
#include "putpixel.h"

/*
 * This is the grid, in SDL.
 * 
 */
SDLGrid::SDLGrid(SDL_Surface *surface_in) : Grid() 
{
  surface = surface_in;
}

/*
 * Draws a Grid on the surface
 * NOTE: Based on:
 *   file:///c:/SDL-1.2.13/docs/html/guidevideo.html#GUIDEVIDEOINTRO
 */
void SDLGrid::draw_grid() {
    /* Map the color yellow to this display (R=0xff, G=0xFF, B=0x00)
     * Note: If the display is palettized, you must set the palette first.
     * NOTE: Softened the color.
     */
    Uint32 yellow;
    yellow = SDL_MapRGB(surface->format, 0xcc, 0xcc, 0x00);

    /*
     * This is _based_ on testgravity.cpp
     *
     * TODO: Reflect shape of grid based on grid's height/weight
     */
    for (int y = 0; y < GRID_SIZE * grid_height; y+=1) {
        for (int x = 0; x < GRID_SIZE * grid_width; x+= 1) {
	    if ((y+1)%GRID_SIZE==0) {
                putpixel(surface, x, y, yellow);
	    }
	    if ((x+1)%GRID_SIZE==0) {
                putpixel(surface, x, y, yellow);
	    }
        }
    }
}
