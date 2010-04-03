#include "SDLSquare.h"
#include "Square.h"

/*
 * This piece is also known as "O", "package", "square", or "block".
 * 
 */
SDLSquare::SDLSquare(SDL_Surface *surface_in) : SDLShape() 
{
  shape = new Square();
  surface = surface_in;
  color = SDL_MapRGB(surface->format, 0xFF, 0xDE, 0x31);
}

