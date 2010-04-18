#include "OriginalNintendoScoring.h"

OriginalNintendoScoring::OriginalNintendoScoring() : ScoreSystem()
{
  pts_for_lines[0] = 0;
  pts_for_lines[1] = 40;
  pts_for_lines[2] = 100;
  pts_for_lines[3] = 300;
  pts_for_lines[4] = 1200;
}

int OriginalNintendoScoring::add_lines_to_score(int level, int lines) {
  int current_score = get_current_score();
  current_score = (pts_for_lines[lines] * (level + 1));
  add_to_current_score(current_score);
  return(current_score);
}
