#include "SDL/SDL.h"
#include "RightSlant.h"

class SDLRightSlant : public RightSlant {
  private:
    SDL_Surface *surface;
  public:
    SDLRightSlant(SDL_Surface *);
    void draw(int, int);
};
