#include "Grid.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Constructor
Grid::Grid() {
  grid_height = 22;
  grid_width = 10;
  // char* grid_data = new char[grid_height * grid_width];
  // for (int i = 0; i < (grid_height * grid_width); i++)
  //  grid_data[i] = '.';
  grid_data = string(22 * 10, '.');
  cout << "Constructor: " << grid_data << endl;
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
void Grid::draw(int start_x, int start_y) {
  cout << "Draw: " << grid_data << endl;
  for (int row = 0; row < grid_height; row++) {
    for (int col = 0; col < grid_width; col++) {
      cout << grid_data[(row * grid_width)+col];
    }
    cout << endl;
  }
}
