#include "SDLSquare.h"
#include "Square.h"

/*
 * This piece is also known as "O", "package", "square", or "block".
 * 
 */
SDLSquare::SDLSquare(SDL_Surface *surface_in) : SDLShape() 
{
  set_shape(new Square());
  set_surface(surface_in);
  set_color(SDL_MapRGB(surface_in->format, 0xFF, 0xDE, 0x31));
}
