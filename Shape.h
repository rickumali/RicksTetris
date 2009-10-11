#ifndef GUARD_shape_h
#define GUARD_shape_h
class Shape {
    protected:
        int shape_height[4];
        int shape_width[4];
	    char *shape_data[4];
    	int rotation; /* 0 to 3 */
    	void rotate(int);
    public:
    	Shape();
    	virtual int get_piece_type() = 0;
    	virtual int rotate_left() = 0;
    	virtual int rotate_right() = 0;
    	virtual void draw(int, int) = 0;
    	int get_height();
    	int get_width();
	char shapedata(int, int);
};
#endif
