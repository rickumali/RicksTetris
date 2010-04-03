#include <string>
using std::string;

#ifndef GUARD_shape_h
#define GUARD_shape_h
class Shape {
    private:
        int shape_height[4];
        int shape_width[4];
        string shape_data[4];
    	int rotation; /* 0 to 3 */
    public:
    	Shape();
    	virtual int get_piece_type() = 0;
    	virtual void rotate_left() = 0;
    	virtual void rotate_right() = 0;
    	virtual void draw() = 0;
    	virtual void init_shape(int, int, string []) = 0;
    	int height() const;
    	int width() const;
    	int& height();
    	int& width();
        char shapedata(int, int) const;
        char& shapedata(int, int);
        string& shapedata();
    	void rotate(int);
};
#endif
