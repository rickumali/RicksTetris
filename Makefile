# Makefile for Rick's Tetris Game (and other support files)

CC = g++
CPPFLAGS = -g -I\MinGW\include\SDL
LOADLIBES = -lmingw32 -lSDLmain \MinGW\lib\SDL_image.lib \MinGW\lib\SDL_ttf.lib -lSDL

firstgrid: firstgrid.o

testchargrid: testchargrid.o Grid.o

# This program just moves a single square. No objects or classes.
movingsquare: movingsquare.o

# This program moves a Tetris square. 
movingpieces: movingpieces.o

# This program tests virtual functions
virtualfunc: virtualfunc.o

# This ia test program of a refactored approach to shapes
testshapedata: testshapedata.o

# This is a command line tool to exercise the individual shapes
testshape: testshape.o Shape.o Square.o Pyramid.o LeftSlant.o RightSlant.o LongRow.o LeftEll.o RightEll.o

testsdlshape: testsdlshape.o Shape.o Square.o SDLSquare.o Pyramid.o SDLPyramid.o LeftSlant.o SDLLeftSlant.o RightSlant.o SDLRightSlant.o LongRow.o SDLLongRow.o LeftEll.o SDLLeftEll.o RightEll.o SDLRightEll.o putpixel.o

testgravity: testgravity.o Shape.o Square.o SDLSquare.o Pyramid.o SDLPyramid.o LeftSlant.o SDLLeftSlant.o RightSlant.o SDLRightSlant.o LongRow.o SDLLongRow.o LeftEll.o SDLLeftEll.o RightEll.o SDLRightEll.o putpixel.o Timer.o

testhit: testhit.o Shape.o Square.o SDLSquare.o Pyramid.o SDLPyramid.o putpixel.o Timer.o

testnrand: testnrand.o nrand.o

clean:
	rm -f *.o *.exe stdout.txt stderr.txt
