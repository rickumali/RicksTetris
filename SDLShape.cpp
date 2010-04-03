#include "SDLShape.h"

// Constructor
SDLShape::SDLShape() {
}

// get_height()
int SDLShape::get_height() {
  return shape->height();
}

// get_width()
int SDLShape::get_width() {
  return shape->width();
}

void SDLShape::rotate_left() {
    shape->rotate(-1);
}

void SDLShape::rotate_right() {
    shape->rotate(1);
}

// return the shape_data character at row, col
char SDLShape::shapedata(int row, int col) {
      return (shape->shapedata(row, col));
}

// get_shape()
Shape *SDLShape::get_shape() {
  return shape;
}
