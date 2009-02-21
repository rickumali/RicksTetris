#include "Square.h"
#include "Pyramid.h"
#include "LeftSlant.h"
#include "RightSlant.h"
#include "LongRow.h"
#include "LeftEll.h"
#include "RightEll.h"
#include "Constants.h"

#include <iostream>
#include <vector>

using namespace std;

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

	char choice;
	int selected_shape;
	while (true) {
		selected_shape = -1;

		cout << "(1) Square, (2) Pyramid," << endl << "(3) Left Slant, (4) Right Slant," << endl << "(5) Long Row," << endl << "(6) Left Ell, (7) Right Ell," << endl << "(q)uit" << endl;
		cin >> choice;

		switch (choice) {
			case '1': selected_shape = 0; break;
			case '2': selected_shape = 1; break;
			case '3': selected_shape = 2; break;
			case '4': selected_shape = 3; break;
			case '5': selected_shape = 4; break;
			case '6': selected_shape = 5; break;
			case '7': selected_shape = 6; break;
			default:
				break;
		}

		if (selected_shape == -1) {
			break;
		}

		cout << "(l)eft rotate, (r)ight rotate, (d)raw" << endl;
		cin >> choice;

		if (choice == 'l') {
			shapes_vector[selected_shape]->rotate_left();
			shapes_vector[selected_shape]->draw(2,2);
		} else if (choice == 'r'){
			shapes_vector[selected_shape]->rotate_right();
			shapes_vector[selected_shape]->draw(2,2);
		} else {
			shapes_vector[selected_shape]->draw(2,2);
		}
	}
}
