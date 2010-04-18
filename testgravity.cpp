#include <iostream>
#include <string>
#include <cstdio>
#include "SDL/SDL.h"
#include "SDL_ttf.h"

#include "SDLGrid.h"
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
#include "OriginalNintendoScoring.h"

#include "ShapeBag.h"

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
    SDL_WM_SetCaption( "testgravity", NULL );

	// Create the Grid
	SDLGrid grid(screen);

    // Create a shape
    SDLShape* square = new SDLSquare(screen);
    SDLShape* pyramid = new SDLPyramid(screen);
    SDLShape* leftslant = new SDLLeftSlant(screen);
    SDLShape* rightslant = new SDLRightSlant(screen);
    SDLShape* longrow = new SDLLongRow(screen);
    SDLShape* leftell = new SDLLeftEll(screen);
    SDLShape* rightell = new SDLRightEll(screen);

    // Add shapes to the bag
    ShapeBag sb;
    sb.addshape(square);
    sb.addshape(pyramid);
    sb.addshape(leftslant);
    sb.addshape(rightslant);
    sb.addshape(longrow);
    sb.addshape(leftell);
    sb.addshape(rightell);

    SDLShape *selected_shape = sb.nextshape();

    // Starting location for ALL shapes
    // int x = rand() % 11; // Return an x value between 0 and 10
    int x = 5; // TODO: Modify this to account for shape!
    int y = -1 * selected_shape->get_height();

    int gravity = 1; // rows per second; can be fractional
    int old_gravity = -1; // stores the gravity when the player wants to fast drop the shape

    char status[50]; // Used for status line
    sprintf(status, "testgravity");

    // Scoring System
    ScoreSystem *scoring = new OriginalNintendoScoring();
    int score = 0;
    int level = 0; // Need 10 rows cleared to increase level (and gravity)
    int lines_cleared_in_level = 0;

    // Timer
    Timer fps;
    
    bool quit = false;
    bool pause = false;
    int num_rows_to_clear = 0;
    fps.start();
    while (quit == false) {
	    while (SDL_PollEvent(&event)) {
		    if (event.type == SDL_QUIT) {
			    quit = true;
		    }

		    if (event.type == SDL_KEYDOWN) {
			    switch(event.key.keysym.sym) {
				    case SDLK_0:
					    x = 5; 
					    y = -1 * selected_shape->get_height();
					    selected_shape = square;
					    sprintf(status, "Selected square!");
					    break;
				    case SDLK_1:
					    x = 5;
					    y = -1 * selected_shape->get_height();
					    selected_shape = pyramid;
					    sprintf(status, "Selected Pyramid!");
					    break;
				    case SDLK_2:
					    x = 5;
					    y = -1 * selected_shape->get_height();
					    selected_shape = leftslant;
					    sprintf(status, "Selected Left Slant!");
					    break;
				    case SDLK_3:
					    x = 5;
					    y = -1 * selected_shape->get_height();
					    selected_shape = rightslant;
					    sprintf(status, "Selected Right Slant!");
					    break;
				    case SDLK_4:
					    x = 5;
					    y = -1 * selected_shape->get_height();
					    selected_shape = longrow;
					    sprintf(status, "Selected Long Row!");
					    break;
				    case SDLK_5:
					    x = 5;
					    y = -1 * selected_shape->get_height();
					    selected_shape = leftell;
					    sprintf(status, "Selected Left Ell!");
					    break;
				    case SDLK_6:
					    x = 5;
					    y = -1 * selected_shape->get_height();
					    selected_shape = rightell;
					    sprintf(status, "Selected Right Ell!");
					    break;
				    case SDLK_UP:
					    selected_shape->rotate_right();
				        if (!grid.out_of_bounds(x,y,selected_shape)) {
						} else {
							selected_shape->rotate_left();
						}
					    break;
				    case SDLK_DOWN:
					    selected_shape->rotate_left();
				        if (!grid.out_of_bounds(x,y,selected_shape)) {
						} else {
							selected_shape->rotate_right();
						}
					    break;
				    case SDLK_LEFT:
				        if (!grid.off_the_side(x - 1,y,selected_shape)) {
				        	x--;
						}
					    break;
				    case SDLK_RIGHT:
				        if (!grid.off_the_side(x + 1,y,selected_shape)) {
				        	x++;
						}
					    break;
				    case SDLK_s:
					if (--gravity < 1) {
						gravity = 1;
					}
					sprintf(status, "Gravity: %d", gravity);
					break;
				    case SDLK_f:
					if (++gravity > 20) {
						gravity = 20;
					}
					sprintf(status, "Gravity: %d", gravity);
					break;
				    case SDLK_SPACE:
					old_gravity = gravity;
					gravity = 60;
					break;
				    case SDLK_p:
					    pause = !pause;
					    if (pause)
						    fps.pause();
					    else
						    fps.unpause();
					    break;
				    case SDLK_d:
					    grid.debug_draw();
					    break;
				    case SDLK_q:
					    quit = true;
					    break;
			    }
		    }
	    }

            if( fps.get_ticks() > (1000/gravity) )
            {
		if (num_rows_to_clear > 0) {
                  score = scoring->add_lines_to_score(level, num_rows_to_clear); 
		  cout << "SCORE: " << score << " LEVEL: " << level << endl;
		  lines_cleared_in_level += num_rows_to_clear;
		  num_rows_to_clear = 0;
		  if (lines_cleared_in_level > 10) {
		    level++; gravity++;
		    lines_cleared_in_level = 0;
		  }
		}

		if (!grid.at_bottom_or_on_mound(x,y+1,selected_shape)) {
			y++;
		} else {
			if (old_gravity != -1) {
				// This code resets the gravity after the user has done a fast drop.
				gravity = old_gravity;
				old_gravity = -1;
			}
			grid.add_to_mound(x,y,selected_shape);
			// TODO: Get new shape now
                        selected_shape = sb.nextshape();
                        x = 5; // TODO: Modify this to account for shape!
		        y = -1 * selected_shape->get_height();
			num_rows_to_clear = grid.get_num_rows_to_clear();
	        }
		fps.start(); // Restart the clock
	    }

	    /* Redraw "everything" */
	    if ( SDL_MUSTLOCK(screen) ) {
    		if ( SDL_LockSurface(screen) < 0 ) {
    		    cout << "Can't lock screen:" << SDL_GetError() << std::endl;
    		    return 1;
    		}
	    }

	    if (num_rows_to_clear > 0) {
	      grid.draw();
	      grid.animate_rows_to_clear(fps.get_ticks());
	    } else {
	      grid.clear_rows();
	      grid.place(x, y, selected_shape);
	      grid.draw();
	    }
	    // grid.draw();

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

