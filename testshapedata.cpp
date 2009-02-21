#include <iostream>

using namespace std;

string const pyramid[] = {
  " # \n###",
  "# \n##\n# ",
  "###\n # ",
  " #\n##\n #",
};
main() {
	cout << pyramid[0] << endl;
	cout << endl;
	cout << pyramid[1] << endl;
	cout << endl;
	cout << pyramid[2] << endl;
	cout << endl;
	cout << pyramid[3] << endl;
}
