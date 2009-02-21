#include "SDL/SDL.h"
#include "Square.h"

class SDLSquare : public Square {
  private:
    SDL_Surface *surface;
  public:
    SDLSquare(SDL_Surface *);
    void draw(int, int);
};
