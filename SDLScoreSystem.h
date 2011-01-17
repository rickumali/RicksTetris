#include "SDL/SDL.h"
#include "SDL_ttf.h"
#include "ScoreSystem.h"

// Similar pattern followed as SDLShape.h and Shape.h.

#ifndef GUARD_sdlscoresystem_h
#define GUARD_sdlscoresystem_h
class SDLScoreSystem {
    private:
        ScoreSystem *scoresystem;
        SDL_Surface *surface;
        TTF_Font *font;
        Uint32 color;
    public:
	SDLScoreSystem(SDL_Surface *, TTF_Font *);
	void add_lines_to_score(int);
	int get_current_score();
	void set_current_score(int);
	void add_to_current_score(int);
	void write_score();
	void write_score_to_file();
	int get_level();
	void increment_level();
	void write_gameover();
	void write_level();
};
#endif
