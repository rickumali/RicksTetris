# Makefile for Rick's Tetris Game (and other support files)

CC = g++
CPPFLAGS = -g -I\MinGW\include\SDL
LOADLIBES = -lmingw32 -lSDLmain \MinGW\lib\SDL_image.lib \MinGW\lib\SDL_ttf.lib -lSDL

SHAPES_HEADERS = Shape.h Square.h Pyramid.h LeftSlant.h RightSlant.h LongRow.h LeftEll.h RightEll.h Grid.h
SHAPES_SOURCE = Shape.cpp Square.cpp Pyramid.cpp LeftSlant.cpp RightSlant.cpp LongRow.cpp LeftEll.cpp RightEll.cpp Grid.cpp
SHAPES = Shape.o Square.o Pyramid.o LeftSlant.o RightSlant.o LongRow.o LeftEll.o RightEll.o Grid.o

SDLSHAPES_HEADERS = SDLSquare.h SDLPyramid.h SDLLeftSlant.h SDLRightSlant.h SDLLongRow.h SDLLeftEll.h SDLRightEll.h SDLGrid.h
SDLSHAPES_SOURCE = SDLSquare.cpp SDLPyramid.cpp SDLLeftSlant.cpp SDLRightSlant.cpp SDLLongRow.cpp SDLLeftEll.cpp SDLRightEll.cpp SDLGrid.cpp
SDLSHAPES = SDLSquare.o SDLPyramid.o SDLLeftSlant.o SDLRightSlant.o SDLLongRow.o SDLLeftEll.o SDLRightEll.o SDLGrid.o

#------------------------------
# Character-based Shape Testers
#------------------------------

# This is a command line tool to exercise the individual shapes
# It draws the shapes in a character on the command line screen
testshape: testshape.o $(SHAPES)

# This ia test program of a refactored approach to shapes
testshapedata: testshapedata.o $(SHAPES)

# This tests a simple 'character-based' grid
testchargrid: testchargrid.o $(SHAPES) Grid.o

#------------
# SDL Testers
#------------

# This just draws a grid using the SDL
firstgrid: firstgrid.o

# This just draws a grid, but the new object SDLGrid
secondgrid: secondgrid.o SDLGrid.o Grid.o Shape.o putpixel.o

# This program just moves a single square. No SDL shape objects or classes.
movingsquare: movingsquare.o

# This program moves a Tetris square. Does NOT use SDL shape objects or classes.
movingpieces: movingpieces.o

# This is a program that demonstrates each of the objects on a "big" grid
testsdlshape: testsdlshape.o $(SHAPES) $(SDLSHAPES) putpixel.o 

# This tests the shapes "falling" based on gravity. Use 'f' for Faster
# and 's' for slower
testgravity: testgravity.o $(SHAPES) $(SDLSHAPES) putpixel.o Timer.o

# This is my attempt to test collision with the edges. I am beginning to 
# abandon the adjust_x and adjust_y methods found in putpixel().
testhit: testhit.o Shape.o Square.o SDLSquare.o Pyramid.o SDLPyramid.o putpixel.o Timer.o

#--------------
# Miscellaneous
#--------------

# Test tests random numbers. What you should see is that there's 
# no VARIATION in between runs. At least how I currently have written things.
testnrand: testnrand.o nrand.o

# Test an input routine.
testinput: testinput.o

# This program tests virtual functions
virtualfunc: virtualfunc.o

clean:
	rm -f *.o *.exe *~ stdout.txt stderr.txt

#-----
# Tags
#-----
tags:
	/c/ctags58/ctags.exe *.cpp *.h
