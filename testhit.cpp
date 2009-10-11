#include <iostream>
#include <string>
#include <cstdio>
#include "SDL/SDL.h"
#include "SDL_ttf.h"
#include "SDLSquare.h"
#include "SDLPyramid.h"
#include "SDLLeftSlant.h"
#include "SDLRightSlant.h"
#include "SDLLongRow.h"
#include "SDLLeftEll.h"
#include "SDLRightEll.h"
#include "putpixel.h"
#include "Constants.h"
#include "Timer.h"

using std::cout;
using std::endl;
using std::string;

// For events
SDL_Event event;

// The surfaces that will be used
SDL_Surface *screen = NULL;

// Font
TTF_Font *font;

//The frames per second
const int FRAMES_PER_SECOND = 20;

void write_instruction_line(SDL_Surface *);
void write_status_line(SDL_Surface *, char *);
void draw_grid(SDL_Surface *);
bool check_hit_edge(Shape *, int, int);
bool check_hit_bottom(Shape *, int, int);

int main( int argc, char* args[] )
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;    
    }
    
    if (SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL) == -1)
    {
        return 1;
    }
    
    if (TTF_Init()==-1) {
	return 1;
    }

    font=TTF_OpenFont("c:\\MinGW\\ttf-bitstream-vera-1.10\\VeraBd.ttf", 16);
    if (!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }
    
    // Set up the screen
    // NOTE: We use HWSURFACE to take advantage of double-buffer
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE);
    
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return 1;    
    }
    
    //Set the window caption
    SDL_WM_SetCaption( "testhit", NULL );

    // Create a shape
    Shape* square = new SDLPyramid(screen);
    Shape* selected_shape = square;
    
    // Starting location for ALL shapes
    int x = 5;
    int y = -1 * selected_shape->get_height();

    int gravity = 1; // rows per second; can be fractional

	char status[50]; // Used for status line
	sprintf(status, "Hello!");

    // Timer
    Timer fps;
    
    bool quit = false;
    fps.start();
    while (quit == false) {
	    while (SDL_PollEvent(&event)) {
		    if (event.type == SDL_QUIT) {
			    quit = true;
		    }

		    if (event.type == SDL_KEYDOWN) {
			    switch(event.key.keysym.sym) {
				    case SDLK_UP:
					    selected_shape->rotate_right();
					    sprintf(status, "Rotate right!");
					    break;
				    case SDLK_DOWN:
					    selected_shape->rotate_left();
					    sprintf(status, "Rotate left!");
					    break;
				    case SDLK_LEFT:
						if (check_hit_edge(selected_shape, --x, y))
				        	x++;
					    break;
				    case SDLK_RIGHT:
						if (check_hit_edge(selected_shape, ++x, y))
				        	x--;
					    break;
				    case SDLK_s:
						if (--gravity < 1) {
							gravity = 1;
						}
						break;
				    case SDLK_f:
						if (++gravity > 20) {
							gravity = 20;
						}
						break;
				    case SDLK_q:
					    quit = true;
					    break;
			    }
		    }
	    }

        if( fps.get_ticks() > (1000/gravity) )
        {
			if (check_hit_bottom(selected_shape,x,y++))
	        	y--;
			fps.start(); // Restart the clock
	    }

	    /* Redraw "everything" */
	    if ( SDL_MUSTLOCK(screen) ) {
    		if ( SDL_LockSurface(screen) < 0 ) {
    		    cout << "Can't lock screen:" << SDL_GetError() << std::endl;
    		    return 1;
    		}
	    }

		draw_grid(screen);
		sprintf(status, "x=%d, y=%d, gravity=%d", x, y, gravity);
		write_status_line(screen, status);
		write_instruction_line(screen);
		selected_shape->draw(x, y);

	    if (SDL_MUSTLOCK(screen)) {
			SDL_UnlockSurface(screen);
	    }

	    if (SDL_Flip(screen) == -1) {
		    cout << "Problem with the SDL_Flip()" << std::endl;
		    return 1;
	    }
    }

    TTF_CloseFont(font);
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
    
    return 0;    
}

/*
 * Check if you're at the boundaries!
 *
 */
bool check_hit_edge(Shape *shape, int shape_x, int shape_y) {
	// Check if the shape location is on the EDGE of the grid
	if (shape_x < 0)
		return true;
	// if ((shape_x + shape->get_width()+shape->get_width_offset()) > 10)
	if ((shape_x + shape->get_width()) > 10)
		return true;
	return false;
}

