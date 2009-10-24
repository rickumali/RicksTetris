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

// draw(start_x, start_y, shape)
void Grid::draw(int start_x, int start_y, Shape *shape) {
  for (int i = 0; i < grid_height * grid_width; i++) 
    grid_data[i] = '.';
  
  for (int row = 0; row < shape->get_height(); row++) {
    for (int col = 0; col < shape->get_width(); col++) {
      grid_data[(start_x + col) + ((start_y + row) * grid_width)] = shape->shapedata(row, col);
    }
  }
}

// out_of_bounds(start_x, start_y, shape)
bool Grid::out_of_bounds(int start_x, int start_y, Shape *shape) {
  // We're off the right edge. 
  if ((start_x + shape->get_width()) > grid_width) {
    int overhang = start_x + shape->get_width() - grid_width;
    // Check that the shape doesn't have an empty data column
    for (int row = 0; row < shape->get_height(); row++) {
      for (int col = shape->get_width() - overhang; col < shape->get_width(); col++) {
        if (shape->shapedata(row, col) == '#')
	  return(true);
      }
    }
  }

  // We're off the BOTTOM edge.
  if ((start_y + shape->get_height()) > grid_height) {
    int overhang = start_y + shape->get_height() - grid_height;
    // Check that the shape doesn't have an empty data rows
    for (int row = shape->get_height() - overhang; row < shape->get_height(); row++) {
      for (int col = 0; col < shape->get_width(); col++) {
        if (shape->shapedata(row, col) == '#')
	  return(true);
      }
    }
  }
  return(false);
  // TODO: Work the empty parts of the rotation
}
