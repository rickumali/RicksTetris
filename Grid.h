#ifndef GUARD_grid_h
#define GUARD_grid_h
#include "Shape.h"
#include <string>
using std::string;

class Grid {
    private:
        string grid_data;
        int grid_height;
        int grid_width;
        void remove_shape_from_grid();
    public:
    	Grid();
    	Grid(int, int);
    	void draw();
    	void clear_rows();
    	bool clear_this_row(int);
    	void place(int, int, Shape *);
    	void add_to_mound(int, int, Shape *);
    	bool any_rows_to_clear();
    	int get_num_rows_to_clear();
    	bool out_of_bounds(int, int, Shape *);
    	bool at_bottom_or_on_mound(int, int, Shape *);
    	bool off_the_side(int, int, Shape *);
    	int height();
    	int width();
		char griddata(int, int);
	void reset();
};
#endif
