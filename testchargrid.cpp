#include "Square.h"
#include "Grid.h"

int main( int argc, char* args[] )
{
	Square *square = new Square();
	Grid my_grid;
	my_grid.draw();
	my_grid.draw(0, 0, square);
}
