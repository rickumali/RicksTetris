#include "StatKeeper.h"

#ifndef GUARD_sdlstatkeeper_h
#define GUARD_sdlstatkeeper_h
class SDLStatKeeper {
    private:
	StatKeeper statkeeper;
        SDL_Surface *surface;
        TTF_Font *font;
        SDL_Rect shape_stat_loc[7];
    public:
    	SDLStatKeeper(SDL_Surface *, TTF_Font *);
	void clear_counters();
	void increment_shape_count(int);
	void write_stats();
};
#endif

