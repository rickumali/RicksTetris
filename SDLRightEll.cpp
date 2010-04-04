#include "SDLRightEll.h"
#include "RightEll.h"

/*
 * RightEll is the piece that looks like this
 *
 *   ##
 *   ##
 * ####
 *
 * It's also known as "J", "left gun", "inverted L", or "Gamma"
 */
SDLRightEll::SDLRightEll(SDL_Surface *surface_in) : SDLShape()
{
  set_shape(new RightEll());
  set_surface(surface_in);
  set_color(SDL_MapRGB(surface_in->format, 0x00, 0x90, 0xFF)); 
}
