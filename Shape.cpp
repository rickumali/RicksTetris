#include "Shape.h"
#include <iostream>

// Constructor
Shape::Shape() {
  rotation = 0;
}

// get_height()
int Shape::get_height() {
  return shape_height[rotation];
}

// get_width()
int Shape::get_width() {
  return shape_width[rotation];
}

// direction is -1 for left, and +1 for right
void Shape::rotate(int direction) {
  rotation += direction;
  if (rotation < 0) {
	  rotation = 3;
  } else if (rotation > 3) {
	  rotation = 0;
  }
}

// return the shape_data character at row, col
// Take a look at the Ruminations on C++ Book, Chapter 9, for the 
// inspiration of this method
char Shape::shapedata(int row, int col) {
      return (shape_data[rotation][(row*shape_width[rotation])+col]);
}
