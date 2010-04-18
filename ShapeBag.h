#include "SDLShape.h"

#ifndef GUARD_shapebag_h
#define GUARD_shapebag_h
class ShapeBag {
    private:
	int shape_counter;
	SDLShape *shapes[7];
        int shape_array[7];
	void fisherYatesShuffle(int []);
    public:
    	ShapeBag();
	SDLShape *nextshape();
	void addshape(SDLShape *);
};
#endif
