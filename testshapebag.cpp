#include <iostream>
#include <string>
#include <cstdio>
#include "SDL/SDL.h"
#include "SDLSquare.h"
#include "SDLPyramid.h"
#include "SDLLeftSlant.h"
#include "SDLRightSlant.h"
#include "SDLLongRow.h"
#include "SDLLeftEll.h"
#include "SDLRightEll.h"
#include "Constants.h"

#include "ShapeBag.h"

using std::cout;
using std::endl;
using std::string;

int main( int argc, char* args[] )
{
    SDL_Surface *screen = NULL;
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;    
    }
    screen = SDL_SetVideoMode( 640, 480, 32, SDL_HWSURFACE);
    SDLShape* square = new SDLSquare(screen);
    SDLShape* pyramid = new SDLPyramid(screen);
    SDLShape* leftslant = new SDLLeftSlant(screen);
    SDLShape* rightslant = new SDLRightSlant(screen);
    SDLShape* longrow = new SDLLongRow(screen);
    SDLShape* leftell = new SDLLeftEll(screen);
    SDLShape* rightell = new SDLRightEll(screen);
    ShapeBag sb;
    sb.addshape(square);
    sb.addshape(pyramid);
    sb.addshape(leftslant);
    sb.addshape(rightslant);
    sb.addshape(longrow);
    sb.addshape(leftell);
    sb.addshape(rightell);

    SDLShape *s;
    for (int i = 0; i < 7 * 3; i++) {
      s = sb.nextshape();
      cout << "Piece Type " << (i+1) << ": " << s->get_piece_type();
      cout << endl;
    }
    //Quit SDL
    SDL_Quit();
}
