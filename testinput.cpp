/*
 * Can you believe I don't really know how to make this kind of loop anymore? The 
 * work below is to inform testchargrid.cpp. I borrowed from:
 *
 * http://www.cplusplus.com/reference/clibrary/cstring/strtok/
 * http://www.cplusplus.com/reference/iostream/istream/getline/
 */
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	bool quit = false;
	char input[40];

	while (!quit) {
		cout << "N R X Y (Q to Quit; H for Help)" << endl;
		cin.getline(input, 40);

		char *pch;
		pch = strtok (input," ");
		int cnt = 0;
		while (pch != NULL)
		{
			if (0 == strcmp(pch, "q")) {
				quit = true;
				break;
			}
			cnt++;
			printf ("%d => %s\n", cnt, pch);
			pch = strtok (NULL, " ");
		}
	}
}
