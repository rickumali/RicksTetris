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
Shape* SDLShape::get_shape() {
  return shape;
}

// set_shape()
void SDLShape::set_shape(Shape *shape_in) {
  shape = shape_in;
}

// set_surface()
void SDLShape::set_surface(SDL_Surface *surface_in) {
  surface = surface_in;
}

// get_surface()
SDL_Surface* SDLShape::get_surface() {
  return(surface);
}

// set_color()
void SDLShape::set_color(Uint32 color_in) {
  color = color_in;
}

// get_color()
Uint32 SDLShape::get_color() {
  return(color);
}

// get_piece_type()
int SDLShape::get_piece_type() {
  return(shape->get_piece_type());
}
