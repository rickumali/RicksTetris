#include "SDL/SDL.h"
#include "SDLGrid.h"
#include <iostream>
#include <string>

using namespace std;

//The attributes of the screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// For events
SDL_Event event;

//The surfaces that will be used
SDL_Surface *screen = NULL;

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

    SDLGrid *mygrid = new SDLGrid(screen);

	/* Redraw "everything" */
    if ( SDL_MUSTLOCK(screen) ) {
   		if ( SDL_LockSurface(screen) < 0 ) {
   		    cout << "Can't lock screen:" << SDL_GetError() << std::endl;
   		    return 1;
   		}
    }
    // Draw the grid
    mygrid->draw_grid();
    
	if (SDL_MUSTLOCK(screen)) {
		SDL_UnlockSurface(screen);
    }

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
