# Makefile for Rick's Tetris Game (and other support files)

CC = g++
CPPFLAGS = -g -I\MinGW\include\SDL
LOADLIBES = -lmingw32 -lSDLmain \MinGW\lib\SDL_image.lib \MinGW\lib\SDL_ttf.lib -lSDL

SHAPES = Shape.o Square.o Pyramid.o LeftSlant.o RightSlant.o LongRow.o LeftEll.o RightEll.o Grid.o
SDLSHAPES = SDLSquare.o SDLPyramid.o SDLLeftSlant.o SDLRightSlant.o SDLLongRow.o SDLLeftEll.o SDLRightEll.o SDLGrid.o

# This just draws a grid
firstgrid: firstgrid.o

# This just draws a grid, but the new style SDLGrid
secondgrid: secondgrid.o SDLGrid.o Grid.o Shape.o putpixel.o

# This program just moves a single square. No objects or classes.
movingsquare: movingsquare.o

# This program moves a Tetris square. 
movingpieces: movingpieces.o

# This program tests virtual functions
virtualfunc: virtualfunc.o

# This ia test program of a refactored approach to shapes
testshapedata: testshapedata.o $(SHAPES)

# This is a command line tool to exercise the individual shapes
# It draws the shapes in a character on the command line screen
testshape: testshape.o 

# This is a program that demonstrates each of the objects on a "big" grid
testsdlshape: testsdlshape.o $(SHAPES) $(SDLSHAPES) putpixel.o 

# This tests the shapes "falling" based on gravity. Use 'f' for Faster
# and 's' for slower
testgravity: testgravity.o $(SHAPES) $(SDLSHAPES) putpixel.o Timer.o

# This is my attempt to test collision with the edges. I am beginning to 
# abandon the adjust_x and adjust_y methods found in putpixel().
testhit: testhit.o Shape.o Square.o SDLSquare.o Pyramid.o SDLPyramid.o putpixel.o Timer.o

# Test tests random numbers. What you should see is that there's 
# no VARIATION in between runs. At least how I currently have written things.
testnrand: testnrand.o nrand.o

# Test an input routine.
testinput: testinput.o

# This tests a simple 'character-based' grid
testchargrid: testchargrid.o $(SHAPES) Grid.o

clean:
	rm -f *.o *.exe *~ stdout.txt stderr.txt

tags:
	/c/ctags58/ctags.exe *.cpp *.h
