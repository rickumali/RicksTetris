#include <string>

#ifndef GUARD_scoresystem_h
#define GUARD_scoresystem_h
class ScoreSystem {
    private:
        int current_score;
        int level;
    public:
    	ScoreSystem();
    	virtual int add_lines_to_score(int) = 0;
	int get_current_score();
	void set_current_score(int);
	void add_to_current_score(int);
	void write_score_to_file();
	int get_level();
	void increment_level();
};
#endif

