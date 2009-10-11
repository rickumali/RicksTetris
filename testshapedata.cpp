#include <iostream>
#include "Square.h"
#include "RightEll.h"
#include "RightSlant.h"
#include "LongRow.h"
#include "Pyramid.h"
#include "LeftSlant.h"
#include "LeftEll.h"

using namespace std;

// Replace "Square" with any of the shapes:
// Square, RightEll, RightSlant, LongRow, Pyramid, LeftSlant, LeftEll

main() {
  LeftEll shape;
  for (int row = 0; row < shape.get_height(); row++) {
    for (int col = 0; col < shape.get_width(); col++) {
      cout << shape.shapedata(row, col);
    }
    cout << endl;
  }
  cout << "----------" << endl;
  shape.draw(0,0);
}
