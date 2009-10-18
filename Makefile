# Makefile for Rick's Tetris Game (and other support files)

CC = g++
CPPFLAGS = -g -I\MinGW\include\SDL
LOADLIBES = -lmingw32 -lSDLmain \MinGW\lib\SDL_image.lib \MinGW\lib\SDL_ttf.lib -lSDL

# This just draws a grid
firstgrid: firstgrid.o

# This program just moves a single square. No objects or classes.
movingsquare: movingsquare.o

# This program moves a Tetris square. 
movingpieces: movingpieces.o

# This program tests virtual functions
virtualfunc: virtualfunc.o

# This ia test program of a refactored approach to shapes
testshapedata: testshapedata.o

# This is a command line tool to exercise the individual shapes
# It draws the shapes in a character on the command line screen
testshape: testshape.o Shape.o Square.o Pyramid.o LeftSlant.o RightSlant.o LongRow.o LeftEll.o RightEll.o

# This is a program that demonstrates each of the objects on a "big" grid
testsdlshape: testsdlshape.o Shape.o Square.o SDLSquare.o Pyramid.o SDLPyramid.o LeftSlant.o SDLLeftSlant.o RightSlant.o SDLRightSlant.o LongRow.o SDLLongRow.o LeftEll.o SDLLeftEll.o RightEll.o SDLRightEll.o putpixel.o

# This tests the shapes "falling" based on gravity. Use 'f' for Faster
# and 's' for slower
testgravity: testgravity.o Shape.o Square.o SDLSquare.o Pyramid.o SDLPyramid.o LeftSlant.o SDLLeftSlant.o RightSlant.o SDLRightSlant.o LongRow.o SDLLongRow.o LeftEll.o SDLLeftEll.o RightEll.o SDLRightEll.o putpixel.o Timer.o

# This is my attempt to test collision with the edges. I am beginning to 
# abandon the adjust_x and adjust_y methods found in putpixel().
testhit: testhit.o Shape.o Square.o SDLSquare.o Pyramid.o SDLPyramid.o putpixel.o Timer.o

# Test tests random numbers. What you should see is that there's 
# no VARIATION in between runs. At least how I currently have written things.
testnrand: testnrand.o nrand.o

# Test an input routine.
testinput: testinput.o

# This tests a simple 'character-based' grid
testchargrid: testchargrid.o Grid.o Square.o Shape.o Pyramid.o LeftSlant.o RightSlant.o LongRow.o LeftEll.o RightEll.o

# This tests the new form shapedata() method in Shape
testshapedata: testshapedata.o Shape.o Square.o Pyramid.o LeftSlant.o RightSlant.o LongRow.o LeftEll.o RightEll.o

clean:
	rm -f *.o *.exe *~ stdout.txt stderr.txt
