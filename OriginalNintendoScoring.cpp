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
  add_to_current_score(pts_for_lines[lines] * (level + 1));
  if (get_current_score() > 999999999) {
    // We're rolling over back to 0 if we're at 1B
    set_current_score(0);
  }
  return(get_current_score());
}