bool check_hit_bottom(Shape *shape, int shape_x, int shape_y) {
	// Check if the shape location is at the bottom
	if ((shape_y + shape->get_height()) > 21)
		return true;
	return false;
}

/*
 * Draws a grid on the surface
 * NOTE: Based on:
 *   file:///c:/SDL-1.2.13/docs/html/guidevideo.html#GUIDEVIDEOINTRO
 */
void draw_grid(SDL_Surface *surface) {
    /* Map the color yellow to this display (R=0xff, G=0xFF, B=0x00)
     * Note: If the display is palettized, you must set the palette first.
     * NOTE: Softened the color.
     */
    Uint32 yellow = SDL_MapRGB(surface->format, 0xcc, 0xcc, 0x00);
    Uint32 blackColor = SDL_MapRGB(surface->format, 0, 0, 0);

    /* Draw the entire screen EXCEPT for the status line area */
    SDL_Rect all_but_status_line_offset;
    all_but_status_line_offset.x = 0;
    all_but_status_line_offset.y = 0;
    all_but_status_line_offset.h = surface->h;
    all_but_status_line_offset.w = surface->w;
    SDL_FillRect (surface, &all_but_status_line_offset, blackColor);

    // The (h - GRID_SIZE * 2) leaves the last two "rows" blank for an
    // instructions line and a status line
    // The (x - GRID_SIZE * 22) leaves the game grid; the logic is backwards in 
    // version of the code, but y is the height, and it says the height is 0 to 
    // "2 lines from the bottom". x is the width, and it says the grid should be
    // drawn from 0 (left) to 22 columns from the right. LAME!
    for (int y = 0; y < (surface->h - GRID_SIZE * 2); y+=1) {
        for (int x = 0; x < (surface->w - GRID_SIZE * 22); x+= 1) {
	    if ((y+1)%GRID_SIZE==0) {
                putpixel(surface, x, y, yellow);
	    }
	    if ((x+1)%GRID_SIZE==0) {
                putpixel(surface, x, y, yellow);
	    }
        }
    }

    return;
}

/*
 * Writes a line of status to the status line. This first 
 * blanks out the status line, THEN it draws the message into the 
 * blaked out status line.
 */
void write_instruction_line(SDL_Surface *screen) {
    Uint32 blackColor = SDL_MapRGB(screen->format, 0, 0, 0);
    SDL_Color textColor = {0, 255, 0};
    SDL_Surface *message = TTF_RenderText_Solid( font, "Key S, Slower; F, Faster", textColor);

    // This is the entire blank area of the status line
    SDL_Rect status_line_offset;
    status_line_offset.x = 0 * GRID_SIZE;
    status_line_offset.y = 22 * GRID_SIZE; // This is the next to last "row"
    status_line_offset.h = 1 * GRID_SIZE - 1;
    status_line_offset.w = 10 * GRID_SIZE - 1;

    // This is the area for the message
    SDL_Rect text_offset;
    text_offset.x = 2;
    text_offset.y = 22 * GRID_SIZE; // This is the next to last "row"

    SDL_FillRect (screen, &status_line_offset, blackColor);
    SDL_BlitSurface (message, NULL, screen, &text_offset);
    SDL_FreeSurface(message);
}

/*
 * Writes a line of status to the status line. This first 
 * blanks out the status line, THEN it draws the message into the 
 * blaked out status line.
 */
void write_status_line(SDL_Surface *screen, char *s) {
    Uint32 blackColor = SDL_MapRGB(screen->format, 0, 0, 0);
    SDL_Color textColor = {0, 255, 0};
    SDL_Surface *message = TTF_RenderText_Solid( font, s, textColor);

    // This is the entire blank area of the status line
    SDL_Rect status_line_offset;
    status_line_offset.x = 0 * GRID_SIZE;
    status_line_offset.y = 23 * GRID_SIZE;
    status_line_offset.h = 1 * GRID_SIZE - 1;
    status_line_offset.w = 10 * GRID_SIZE - 1;

    // This is the area for the message
    SDL_Rect text_offset;
    text_offset.x = 2;
    text_offset.y = 23 * GRID_SIZE;

    SDL_FillRect (screen, &status_line_offset, blackColor);
    SDL_BlitSurface (message, NULL, screen, &text_offset);
    SDL_FreeSurface(message);
}
