// testinitializer.cpp
//

#include <iostream>

using namespace std;

void init_shape(int rotation, int square_size, string shape_data[]) {
	string final_data[4];
	cout << "Rotation: " << rotation << " " << endl;
	cout << "Square Size: " << square_size << " " << endl;
	// get length of shape_data to get square_size
	// NOTE: Couldn't figure this out
	// cout << "Number of initializer strings: " << sizeof(shape_data)/sizeof(shape_data)<< endl;
	for (int i = 0; i < square_size; i++) {
		cout << shape_data[i] << endl;
		final_data[rotation] += shape_data[rotation];
	}
	cout << "Final shape data: " << final_data[rotation] << " " << endl;
	cout << "Final shape data length: " << final_data[rotation].length() << " " << endl;
}

int main( int argc, char* args[] )
{
	string sp1[2] = 
{ "##",
  "##" };
	init_shape(0, 2, sp1); 
	string sp2[4] = 
{ "  # ",
  "  # ",
  "  # ",
  "  # ",
};
	init_shape(0, 4, sp2); 
}
