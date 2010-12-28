#include <iostream>
#include <fstream>

using namespace std;

typedef struct stat_loc {
  int x, y;
} STAT_LOC;

int main()
{
        STAT_LOC shape_stat_loc[7];
  shape_stat_loc[0].x = 270; shape_stat_loc[0].y = 250; // SQUARE 
  shape_stat_loc[1].x = 276; shape_stat_loc[1].y = 372; // PYRAMID
  shape_stat_loc[2].x = 479; shape_stat_loc[2].y = 250; // LEFT_SLANT
  shape_stat_loc[3].x = 374; shape_stat_loc[3].y = 250; // RIGHT_SLANT
  shape_stat_loc[4].x = 563; shape_stat_loc[4].y = 290; // LONG_ROW
  shape_stat_loc[5].x = 376; shape_stat_loc[5].y = 372; // LEFT_ELL
  shape_stat_loc[6].x = 481; shape_stat_loc[6].y = 372; // RIGHT_ELL
	for (int i = 0; i < 7; i++) {
	        cout << i << ":" << shape_stat_loc[i].x << "," << shape_stat_loc[i].y << endl;
	}
}
