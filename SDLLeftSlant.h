#include "SDL/SDL.h"
#include "LeftSlant.h"

class SDLLeftSlant : public LeftSlant {
  private:
    SDL_Surface *surface;
  public:
    SDLLeftSlant(SDL_Surface *);
    void draw(int, int);
};
