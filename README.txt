tetris

This is my attempt to learn how to write a Win32 game. But I don't start
entirely from scratch. I make use of SDL, the Simple DirectMedia Layer library
from www.libsdl.org.

grid.cpp = First attempt to make a simple grid.

In the week of 2/16, my laptop hard drive crashed. I had to recover my Tetris files MINUS my SVN log.

Refactor grid to NOT refer to grid_data directly, but rather go through
griddata. This will enable me to hide the implementation (switch between
griddata as a raw string or griddata as a List of Strings).
