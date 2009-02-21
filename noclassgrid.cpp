#include <iostream>

using std::cout;
using std::endl;

// Constructor
int main( int argc, char* args[] ) {
  int grid_height = 22;
  int grid_width = 10;
  char* grid_data = new char[grid_height * grid_width];
  for (int i = 0; i < (grid_height * grid_width); i++)
    grid_data[i] = '.';
    // *grid_data++ = '.';
  cout << "noclassgird: Constructor: " << grid_data << endl;

  cout << "noclassgird: Draw: " << grid_data << endl;
  for (int row = 0; row < grid_height; row++) {
    for (int col = 0; col < grid_width; col++) {
      cout << grid_data[(row * grid_width)+col];
    }
    cout << endl;
  }
}
