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
    	Grid(int, int);
    	void draw();
    	void place(int, int, Shape *);
    	bool out_of_bounds(int, int, Shape *);
    	int height();
    	int width();
};
#endif
