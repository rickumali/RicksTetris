#include <fstream>
#include <time.h>
#include "ScoreSystem.h"

using namespace std;

// Constructor
ScoreSystem::ScoreSystem() {
  current_score = 0;
}

void ScoreSystem::set_current_score(int score) {
  current_score = score;
}

void ScoreSystem::add_to_current_score(int score) {
  current_score += score;
}

int ScoreSystem::get_current_score() {
  return(current_score);
}

void ScoreSystem::write_score_to_file() {
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime(&rawtime);

	ofstream scorefile;
	scorefile.open("scores.txt",ios::app|ios::out);
	if (!scorefile.fail()) {
	  scorefile << asctime(timeinfo);
	  scorefile << current_score;
	  scorefile << endl;
	  scorefile.close();
	}
}
