# Makefile for Rick's Tetris Game (and other support files)

CC      = g++
EXE	= .exe
CFLAGS  = -I\MinGW\include\SDL
LIBS	= -lmingw32 -lSDLmain \MinGW\lib\SDL_image.lib \MinGW\lib\SDL_ttf.lib -lSDL
MATHLIB = -lm

grid$(EXE): grid.cpp
	$(CC) -o $@ $? $(CFLAGS) $(LIBS)

clean:
	rm grid$(EXE)
	rm grid.o

all: grid$(EXE)

