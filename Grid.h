#ifndef GUARD_grid_h
#define GUARD_grid_h
#include "Shape.h"
#include <string>
using std::string;

class Grid {
    protected:
        string grid_data;
        int grid_height;
        int grid_width;
    public:
    	Grid();
    	void draw();
    	void draw(int, int, Shape *);
    	int height();
    	int width();
};
#endif
