#include "SDLRightSlant.h"
#include "RightSlant.h"

/*
 * RightSlant is the piece that looks like this
 *
 *   ####
 * ####
 *
 * This piece is also known as "inverted N", or "S".
 */
SDLRightSlant::SDLRightSlant(SDL_Surface *surface_in) : SDLShape()
{
  set_shape(new RightSlant());
  set_surface(surface_in);
  set_color(SDL_MapRGB(surface_in->format, 0x73, 0xFF, 0x31));
}
