#include "SDL/SDL.h"
#include "Grid.h"
#include "SDLShape.h"

class SDLGrid {
  private:
    SDL_Surface *surface;
	Grid *grid;
	Uint32 shape_color;
  public:
    SDLGrid(SDL_Surface *);
    void place(int, int, SDLShape *);
    bool out_of_bounds(int, int, SDLShape *);
	void draw();
	void set_grid(Grid *);
	void set_surface(SDL_Surface *);
	void set_shape_color(Uint32);
};
