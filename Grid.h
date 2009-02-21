#ifndef GUARD_grid_h
#define GUARD_grid_h
#include <string>
using std::string;

class Grid {
    protected:
        string grid_data;
        int grid_height;
        int grid_width;
    public:
    	Grid();
    	void draw(int, int);
    	int height();
    	int width();
};
#endif
