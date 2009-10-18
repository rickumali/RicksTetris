#include <iostream>
#include <vector>

#include "Grid.h"
#include "Square.h"
#include "Pyramid.h"
#include "LeftSlant.h"
#include "RightSlant.h"
#include "LongRow.h"
#include "LeftEll.h"
#include "RightEll.h"

using namespace std;

void print_help();

int main( int argc, char* args[] )
{
	vector<Shape *> shapes_vector;
	Shape* shape;

	shape = new Square();
	shapes_vector.push_back(shape);

	shape = new Pyramid();
	shapes_vector.push_back(shape);

	shape = new LeftSlant();
	shapes_vector.push_back(shape);

	shape = new RightSlant();
	shapes_vector.push_back(shape);

	shape = new LongRow();
	shapes_vector.push_back(shape);

	shape = new LeftEll();
	shapes_vector.push_back(shape);

	shape = new RightEll();
	shapes_vector.push_back(shape);

	Grid my_grid(20,20);

	bool quit = false;
	int selected_shape = 0;
	int rot = 0;
	int x = 0, y = 0;
	char input[40];
	while (!quit) {
		cout << "N R X Y (Q to Quit; H for Help)" << endl;
		cin.getline(input, 40);

		int tok_cnt = 0;
		char *pch;
		pch = strtok (input," ");
		while (pch != NULL)
		{
			rot = -1;
			if (0 == strcmp(pch, "q")) {
				exit(0);
			}
			if (0 == strcmp(pch, "h")) {
				print_help();
				break;
			}
			tok_cnt++;
			switch(tok_cnt) {
				case 1:
					selected_shape = atoi(pch);
					if ((selected_shape < 0) || (selected_shape > 7)) {
						selected_shape = 0;
					}
					break;
				case 2:
					rot = atoi(pch);
					break;
				case 3:
					x = atoi(pch);
					break;
				case 4:
					y = atoi(pch);
					break;
				default:
					break;
			}
			pch = strtok (NULL, " ");
		}

		// If user only specified the shape and the rotation, then 
		// update the x and y
		if (tok_cnt < 2) {
			x++;
			if (x > my_grid.width()) {
				x = 0; y++;
			}
			if (y > my_grid.height())
				y = 0;
		}
		// If user specified the rotation
		// then rotate right for now
		if (rot != -1) {
			shapes_vector[selected_shape]->rotate_right();
		}

		cout << "----------\n";
		my_grid.draw(x, y, shapes_vector[selected_shape]);
		my_grid.draw();
	}
}

void print_help() {
	cout << "(0) Square, (1) Pyramid, (2) Left Slant, (3) Right Slant," << endl << "(4) Long Row, (5) Left Ell, (6) Right Ell," << endl << "(q)uit" << endl;
}
