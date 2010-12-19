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

void write_score(SDL_Surface *, int);
void write_level(SDL_Surface *, int);

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

    // Scoring System
    ScoreSystem *scoring = new OriginalNintendoScoring();
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
					break;
				    case SDLK_f:
					if (++gravity > 20) {
						gravity = 20;
					}
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
                  (void) scoring->add_lines_to_score(level, num_rows_to_clear); 
		  lines_cleared_in_level += num_rows_to_clear;
		  num_rows_to_clear = 0;
		  if (lines_cleared_in_level > 10) {
		    level++; gravity++;
		    lines_cleared_in_level = 0;
		    if (level > 999999) {
                      level = 1000000; // Cap level at 1M
		    }
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

	    write_score(screen, scoring->get_current_score());
	    write_level(screen, level+1);

	    /* Redraw "everything" */
	    if ( SDL_MUSTLOCK(screen) ) {
    		if ( SDL_LockSurface(screen) < 0 ) {
    		    cout << "Can't lock screen:" << SDL_GetError() << std::endl;
    		    return 1;
    		}
	    }

	    if (num_rows_to_clear > 0) {
	      grid.draw(pause);
	      grid.animate_rows_to_clear(fps.get_ticks());
	    } else {
	      grid.clear_rows();
	      grid.place(x, y, selected_shape);
	      grid.draw(pause);
	    }

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
 * Writes the score to the scoring area.
 * It blanks out the score line, THEN it draws 
 * the message into the blacked out area.
 */
void write_score(SDL_Surface *screen, int score) {
    const int X_OFFSET = 17;
    const int Y_OFFSET = 5;
    Uint32 blackColor = SDL_MapRGB(screen->format, 0, 0, 0);
    SDL_Color textColor = {0, 255, 0};
    char s[20];

    sprintf(s, "Score: %10d", score);
    SDL_Surface *message = TTF_RenderText_Solid( font, s, textColor);

    // This is the entire blank area of the scoring line
    SDL_Rect status_line_offset;
    status_line_offset.x = X_OFFSET * GRID_SIZE;
    status_line_offset.y = Y_OFFSET * GRID_SIZE;
    status_line_offset.h = 1 * GRID_SIZE - 1;
    status_line_offset.w = 30 * GRID_SIZE - 1;

    // This is the area for the message
    SDL_Rect text_offset;
    text_offset.x = X_OFFSET * GRID_SIZE;
    text_offset.y = Y_OFFSET * GRID_SIZE;

    SDL_FillRect (screen, &status_line_offset, blackColor);
    SDL_BlitSurface (message, NULL, screen, &text_offset);
    SDL_FreeSurface(message);
}

/*
 * Writes the level to the level display area.
 * It blanks out the line, THEN it draws 
 * the message into the blacked out area.
 */
void write_level(SDL_Surface *screen, int level) {
    const int X_OFFSET = 17;
    const int Y_OFFSET = 6;
    Uint32 blackColor = SDL_MapRGB(screen->format, 0, 0, 0);
    SDL_Color textColor = {0, 255, 0};
    char s[20];

    if (level > 999999)
      sprintf(s, "Level: Past million!");
    else 
      sprintf(s, "Level: %11d", level);
    SDL_Surface *message = TTF_RenderText_Solid( font, s, textColor);

    // This is the entire blank area of the level line
    SDL_Rect status_line_offset;
    status_line_offset.x = X_OFFSET * GRID_SIZE;
    status_line_offset.y = Y_OFFSET * GRID_SIZE;
    status_line_offset.h = 1 * GRID_SIZE - 1;
    status_line_offset.w = 30 * GRID_SIZE - 1;

    // This is the area for the message
    SDL_Rect text_offset;
    text_offset.x = X_OFFSET * GRID_SIZE;
    text_offset.y = Y_OFFSET * GRID_SIZE;

    SDL_FillRect (screen, &status_line_offset, blackColor);
    SDL_BlitSurface (message, NULL, screen, &text_offset);
    SDL_FreeSurface(message);
}



