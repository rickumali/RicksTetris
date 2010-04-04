#include "SDLLeftEll.h"
#include "LeftEll.h"

/*
 * LeftEll is the piece that looks like this
 *
 * ##
 * ##
 * ####
 *
 * It's also known as "L", "gun", or "right gun".
 */
SDLLeftEll::SDLLeftEll(SDL_Surface *surface_in) : SDLShape()
{
  set_shape(new LeftEll());
  set_surface(surface_in);
  set_color(SDL_MapRGB(surface_in->format, 0xFF, 0x8C, 0x31));
}
