#include "SDL/SDL.h"
#include "LongRow.h"

class SDLLongRow : public LongRow {
  private:
    SDL_Surface *surface;
  public:
    SDLLongRow(SDL_Surface *);
    void draw(int, int);
};
