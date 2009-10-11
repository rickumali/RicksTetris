#include <iostream>
#include "Square.h"
#include "Grid.h"
using std::cout;

int main( int argc, char* args[] )
{
	Square *square = new Square();
	Grid my_grid;
	my_grid.draw();
	cout << "----------\n";
	my_grid.draw(0, 0, square);
	cout << "----------\n";
	my_grid.draw(0, 1, square);
}
