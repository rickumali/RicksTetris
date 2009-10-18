#include "SDL/SDL.h"
#include "Grid.h"

class SDLGrid : public Grid {
  private:
    SDL_Surface *surface;
  public:
    SDLGrid(SDL_Surface *);
    void draw_grid();
};
