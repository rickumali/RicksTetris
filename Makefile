# Makefile for Rick's Tetris Game (and other support files)

CC = g++
CPPFLAGS = -g -I\MinGW\include\SDL
LOADLIBES = -lmingw32 -lSDLmain \MinGW\lib\SDL_image.lib \MinGW\lib\SDL_ttf.lib -lSDL

SHAPES_HEADERS = Shape.h Square.h Pyramid.h LeftSlant.h RightSlant.h LongRow.h LeftEll.h RightEll.h Grid.h
SHAPES_SOURCE = Shape.cpp Square.cpp Pyramid.cpp LeftSlant.cpp RightSlant.cpp LongRow.cpp LeftEll.cpp RightEll.cpp Grid.cpp
SHAPES = Shape.o Square.o Pyramid.o LeftSlant.o RightSlant.o LongRow.o LeftEll.o RightEll.o Grid.o

SDLSHAPES_HEADERS = SDLSquare.h SDLPyramid.h SDLLeftSlant.h SDLRightSlant.h SDLLongRow.h SDLLeftEll.h SDLRightEll.h SDLGrid.h
SDLSHAPES_SOURCE = SDLShape.cpp SDLSquare.cpp SDLPyramid.cpp SDLLeftSlant.cpp SDLRightSlant.cpp SDLLongRow.cpp SDLLeftEll.cpp SDLRightEll.cpp SDLGrid.cpp
SDLSHAPES = SDLShape.o SDLSquare.o SDLPyramid.o SDLLeftSlant.o SDLRightSlant.o SDLLongRow.o SDLLeftEll.o SDLRightEll.o SDLGrid.o

SCORING_HEADERS = ScoreSystem.h OriginalNintendoScoring.h
SCORING_SOURCE = ScoreSystem.cpp OriginalNintendoScoring.cpp
SCORING = ScoreSystem.o OriginalNintendoScoring.o

SDLSCORING_HEADERS = SDLScoreSystem.h
SDLSCORING_SOURCE = SDLScoreSystem.cpp
SDLSCORING = SDLScoreSystem.o

STATKEEPER_HEADERS = StatKeeper.h
STATKEEPER_SOURCE = StatKeeper.cpp
STATKEEPER = StatKeeper.o

SDLSTATKEEPER_HEADERS = SDLStatKeeper.h
SDLSTATKEEPER_SOURCE = SDLStatKeeper.cpp
SDLSTATKEEPER = SDLStatKeeper.o

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

# This tests ONE SDLShape (used this to initially test refactored shapes)
# Manually replace the shape with the one you want to use

# testoneshape: testoneshape.o Shape.o SDLShape.o Square.o SDLSquare.o Grid.o SDLGrid.o putpixel.o 
# testoneshape: testoneshape.o Shape.o SDLShape.o Pyramid.o SDLPyramid.o Grid.o SDLGrid.o putpixel.o 
# testoneshape: testoneshape.o Shape.o SDLShape.o LeftSlant.o SDLLeftSlant.o Grid.o SDLGrid.o putpixel.o 
# testoneshape: testoneshape.o Shape.o SDLShape.o RightSlant.o SDLRightSlant.o Grid.o SDLGrid.o putpixel.o 
# testoneshape: testoneshape.o Shape.o SDLShape.o LongRow.o SDLLongRow.o Grid.o SDLGrid.o putpixel.o 
# testoneshape: testoneshape.o Shape.o SDLShape.o LeftEll.o SDLLeftEll.o Grid.o SDLGrid.o putpixel.o 
testoneshape: testoneshape.o Shape.o SDLShape.o RightEll.o SDLRightEll.o Grid.o SDLGrid.o putpixel.o 

# This is a program that demonstrates each of the objects on a "big" grid
testsdlshape: testsdlshape.o $(SHAPES) $(SDLSHAPES) putpixel.o 

# This tests the shapes "falling" based on gravity. For a LONG TIME this was the ACTUAL GAME ITSELF!
testgravity: testgravity.o ShapeBag.o $(SHAPES) $(SDLSHAPES) $(SCORING) $(SDLSCORING) putpixel.o Timer.o

# This tests the statistics system
teststats: teststats.o ShapeBag.o $(SHAPES) $(SDLSHAPES) $(STATKEEPER) $(SDLSTATKEEPER) putpixel.o Timer.o

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

# This program tests the refactored initialization
testinitializer: testinitializer.o

# Tests good old Fisher-Yates
fisheryates: fisheryates.o

# Tests the ShapeBag
testshapebag: testshapebag.o ShapeBag.o Shape.o Square.o Pyramid.o LeftSlant.o RightSlant.o LongRow.o LeftEll.o RightEll.o SDLShape.o SDLSquare.o SDLPyramid.o SDLLeftSlant.o SDLRightSlant.o SDLLongRow.o SDLLeftEll.o SDLRightEll.o

# Tests Bitmap BLT'ing
testsamplebitmap: testsamplebitmap.o

# Test tests random numbers. What you should see is that there's 
# no VARIATION in between runs. At least how I currently have written things.
shapestatlocs: shapestatlocs.o

clean:
	rm -f *.o *.exe *~ stdout.txt stderr.txt

#-----
# Tags
#-----
tags:
	/c/ctags58/ctags.exe *.cpp *.h
