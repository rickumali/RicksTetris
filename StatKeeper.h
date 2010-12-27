#include <string>

#ifndef GUARD_statkeeper_h
#define GUARD_statkeeper_h
class StatKeeper {
    private:
	// Each shape (in Constants.h) is COUNTED in this array.
	// NOTE: The shape constant is decremented BY ONE to fit this 
	// array.
        int shape_count[7];
    public:
    	StatKeeper();
	void clear_counters();
	void increment_shape_count(int);
	int get_shape_count(int);
	void dump_stats();
};
#endif

