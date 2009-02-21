#include "SDL/SDL.h"
#include <string>

//The attributes of the screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// Grid attributes
const int GRID_SIZE = 20;

// For events
SDL_Event event;

//The surfaces that will be used
SDL_Surface *screen = NULL;

// Functions declared below
void draw_grid(SDL_Surface *);
void draw_square(SDL_Surface *, int, int);

int main( int argc, char* args[] )
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;    
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return 1;    
    }
    
    //Set the window caption
    SDL_WM_SetCaption( "Grid", NULL );

    // Draw the grid
    draw_grid(screen);

    // Draw the square
    draw_square(screen, 0, 0);
    
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;    
    }

    bool quit = false;
    while (quit == false) {
	    while (SDL_PollEvent(&event)) {
		    if (event.type == SDL_QUIT) {
			    quit = true;
		    }
	    }
	    SDL_Delay(100);
    }

    //Quit SDL
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
    /* Code to set a yellow pixel at the center of the screen */

    Uint32 yellow;

    /* Map the color yellow to this display (R=0xff, G=0xFF, B=0x00)
     * Note: If the display is palettized, you must set the palette first.
     * NOTE: Softened the color.
     */
    yellow = SDL_MapRGB(surface->format, 0xcc, 0xcc, 0x00);

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

    /* Update "everything" */
    SDL_UpdateRect(surface, 0, 0, 0, 0);

    return;
}

/*
 * Draws a square on the surface
 * NOTE: Based on:
 *   file:///c:/SDL-1.2.13/docs/html/guidevideo.html#GUIDEVIDEOINTRO
 */
void draw_square(SDL_Surface *surface, int start_x, int start_y) {
    /* Code to set a yellow pixel at the center of the screen */

    Uint32 blue;

    /* Map the color yellow to this display (R=0xff, G=0xFF, B=0x00)
     * Note:  If the display is palettized, you must set the palette first.
     */
    blue = SDL_MapRGB(surface->format, 0x00, 0x00, 0xff);

    /* Lock the screen for direct access to the pixels */
    if ( SDL_MUSTLOCK(surface) ) {
        if ( SDL_LockSurface(surface) < 0 ) {
            fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
            return;
        }
    }

    // Draw square here
    for (int y = 0; y < GRID_SIZE; y+=1) {
        for (int x = 0; x < GRID_SIZE; x+= 1) {
                putpixel(surface, x+start_x, y+start_y, blue);
        }
    }

    if (SDL_MUSTLOCK(surface)) {
        SDL_UnlockSurface(surface);
    }

    /* Update "everything" */
    SDL_UpdateRect(surface, 0, 0, 0, 0);

    return;
}

