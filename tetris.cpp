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
#include "SDLScoreSystem.h"
#include "putpixel.h"
#include "Constants.h"
#include "Timer.h"
#include "SDLStatKeeper.h"
#include "ShapeBag.h"

#include "windows.h"

using std::cout;
using std::endl;
using std::string;

// For events
SDL_Event event;

// The surfaces that will be used
SDL_Surface *screen = NULL;

// The surfaces for the "background" image
SDL_Surface *tetris_bmp;
SDL_Surface *start_bmp;
SDL_Surface *help_bmp;

//The frames per second
const int FRAMES_PER_SECOND = 20;

// Font
TTF_Font *font;

int main( int argc, char* args[] )
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        cout << "Can't initialize SDL library: " << SDL_GetError() << std::endl;
	MessageBox(0,"Can't initialize SDL graphics library. See README.txt.","Rick's Tetris: Can't Initialize SDL",MB_OK); 
	return 1;
    }
    
    if (TTF_Init()==-1) {
	return 1;
    }

    int font_counter = 0;
    bool found_font = false;
    const char* font_paths[] = { "c:\\WINDOWS\\Fonts\\VeraBd.ttf", "c:\\MinGW\\ttf-bitstream-vera-1.10\\VeraBd.ttf", "VeraBd.ttf" };
    while (!found_font) {
      font=TTF_OpenFont(font_paths[font_counter], 16);
      if (font) {
          found_font = true;
      }
      font_counter++;
    }
    if (!found_font) {
	MessageBox(0,"Can't find VeraBd.ttf font file. See README.txt.","Rick's Tetris: Can't Find Font",MB_OK); 
	return 1;
    }

    //Set the window caption and icon
    SDL_WM_SetCaption( "Tetris by Rick Umali", "Tetris" );
    SDL_WM_SetIcon( SDL_LoadBMP("rtet.bmp"), NULL);
    
    // Set up the screen
    // NOTE: We use HWSURFACE to take advantage of double-buffer
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE);
    
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        cout << "Can't set up SDL screen: " << SDL_GetError() << std::endl;
	MessageBox(0,"Can't set up SDL screen. See README.txt.","Rick's Tetris: Can't Set Screen",MB_OK); 
	return 1;
    }
    
    // Main "background" bitmap
    tetris_bmp = SDL_LoadBMP("tetris.bmp");
    if(tetris_bmp == NULL) {
       MessageBox(0,"Can't load tetris.bmp. See README.txt.","Rick's Tetris: Can't Load Bitmap",MB_OK); 
       return 1;
    }
    // Start "splash" "background" bitmap
    start_bmp = SDL_LoadBMP("start.bmp");
    if(start_bmp == NULL) {
       MessageBox(0,"Can't load start.bmp. See README.txt.","Rick's Tetris: Can't Load Bitmap",MB_OK); 
       return 1;
    }
    // Help "background" bitmap
    help_bmp = SDL_LoadBMP("help.bmp");
    if(help_bmp == NULL) {
       MessageBox(0,"Can't load help.bmp. See README.txt.","Rick's Tetris: Can't Load Bitmap",MB_OK); 
       return 1;
    }

    // BLIT the start "splash" "background" bitmap
    SDL_BlitSurface(start_bmp , NULL, screen , NULL);
    SDL_UpdateRect(screen , 0 , 0 , 0 , 0 );

    // Create the Grid
    SDLGrid grid(screen);

    // Create shapes
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

    SDLShape *selected_shape;

    int x, y; // Location of the shape on the grid
    int gravity; // rows per second; TODO: Make it so it can be fractional
    int old_gravity = -1; // stores the gravity when the player wants to fast drop the shape

    // Scoring System
    SDLScoreSystem *scoring = new SDLScoreSystem(screen, font);
    int lines_cleared_in_level;

    // Timer
    Timer fps;
    
    // StatKeeper
    SDLStatKeeper statkeeper(screen, font);

    bool game_loop = true; // overall game loop
    bool help; // User asked for 'help' Screen?
    bool user_quit; // User initiated the quit
    bool game_quit; // Game initiated the quit (shapes all fall to the TOP)
    bool pause; // User asked to 'pause'
    int num_rows_to_clear;

    // The code block implements the start splash "screen"
    bool start = false;
    while (start == false) {
      while (SDL_PollEvent(&event)) {
  	if (event.type != SDL_KEYDOWN) {
  	  continue;
  	}
  
  	if (!start && event.key.keysym.sym == SDLK_q) {
          return 1; // Allow exit from splash screen
	} else if (!start && event.key.keysym.sym != SDLK_s) {
  	  continue;
  	} else {
  	  start = true;
  	}
      }
      // See http://www.gamedev.net/community/forums/topic.asp?topic_id=360184
      SDL_Delay(1); 
    }

    while (game_loop) {
	    gravity = 1; old_gravity = -1;
	    game_quit = false; user_quit = false; start = true;
	    lines_cleared_in_level = 0;
	    pause = false; help = false;
	    num_rows_to_clear = 0;
	    fps.start();
	    grid.reset();
	    statkeeper.clear_counters();
	
	    selected_shape = sb.nextshape(); // TODO: Reset the 7 shapes in the bag properly
	    // Starting location for ALL shapes
	    // int x = rand() % 11; // TODO: Return an x value between 0 and 10, that accounts for shape!
	    x = 5; // XXX: Hardcoded for now
	    y = -1 * selected_shape->get_height();
	
	    // Track Shapes with StatKeeper
	    statkeeper.increment_shape_count(selected_shape->get_piece_type());
	
	    scoring->set_current_score(0);
	
	    // Now BLIT the normal "background" bitmap
	    SDL_BlitSurface(tetris_bmp , NULL, screen , NULL);
	
	    while (!user_quit && !game_quit) {
		    while (SDL_PollEvent(&event)) {
			    if (event.type == SDL_QUIT) {
				    user_quit = true;
			    }
	
			    if (event.type == SDL_KEYDOWN) {
				        // This block of code implements "pause" (p turns pause on or off)
					if (pause && event.key.keysym.sym != SDLK_p)
					  continue;
				        // This block of code implements "help" (h turns help on or off)
					if (help && event.key.keysym.sym != SDLK_h)
					  continue;
	
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
					    case SDLK_h:
						    help = !help;
						    if (help) {
							fps.pause();
	    						// BLIT the "help" bitmap (it's slightly 
							// offset, to cover the lower-thirds game shapes)
							SDL_Rect dest;
	  						dest.x = 250;
	  						dest.y = 223;
	    						SDL_BlitSurface(help_bmp , NULL, screen , &dest);
						    } else {
	    						// BLIT the normal "background" bitmap
	    						SDL_BlitSurface(tetris_bmp , NULL, screen , NULL);
							fps.unpause();
						    }
						    break;
					    case SDLK_d:
						    grid.debug_draw();
						    break;
					    case SDLK_q:
						    game_loop = false;
						    user_quit = true;
						    break;
				    }
			    }
		    }
	
	            if( fps.get_ticks() > (1000/gravity) )
	            {
			if (num_rows_to_clear > 0) {
	                  (void) scoring->add_lines_to_score(num_rows_to_clear); 
			  lines_cleared_in_level += num_rows_to_clear;
			  num_rows_to_clear = 0;
			  if (lines_cleared_in_level > 10) {
				scoring->increment_level();
			    gravity++;
			    lines_cleared_in_level = 0;
			    if (gravity > 10) {
	                      gravity = 10; // Cap gravity at 10
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
				if (y <= 0) {
				  game_quit = true;
				} else {
	                          selected_shape = sb.nextshape();
	                          x = 5; // TODO: Modify this to account for shape!
			          y = -1 * selected_shape->get_height();
				  num_rows_to_clear = grid.get_num_rows_to_clear();
				  statkeeper.increment_shape_count(selected_shape->get_piece_type());
				}
		        }
			fps.start(); // Restart the clock
		    }
	
		    scoring->write_score();
		    if (!help) {
		      statkeeper.write_stats();
		    }
		    scoring->write_level();
	
		    /* Redraw "everything" */
		    if ( SDL_MUSTLOCK(screen) ) {
	    		if ( SDL_LockSurface(screen) < 0 ) {
	    		    cout << "Can't lock screen: " << SDL_GetError() << std::endl;
                            MessageBox(0,"Can't lock screen. See README.txt.","Rick's Tetris: Can't Lock Screen",MB_OK); 
	    		    return 1;
	    		}
		    }
	
		    if (num_rows_to_clear > 0) {
		      grid.draw(pause||help);
		      grid.animate_rows_to_clear(fps.get_ticks());
		    } else {
		      grid.clear_rows();
		      grid.place(x, y, selected_shape);
		      grid.draw(pause||help);
		    }
	
		    if (SDL_MUSTLOCK(screen)) {
			SDL_UnlockSurface(screen);
		    }
	
		    if (SDL_Flip(screen) == -1) {
	    		    cout << "Can't flip screen: " << SDL_GetError() << std::endl;
                            MessageBox(0,"Can't flip screen. See README.txt.","Rick's Tetris: Can't Flip Screen",MB_OK); 
			    return 1;
		    }
	
		    // See http://www.gamedev.net/community/forums/topic.asp?topic_id=360184
	            SDL_Delay(1); 
	    }
	
	    scoring->write_score_to_file();
	    // Check if the game quit. If the game quit (because the pieces reach
	    // the top of the grid), then allow the user to start a new game. If the
	    // user quit, then just bail.
	    if (game_quit) {
	      user_quit = false; 
	      scoring->write_gameover();
	      SDL_UpdateRect(screen , 0 , 0 , 0 , 0 );
	      while (user_quit == false) {
		 while (SDL_PollEvent(&event)) {
	  	   if (event.type != SDL_KEYDOWN) {
	  	     continue;
	  	   }
	
		   if (event.key.keysym.sym == SDLK_q) {
		     user_quit = true;
		     game_loop = false;
		   }
	  
	  	   if (event.key.keysym.sym == SDLK_n) {
		     user_quit = true; // XXX: This works, but REFACTOR!
	  	   }
		}
		// See http://www.gamedev.net/community/forums/topic.asp?topic_id=360184
	        SDL_Delay(1); 
	      }
	    }
    }
    TTF_CloseFont(font);
    TTF_Quit();

    // Free images
    SDL_FreeSurface(screen);
    SDL_FreeSurface(tetris_bmp);
    SDL_FreeSurface(help_bmp);

    //Quit SDL
    SDL_Quit();
    
    return 0;    
}

