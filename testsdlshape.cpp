#include <iostream>
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

using std::cout;

// For events
SDL_Event event;

// The surfaces that will be used
SDL_Surface *screen = NULL;

// Font
TTF_Font *font;

void write_instruction_line(SDL_Surface *);
void write_status_line(SDL_Surface *, char *);
void draw_grid(SDL_Surface *);

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

    // Create a shape
    Shape* square = new SDLSquare(screen);
    Shape* pyramid = new SDLPyramid(screen);
    Shape* leftslant = new SDLLeftSlant(screen);
    Shape* rightslant = new SDLRightSlant(screen);
    Shape* longrow = new SDLLongRow(screen);
    Shape* leftell = new SDLLeftEll(screen);
    Shape* rightell = new SDLRightEll(screen);
    
    int piece_x[] = { 1, 20, 13,  6, 14, 24, 18 }; 
    int piece_y[] = { 1,  4,  3, 18, 10, 15, 15 }; 
    
    bool quit = false;
    Shape *selected_shape = square;
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
					    write_status_line(screen, "Rotate right.");
					    break;
				    case SDLK_DOWN:
					    selected_shape->rotate_left();
					    write_status_line(screen, "Rotate left.");
					    break;
				    case SDLK_LEFT:
				        piece_x[selected_shape->get_piece_type() - 1] -= 1;
				        write_status_line(screen, "Move left.");
					    break;
				    case SDLK_RIGHT:
				        piece_x[selected_shape->get_piece_type() - 1] += 1;
				        write_status_line(screen, "Move right.");
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
	    draw_grid(screen);
	    write_instruction_line(screen);
	    square->draw(piece_x[0],piece_y[0]);
	    pyramid->draw(piece_x[1],piece_y[1]);
	    leftslant->draw(piece_x[2],piece_y[2]);
	    rightslant->draw(piece_x[3],piece_y[3]);
	    longrow->draw(piece_x[4],piece_y[4]);
	    leftell->draw(piece_x[5],piece_y[5]);
	    rightell->draw(piece_x[6],piece_y[6]);
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
    all_but_status_line_offset.h = surface->h - GRID_SIZE;
    all_but_status_line_offset.w = surface->w;
    SDL_FillRect (surface, &all_but_status_line_offset, blackColor);

    // The h - GRID_SIZE leaves the last two "rows" blank for an instructions line, and a status line
    for (int y = 0; y < (surface->h - GRID_SIZE * 2); y+=1) {
        for (int x = 0; x < surface->w; x+= 1) {
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
