#include <fstream>
#include <time.h>
#include "ScoreSystem.h"

using namespace std;

// Constructor
ScoreSystem::ScoreSystem() {
  current_score = 0;
  level = 1;
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
	rawtime = time(NULL);

	ofstream scorefile;
	scorefile.open("scores.txt",ios::app|ios::out);
	if (!scorefile.fail()) {
	  scorefile << rawtime << " " << current_score << " " << level << endl;
	  scorefile.close();
	}
}

int ScoreSystem::get_level() {
  return(level);
}

void ScoreSystem::increment_level() {
  level++;
  if (level > 999999) {
    level = 1000000; // Cap level at 1M
  }
}
