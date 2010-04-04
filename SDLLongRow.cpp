#include "SDLLongRow.h"
#include "LongRow.h"

/*
 * This is the "long row", also known as "stick", "straight", or "I"
 */
SDLLongRow::SDLLongRow(SDL_Surface *surface_in) : SDLShape() 
{
  set_shape(new LongRow());
  set_surface(surface_in);
  set_color(SDL_MapRGB(surface_in->format, 0x31, 0xCE, 0xFF)); 
}
