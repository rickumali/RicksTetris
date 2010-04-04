#include <iostream>
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

using std::cout;

// For events
SDL_Event event;

// The surfaces that will be used
SDL_Surface *screen = NULL;

// Font
TTF_Font *font;

void write_instruction_line(SDL_Surface *);
void write_status_line(SDL_Surface *, char *);

int main( int argc, char* args[] )
{
    cout << "testsdlshape.exe" << std::endl;

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
    SDL_WM_SetCaption( "testsdlshape", NULL );

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
    
    int piece_x[] = { 1, 3, 5, 7, 2, 4, 2 }; 
    int piece_y[] = { 1, 3, 5, 7, 9, 9, 11 }; 

    bool quit = false;
    SDLShape *selected_shape = square;
    while (quit == false) {
	    while (SDL_PollEvent(&event)) {
		    if (event.type == SDL_QUIT) {
			    quit = true;
		    }

		    if (event.type == SDL_KEYDOWN) {
			    switch(event.key.keysym.sym) {
				    case SDLK_0:
					    selected_shape = square;
					    write_status_line(screen, "Selected Square!");
					    break;
				    case SDLK_1:
					    selected_shape = pyramid;
					    write_status_line(screen, "Selected Pyramid!");
					    break;
				    case SDLK_2:
					    selected_shape = leftslant;
					    write_status_line(screen, "Selected Left Slant!");
					    break;
				    case SDLK_3:
					    selected_shape = rightslant;
					    write_status_line(screen, "Selected Right Slant!");
					    break;
				    case SDLK_4:
					    selected_shape = longrow;
					    write_status_line(screen, "Selected Long Row!");
					    break;
				    case SDLK_5:
					    selected_shape = leftell;
					    write_status_line(screen, "Selected Left Ell!");
					    break;
				    case SDLK_6:
					    selected_shape = rightell;
					    write_status_line(screen, "Selected Right Ell!");
					    break;
				    case SDLK_UP:
					    selected_shape->rotate_right();
				        if (!grid.out_of_bounds(piece_x[selected_shape->get_piece_type() -1],piece_y[selected_shape->get_piece_type()-1],selected_shape)) {
				        	write_status_line(screen, "Rotate right.");
						} else {
							selected_shape->rotate_left();
						}
					    break;
				    case SDLK_DOWN:
					    selected_shape->rotate_left();
				        if (!grid.out_of_bounds(piece_x[selected_shape->get_piece_type() -1],piece_y[selected_shape->get_piece_type()-1],selected_shape)) {
				        	write_status_line(screen, "Rotate left.");
						} else {
							selected_shape->rotate_right();
						}
					    break;
				    case SDLK_LEFT:
				        if (!grid.out_of_bounds(piece_x[selected_shape->get_piece_type() -1] - 1,piece_y[selected_shape->get_piece_type()-1],selected_shape)) {
				        	piece_x[selected_shape->get_piece_type() - 1] -= 1;
				        	write_status_line(screen, "Move left.");
						}
					    break;
				    case SDLK_RIGHT:
				        if (!grid.out_of_bounds(piece_x[selected_shape->get_piece_type() -1] + 1,piece_y[selected_shape->get_piece_type()-1],selected_shape)) {
				        	piece_x[selected_shape->get_piece_type() - 1] += 1;
							write_status_line(screen, "Move right.");
						}
					    break;
				    case SDLK_q:
					    quit = true;
					    break;
			    }
		    }
	    }

	    /* Redraw "everything" */
	    if ( SDL_MUSTLOCK(screen) ) {
    		if ( SDL_LockSurface(screen) < 0 ) {
    		    cout << "Can't lock screen:" << SDL_GetError() << std::endl;
    		    return 1;
    		}
	    }

	    // write_instruction_line(screen);
	    grid.place(
			piece_x[selected_shape->get_piece_type()-1],
			piece_y[selected_shape->get_piece_type()-1], 
			selected_shape);
		grid.draw();
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
 * Writes a line of status to the status line. This first 
 * blanks out the status line, THEN it draws the message into the 
 * blaked out status line.
 */
void write_instruction_line(SDL_Surface *screen) {
    Uint32 blackColor = SDL_MapRGB(screen->format, 0, 0, 0);
    SDL_Color textColor = {0, 255, 0};
    SDL_Surface *message = TTF_RenderText_Solid( font, "Key 0, Shape 0; 1, T; 2, LS; 3, RS; 4, I; 5, LG; 6; RG", textColor);

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
