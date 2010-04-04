#include "SDLLeftSlant.h"
#include "LeftSlant.h"

/*
 * LeftSlant is the piece that looks like this
 *
 * ####
 *   ####
 *
 * This piece is also known as "Z", "N", "skew", or "Snake".
 * 
 */
SDLLeftSlant::SDLLeftSlant(SDL_Surface *surface_in) : SDLShape()
{
  set_shape(new LeftSlant());
  set_surface(surface_in);
  set_color(SDL_MapRGB(surface_in->format, 0xFF, 0x31, 0x7B));
}
