#include "SDL/SDL.h"
#include "Shape.h"

// The key design "insight" for this class is that SDLShapes are "implemented-in-terms-of-a" 
// Shape class! SDL shapes "are NOT shapes". SDL Shapes have SDL fields.

#ifndef GUARD_sdlshape_h
#define GUARD_sdlshape_h
class SDLShape {
    protected:
        Shape *shape;
        SDL_Surface *surface;
        Uint32 color;
    public:
	SDLShape();
    	void rotate_left();
    	void rotate_right();
    	int get_height();
    	int get_width();
    	char shapedata(int, int);
    	Shape *get_shape();
};
#endif
