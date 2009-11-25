#include "SDLGrid.h"
#include "Constants.h"
#include "putpixel.h"

/*
 * This is the grid, in SDL.
 *
 * TODO: Figure out how to initialize this to a different size. It's a C++ syntax thing.
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
void SDLGrid::draw() {
    /* Map the color yellow to this display (R=0xff, G=0xFF, B=0x00)
     * Note: If the display is palettized, you must set the palette first.
     * NOTE: Softened the color.
     */
    Uint32 black = SDL_MapRGB(surface->format, 0x00, 0x00, 0x00);
    Uint32 yellow = SDL_MapRGB(surface->format, 0xcc, 0xcc, 0x00);
    Uint32 color = SDL_MapRGB(surface->format, 0xFF, 0xDE, 0x31);

    /*
     * This is _based_ on testgravity.cpp
     *
     * TODO: Reflect shape of grid based on grid's height/weight
     */
    for (int y = 0; y < grid_height; y++) {
        for (int x = 0; x < grid_width; x++) {
			// Check if the "grid_data" contains a '#'. If so, then draw a filled in
			// grid square, else draw "black"
			if (grid_data[(y * grid_width) + x] == '#') {
				for (int j = 0; j < GRID_SIZE; j++) {
					for (int k = 0; k < GRID_SIZE; k++) {
          				putpixel(surface, x*GRID_SIZE+j, y*GRID_SIZE+k, color);
					}
				}
			} else {
				for (int j = 0; j < GRID_SIZE; j++) {
					for (int k = 0; k < GRID_SIZE; k++) {
          				putpixel(surface, x*GRID_SIZE+j, y*GRID_SIZE+k, black);
					}
				}
			}
	    	for (int j = 0; j < GRID_SIZE; j++) {
				// Draw the top and bottom of the "grid" square
                putpixel(surface, (x*GRID_SIZE)+j, (y*GRID_SIZE), yellow);
                putpixel(surface, (x*GRID_SIZE)+j, (y*GRID_SIZE)+GRID_SIZE, yellow);
				// If we're at the last "row", then draw one more row below
				if ((y+1) == grid_height) {
					putpixel(surface, (x*GRID_SIZE)+j, (grid_height*GRID_SIZE), yellow);
				}
	    	}
	    	for (int j = 0; j < GRID_SIZE; j++) {
				// Draw the left and right of the "grid" square
                putpixel(surface, (x*GRID_SIZE), (y*GRID_SIZE)+j, yellow);
                putpixel(surface, (x*GRID_SIZE)+GRID_SIZE, (y*GRID_SIZE)+j, yellow);
				// If we're at the last "row", then draw one more row below
				// NOTE: This seeminly puts a last DOT in the lower right hand corner
				if ((y+1) == grid_height) {
					putpixel(surface, (x*GRID_SIZE)+GRID_SIZE, (grid_height*GRID_SIZE), yellow);
				}
	    	}
        }
    }
}
