#include "Grid.h"
#include "Shape.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Constructor
Grid::Grid() {
  grid_height = 22;
  grid_width = 10;
  grid_data = string(22 * 10, '.');
}

// Constructor
Grid::Grid(int h, int w) {
  grid_height = h;
  grid_width = w;
  grid_data = string(h * w, '.');
}

// get_height()
int Grid::height() {
  return grid_height;
}

// get_width()
int Grid::width() {
  return grid_width;
}

// draw()
void Grid::draw() {
  for (int row = 0; row < grid_height; row++) {
    for (int col = 0; col < grid_width; col++) {
      cout << grid_data[(row * grid_width)+col];
    }
    cout << endl;
  }
}

// place(start_x, start_y, shape)
void Grid::place(int start_x, int start_y, Shape *shape) {
  for (int i = 0; i < grid_height * grid_width; i++) 
    grid_data[i] = '.';
  
  for (int row = 0; row < shape->get_height(); row++) {
    for (int col = 0; col < shape->get_width(); col++) {
      int ary_data = (start_x + col) + ((start_y + row) * grid_width);
      if ((ary_data >= 0) && (ary_data < grid_data.length()))
        grid_data[(start_x + col) + ((start_y + row) * grid_width)] = shape->shapedata(row, col);
    }
  }
}

// out_of_bounds(start_x, start_y, shape)
//
// TODO: Check if we should check out of bounds for "values" over the top
bool Grid::out_of_bounds(int start_x, int start_y, Shape *shape) {
  bool out_of_bounds = false;
  for (int row = 0; row < shape->get_height(); row++) {
    for (int col = 0; col < shape->get_width(); col++) {
	  int grid_x = start_x + col;
	  int grid_y = start_y + row;
	  if (shape->shapedata(row, col) == '#') {
		if ((grid_x < 0) || (grid_x >= grid_width) ||
			(grid_y >= grid_height)) {
			return true;
		} else {
		}
	  } else {
	  }
    }
  }
  return false;
}
