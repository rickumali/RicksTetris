#include "ScoreSystem.h"

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
