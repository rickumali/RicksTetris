#include "SDL/SDL.h"
#include "RightEll.h"

class SDLRightEll : public RightEll {
  private:
    SDL_Surface *surface;
  public:
    SDLRightEll(SDL_Surface *);
    void draw(int, int);
};
