#include "SDLPyramid.h"
#include "Pyramid.h"

using namespace std;

SDLPyramid::SDLPyramid(SDL_Surface *surface_in) : SDLShape()
{
  set_shape(new Pyramid());
  set_surface(surface_in);
  set_color(SDL_MapRGB(surface_in->format, 0xB3, 0x33, 0xFF));
}
