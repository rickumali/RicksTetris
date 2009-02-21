#include <iostream>
#include <fstream>
#include "nrand.h"

using namespace std;

int main()
{
	for (int i = 0; i < 100; i++) {
		cout.width(5);
	        cout << nrand(11);
		if ((i+1)%15==0)
			cout << endl;
	}
}
