#include "StatKeeper.h"
#include "Constants.h"
#include <iostream>

using std::cout;
using std::endl;

StatKeeper::StatKeeper() {
}

void StatKeeper::clear_counters() {
  for (int i=0; i<7; i++)
	  shape_count[i] = 0;
}

void StatKeeper::increment_shape_count(int shape) {
  // This takes a shape constant (from Constants.h), and increments the counter
  if (shape < 1 || shape > 7)
	  return;
  shape--;
  shape_count[shape]++;
}

int StatKeeper::get_shape_count(int shape) {
  shape--;
  return(shape_count[shape]);
}

void StatKeeper::dump_stats() {
	cout << "SQUARE: " << get_shape_count(SQUARE) << endl;
	cout << "PYRAMID: " << get_shape_count(PYRAMID) << endl;
	cout << "LEFT_SLANT: " << get_shape_count(LEFT_SLANT) << endl;
	cout << "RIGHT_SLANT: " << get_shape_count(RIGHT_SLANT) << endl;
	cout << "LONG_ROW: " << get_shape_count(LONG_ROW) << endl;
	cout << "LEFT_ELL: " << get_shape_count(LEFT_ELL) << endl;
	cout << "RIGHT_ELL: " << get_shape_count(RIGHT_ELL) << endl;
}
