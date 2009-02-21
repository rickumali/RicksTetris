#include "SDL/SDL.h"
#include "LeftEll.h"

class SDLLeftEll : public LeftEll {
  private:
    SDL_Surface *surface;
  public:
    SDLLeftEll(SDL_Surface *);
    void draw(int, int);
};
