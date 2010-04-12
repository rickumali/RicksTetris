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
    void add_to_mound(int, int, SDLShape *);
    bool out_of_bounds(int, int, SDLShape *);
    bool at_bottom_or_on_mound(int, int, SDLShape *);
    bool off_the_side(int, int, SDLShape *);
	void draw();
	void animate_rows_to_clear();
	bool any_rows_to_clear();
	void clear_rows();
	void debug_draw();
	void set_grid(Grid *);
	void set_surface(SDL_Surface *);
	void set_shape_color(Uint32);
};
