#include "ScoreSystem.h"

class OriginalNintendoScoring : public ScoreSystem {
  private:
    int pts_for_lines[5];
  public:
    OriginalNintendoScoring();
    int add_lines_to_score(int, int);
};
