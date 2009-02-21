#include "SDL/SDL.h"
#include "Pyramid.h"

class SDLPyramid : public Pyramid {
  private:
    SDL_Surface *surface;
  public:
    SDLPyramid(SDL_Surface *);
    void draw(int, int);
};
