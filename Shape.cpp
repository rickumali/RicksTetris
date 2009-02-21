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
