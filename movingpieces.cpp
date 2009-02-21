#include "SDL/SDL.h"
#include <string>

//The attributes of the screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// Grid attributes
const int GRID_SIZE = 20;

// Pieces
const int SQUARE = 1;
const int PYRAMID = 2;
const int LEFT_SLANT = 3;
const int RIGHT_SLANT = 4;
const int LONG_ROW = 5;

// Piece dimensions (no rotation yet)
const int SQUARE_HEIGHT = 2;
const int SQUARE_WIDTH = 2;
const int PYRAMID_HEIGHT = 2;
const int PYRAMID_WIDTH = 3;
const int LEFT_SLANT_HEIGHT = 2;
const int LEFT_SLANT_WIDTH = 3;
const int RIGHT_SLANT_HEIGHT = 2;
const int RIGHT_SLANT_WIDTH = 3;
const int LONG_ROW_HEIGHT = 1;
const int LONG_ROW_WIDTH = 4;

// For events
SDL_Event event;

//The surfaces that will be used
SDL_Surface *screen = NULL;

// Functions declared below
void draw_grid(SDL_Surface *);
void draw_piece(SDL_Surface *, int, int, int);
void draw_square(SDL_Surface *, int, int);

int main( int argc, char* args[] )
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;    
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE|SDL_DOUBLEBUF);
    
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return 1;    
    }
    
    //Set the window caption
    SDL_WM_SetCaption( "Moving Square", NULL );

    bool quit = false;
    int start_x = 0; // Add randomization
    int start_y = 0;
    int piece_type = SQUARE;
    int piece_height = SQUARE_HEIGHT;
    int piece_width = SQUARE_WIDTH;
    while (quit == false) {

	    // NOTE: Add the timer stuff from lesson16
	    // Draw the square
	    draw_grid(screen);
	    draw_piece(screen, piece_type, start_x, start_y);

	    if (SDL_Flip(screen) == -1) {
		    printf("Problem with the SDL_Flip()");
		    return 1;
	    }

	    // Move the piece down one "line"
	    start_y += GRID_SIZE * piece_height;

	    // Check if piece is beyond the end line
	    if (start_y >= screen->h) {
		    start_y=0;
		    start_x += GRID_SIZE * piece_width;
	    }

	    // Check if piece is beyond the right edge
	    if (start_x >= screen->w) {
		    start_x=0;
	    }
    
	    while (SDL_PollEvent(&event)) {
		    if (event.type == SDL_QUIT) {
			    quit = true;
		    }
	    }
	    SDL_Delay(100);
    }

    SDL_Quit();
    
    return 0;    
}

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
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

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
 * Draws a grid on the surface
 * NOTE: Based on:
 *   file:///c:/SDL-1.2.13/docs/html/guidevideo.html#GUIDEVIDEOINTRO
 */
void draw_grid(SDL_Surface *surface) {
    Uint32 yellow;

    /* Map the color yellow to this display (R=0xff, G=0xFF, B=0x00)
     * Note: If the display is palettized, you must set the palette first.
     * NOTE: Softened the color.
     */
    yellow = SDL_MapRGB(surface->format, 0xcc, 0xcc, 0x00);

    // Fill the screen with "black" first
    SDL_FillRect(surface, NULL, SDL_MapRGB( surface->format, 0, 0, 0 ) );

    /* Lock the screen for direct access to the pixels */
    if ( SDL_MUSTLOCK(surface) ) {
        if ( SDL_LockSurface(surface) < 0 ) {
            fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
            return;
        }
    }

    for (int y = 0; y < surface->h; y+=1) {
        for (int x = 0; x < surface->w; x+= 1) {
	    if ((y+1)%GRID_SIZE==0) {
                putpixel(surface, x, y, yellow);
	    }
	    if ((x+1)%GRID_SIZE==0) {
                putpixel(surface, x, y, yellow);
	    }
        }
    }

    if (SDL_MUSTLOCK(surface)) {
        SDL_UnlockSurface(surface);
    }

    return;
}

/*
 * Draws a piece on the surface
 * NOTE: Based on:
 *   file:///c:/SDL-1.2.13/docs/html/guidevideo.html#GUIDEVIDEOINTRO
 */
void draw_piece(SDL_Surface *surface, int piece_type, int start_x, int start_y) {
    /* Lock the screen for direct access to the pixels */
    if ( SDL_MUSTLOCK(surface) ) {
        if ( SDL_LockSurface(surface) < 0 ) {
            fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
            return;
        }
    }

    switch(piece_type) {
	    case SQUARE:
		draw_square(surface, start_x, start_y);
		break;
	    case PYRAMID:
		break;
	    case LEFT_SLANT:
		break;
	    case RIGHT_SLANT:
		break;
	    case LONG_ROW:
		break;
    }

    if (SDL_MUSTLOCK(surface)) {
        SDL_UnlockSurface(surface);
    }

    return;
}

void draw_square(SDL_Surface *surface, int start_x, int start_y) {
    Uint32 blue;
    /* Map the color yellow to this display (R=0xff, G=0xFF, B=0x00)
     * Note:  If the display is palettized, you must set the palette first.
     */
    blue = SDL_MapRGB(surface->format, 0x00, 0x00, 0xff);

    // Draw a 4x4 "square" here
    for (int y = 0; y < GRID_SIZE * 2; y+=1) {
        for (int x = 0; x < GRID_SIZE * 2; x+= 1) {
                putpixel(surface, x+start_x, y+start_y, blue);
        }
    }
    return;
}

