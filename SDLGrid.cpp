#include "SDLGrid.h"
#include "Constants.h"
#include "putpixel.h"

/*
 * This is the grid, in SDL.
 *
 * TODO: Figure out how to initialize this to a different size. It's a C++ syntax thing.
 * 
 */
SDLGrid::SDLGrid(SDL_Surface *surface_in)
{
  set_grid(new Grid());
  set_surface(surface_in);
  set_shape_color(SDL_MapRGB(surface->format, 0xFF, 0xDE, 0x31));
}

/*
 * Draws the character based Grid
 */
void SDLGrid::debug_draw() {
	grid->draw();
}

/*
 * Draws the character based Grid
 */
void SDLGrid::clear_rows() {
	grid->clear_rows();
}

/*
 */
bool SDLGrid::any_rows_to_clear() {
	return(grid->any_rows_to_clear());
}
/*
 * animate_rows_to_clear() 
 */
void SDLGrid::animate_rows_to_clear() {
    Uint32 red = SDL_MapRGB(surface->format, 0xFF, 0x00, 0x00);
    for (int y = 0; y < grid->height(); y++) {
		if (grid->clear_this_row(y)) {
            for (int x = 0; x < grid->width(); x++) {
				for (int j = 0; j < GRID_SIZE; j++) {
					for (int k = 0; k < GRID_SIZE; k++) {
          				putpixel(surface, x*GRID_SIZE+j, y*GRID_SIZE+k, red);
					}
				}
            }
		}
    }
}

/*
 * animate_rows_to_clear(int ticks) 
 *
 * In our code, ticks is going to be an integer between 0 and 1000.
 */
void SDLGrid::animate_rows_to_clear(int ticks) {
	int rvalue = 0;
	if (ticks > 255)
		rvalue = 255;
	else
		rvalue = ticks;
    Uint32 red = SDL_MapRGB(surface->format, 255 - rvalue, 0x00, 0x00);
    Uint32 yellow = SDL_MapRGB(surface->format, 0xcc, 0xcc, 0x00);
    for (int y = 0; y < grid->height(); y++) {
		if (grid->clear_this_row(y)) {
            for (int x = 0; x < grid->width(); x++) {
				for (int j = 0; j < GRID_SIZE; j++) {
					for (int k = 0; k < GRID_SIZE; k++) {
          				putpixel(surface, x*GRID_SIZE+j, y*GRID_SIZE+k, red);
					}
				}
			// DUPLICATE (see SDLGrid::draw())
	    	for (int j = 0; j < GRID_SIZE; j++) {
				// Draw the top and bottom of the "grid" square
                putpixel(surface, (x*GRID_SIZE)+j, (y*GRID_SIZE), yellow);
                putpixel(surface, (x*GRID_SIZE)+j, (y*GRID_SIZE)+GRID_SIZE, yellow);
				// If we're at the last "row", then draw one more row below
				if ((y+1) == grid->height()) {
					putpixel(surface, (x*GRID_SIZE)+j, (grid->height()*GRID_SIZE), yellow);
				}
	    	}
	    	for (int j = 0; j < GRID_SIZE; j++) {
				// Draw the left and right of the "grid" square
                putpixel(surface, (x*GRID_SIZE), (y*GRID_SIZE)+j, yellow);
                putpixel(surface, (x*GRID_SIZE)+GRID_SIZE, (y*GRID_SIZE)+j, yellow);
				// If we're at the last "row", then draw one more row below
				// NOTE: This seeminly puts a last DOT in the lower right hand corner
				if ((y+1) == grid->height()) {
					putpixel(surface, (x*GRID_SIZE)+GRID_SIZE, (grid->height()*GRID_SIZE), yellow);
				}
	    	}
			// DUPLICATE (see SDLGrid::draw())
            }
		}
    }
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
    Uint32 grey = SDL_MapRGB(surface->format, 0x99, 0x99, 0x99);

    /*
     * This is _based_ on testgravity.cpp
     *
     * TODO: Reflect shape of grid based on grid's height/weight
     */
    for (int y = 0; y < grid->height(); y++) {
        for (int x = 0; x < grid->width(); x++) {
			// Check if the "grid_data" contains a '#'. If so, then draw a filled in
			// grid square, else draw "black"
			if (grid->griddata(y,x) == '#') {
				for (int j = 0; j < GRID_SIZE; j++) {
					for (int k = 0; k < GRID_SIZE; k++) {
          				putpixel(surface, x*GRID_SIZE+j, y*GRID_SIZE+k, shape_color);
					}
				}
			} else if (grid->griddata(y,x) == 'm') {
				for (int j = 0; j < GRID_SIZE; j++) {
					for (int k = 0; k < GRID_SIZE; k++) {
          				putpixel(surface, x*GRID_SIZE+j, y*GRID_SIZE+k, grey);
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
				if ((y+1) == grid->height()) {
					putpixel(surface, (x*GRID_SIZE)+j, (grid->height()*GRID_SIZE), yellow);
				}
	    	}
	    	for (int j = 0; j < GRID_SIZE; j++) {
				// Draw the left and right of the "grid" square
                putpixel(surface, (x*GRID_SIZE), (y*GRID_SIZE)+j, yellow);
                putpixel(surface, (x*GRID_SIZE)+GRID_SIZE, (y*GRID_SIZE)+j, yellow);
				// If we're at the last "row", then draw one more row below
				// NOTE: This seeminly puts a last DOT in the lower right hand corner
				if ((y+1) == grid->height()) {
					putpixel(surface, (x*GRID_SIZE)+GRID_SIZE, (grid->height()*GRID_SIZE), yellow);
				}
	    	}
        }
    }
}

void SDLGrid::place(int x, int y, SDLShape *shape) {
	grid->place(x, y, shape->get_shape());
	set_shape_color(shape->get_color());
}

void SDLGrid::add_to_mound(int x, int y, SDLShape *shape) {
	grid->add_to_mound(x, y, shape->get_shape());
	set_shape_color(shape->get_color()); // ??? Do I need this?
}

bool SDLGrid::out_of_bounds(int x, int y, SDLShape *shape) {
	return(grid->out_of_bounds(x, y, shape->get_shape()));
}

bool SDLGrid::off_the_side(int x, int y, SDLShape *shape) {
	return(grid->off_the_side(x, y, shape->get_shape()));
}

bool SDLGrid::at_bottom_or_on_mound(int x, int y, SDLShape *shape) {
	return(grid->at_bottom_or_on_mound(x, y, shape->get_shape()));
}

void SDLGrid::set_grid(Grid *grid_in) {
  grid = grid_in;
}

// set_surface()
void SDLGrid::set_surface(SDL_Surface *surface_in) {
  surface = surface_in;
}

// set_shape_color()
void SDLGrid::set_shape_color(Uint32 color_in) {
  shape_color = color_in;
}
