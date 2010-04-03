#include "Shape.h"

// Constructor
Shape::Shape() {
  rotation = 0;
}

// height()
int Shape::height() const {
  return shape_height[rotation];
}

// width()
int Shape::width() const {
  return shape_width[rotation];
}
// &height()
int& Shape::height() {
  return shape_height[rotation];
}

// &width()
int& Shape::width() {
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
char Shape::shapedata(int row, int col) const {
      return (shape_data[rotation][(row*shape_width[rotation])+col]);
}
char& Shape::shapedata(int row, int col) {
      return (shape_data[rotation][(row*shape_width[rotation])+col]);
}

// This is meant for initialization routines. It returns a reference to 
// shape_data for the current "rotation." See init_shape() routines in the 
// various shapes.
string& Shape::shapedata() {
      return shape_data[rotation];
}
