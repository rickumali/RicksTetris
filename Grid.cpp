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
  cout << "GRID  GRID" << endl;
  for (int row = 0; row < grid_height; row++) {
    for (int col = 0; col < grid_width; col++) {
      cout << grid_data[(row * grid_width)+col];
    }
    cout << endl;
  }
  cout << "GRID  GRID" << endl;
}

// The grid contains these characters: ' ' or '.' for "blank" (the 
// ' ' is introduced by a shape's blank space in its square), '#' for 
// a "shape" block, and 'm' for a "mound" block. Clearing the grid of 
// a shape is to remove everything that is NOT an 'm' (a mound).
void Grid::remove_shape_from_grid() {
  for (int i = 0; i < grid_height * grid_width; i++) {
    if (grid_data[i] != 'm')
	  grid_data[i] = '.';
  }
}

// place(start_x, start_y, shape)
void Grid::place(int start_x, int start_y, Shape *shape) {
  remove_shape_from_grid();
  
  for (int row = 0; row < shape->height(); row++) {
    for (int col = 0; col < shape->width(); col++) {
      int ary_data = (start_x + col) + ((start_y + row) * grid_width);
      if ((ary_data >= 0) && (ary_data < grid_data.length()) && (shape->shapedata(row,col) == '#'))
        grid_data[(start_x + col) + ((start_y + row) * grid_width)] = shape->shapedata(row, col);
    }
  }
}

// place(start_x, start_y, shape)
void Grid::add_to_mound(int start_x, int start_y, Shape *shape) {
  remove_shape_from_grid();
  for (int row = 0; row < shape->height(); row++) {
    for (int col = 0; col < shape->width(); col++) {
      int ary_data = (start_x + col) + ((start_y + row) * grid_width);
      if ((ary_data >= 0) && (ary_data < grid_data.length()) && (shape->shapedata(row,col) == '#'))
        grid_data[(start_x + col) + ((start_y + row) * grid_width)] = 'm';
    }
  }
}

// out_of_bounds(start_x, start_y, shape)
//
// TODO: Check if we should check out of bounds for "values" over the top
bool Grid::out_of_bounds(int start_x, int start_y, Shape *shape) {
  for (int row = 0; row < shape->height(); row++) {
    for (int col = 0; col < shape->width(); col++) {
	  int grid_x = start_x + col;
	  int grid_y = start_y + row;
	  if (shape->shapedata(row, col) == '#') {
		if ((grid_x < 0) || (grid_x >= grid_width) ||
			(grid_y >= grid_height)) {
			return true;
		}
	  }
    }
  }
  return false;
}

// off_the_side(start_x, start_y, shape)
// NOTE: also checks if we hit 'the mound'
bool Grid::off_the_side(int start_x, int start_y, Shape *shape) {
  for (int row = 0; row < shape->height(); row++) {
    for (int col = 0; col < shape->width(); col++) {
	  int grid_x = start_x + col;
	  int grid_y = start_y + row;
	  if (shape->shapedata(row, col) == '#') {
		// Account for being off the side
		if ((grid_x < 0) || (grid_x >= grid_width))
		  return true;
		// Account for hitting the 'mound'
        if (grid_data[(start_x + col) + ((start_y + row) * grid_width)] == 'm')
		  return true;
	  }
    }
  }
  return false;
}

char Grid::griddata(int row, int col) {
      return (grid_data[(row*grid_width)+col]);
}

// off_the_side(start_x, start_y, shape)
bool Grid::at_bottom_or_on_mound(int start_x, int start_y, Shape *shape) {
  for (int row = 0; row < shape->height(); row++) {
    for (int col = 0; col < shape->width(); col++) {
	  int grid_x = start_x + col;
	  int grid_y = start_y + row;
	  if (shape->shapedata(row, col) == '#') {
        if (grid_data[(start_x + col) + ((start_y + row) * grid_width)] == 'm')
		  return true;
	    if (grid_y >= grid_height) {
	      return true;
	    }
	  }
    }
  }
  return false;
}
