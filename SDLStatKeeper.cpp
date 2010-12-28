#include "SDL/SDL.h"
#include "SDL_ttf.h"
#include "SDLStatKeeper.h"
#include "Constants.h"

SDLStatKeeper::SDLStatKeeper(SDL_Surface *surface_in, TTF_Font *font_in) {
  shape_stat_loc[0].x = 270; shape_stat_loc[0].y = 250; // SQUARE 
  shape_stat_loc[0].h = 21; shape_stat_loc[0].w = 51; // SQUARE 
  shape_stat_loc[1].x = 276; shape_stat_loc[1].y = 372; // PYRAMID
  shape_stat_loc[1].h = 21; shape_stat_loc[1].w = 51; // PYRAMID
  shape_stat_loc[2].x = 479; shape_stat_loc[2].y = 250; // LEFT_SLANT
  shape_stat_loc[2].h = 21; shape_stat_loc[2].w = 51; // LEFT_SLANT
  shape_stat_loc[3].x = 374; shape_stat_loc[3].y = 250; // RIGHT_SLANT
  shape_stat_loc[3].h = 21; shape_stat_loc[3].w = 51; // RIGHT_SLANT
  shape_stat_loc[4].x = 563; shape_stat_loc[4].y = 290; // LONG_ROW
  shape_stat_loc[4].h = 21; shape_stat_loc[4].w = 51; // LONG_ROW
  shape_stat_loc[5].x = 376; shape_stat_loc[5].y = 372; // LEFT_ELL
  shape_stat_loc[5].h = 21; shape_stat_loc[5].w = 51; // LEFT_ELL
  shape_stat_loc[6].x = 481; shape_stat_loc[6].y = 372; // RIGHT_ELL
  shape_stat_loc[6].h = 21; shape_stat_loc[6].w = 51; // RIGHT_ELL
  surface = surface_in;
  font = font_in;
}

void SDLStatKeeper::clear_counters() {
  statkeeper.clear_counters();
}
void SDLStatKeeper::increment_shape_count(int shape_id) {
  statkeeper.increment_shape_count(shape_id);
}

void SDLStatKeeper::write_stats() {
    const int HEIGHT = 21;
    const int WIDTH = 51;
    Uint32 blackColor = SDL_MapRGB(surface->format, 0, 0, 0);
    SDL_Color textColor = {0, 255, 0};
    char s[5];

    for (int shape_id = 0; shape_id < 7; shape_id++) {
      sprintf(s, "%4d", statkeeper.get_shape_count(shape_id+1));
      SDL_Surface *message = TTF_RenderText_Solid( font, s, textColor);
  
      SDL_FillRect (surface, &shape_stat_loc[shape_id], blackColor);
      SDL_BlitSurface (message, NULL, surface, &shape_stat_loc[shape_id]);
      SDL_FreeSurface(message);
    }
}
