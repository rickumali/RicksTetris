#include "SDL/SDL.h"
#include "ScoreSystem.h"

// Similar pattern followed as SDLShape.h and Shape.h.

#ifndef GUARD_sdlscoresystem_h
#define GUARD_sdlscoresystem_h
class SDLScoreSystem {
    private:
        ScoreSystem *scoresystem;
        SDL_Surface *surface;
        Uint32 color;
    public:
	SDLScoreSystem(SDL_Surface *);
	void add_lines_to_score(int, int);
	int get_current_score();
	void set_current_score(int);
	void add_to_current_score(int);
	void write_score();
};
#endif
