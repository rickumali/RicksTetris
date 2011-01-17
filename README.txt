		       R I C K ' S  T E T R I S

Thanks for downloading, installing and checking out my version of
Tetris.

To find out more, visit http://tech.rickumali.com/tetris

This is version 1.0.

----------------------------------------------------------------------

Playing 
-------

Pieces fall down. As they fall, you can rotate them. Position them so
that they form a pile. When the pile fills the entire row, the row is
"cleared", and you earn points! After 10 rows are cleared, you move to
the next level, and the pieces fall faster.

Up Arrow   - Rotate Piece Left (counter-clockwise)
Down Arrow - Rotate Piece Right (clockwise)
Left       - Move Piece Left
Right      - Move Piece Right
P          - Pause the Game
H          - Display the Help Screen
Q          - Quit the Game

Scores
------

All scores are saved to a file called scores.txt in the same directory as
the program. The first column is the date (expressed in the UNIX epoch),
the second column is the score, and the third column is the level.

If you're adept with Perl you can try to run the scoretable.pl Perl program
to produce a listing of your scores. Read scoretable.pl for details on
how to use.

A future version of my implementation of Tetris will process this
file.

Error Messages
--------------

1. Can't find VeraBd.ttf font file. 

The program looks for this Windows TrueType font in 

c:\WINDOWS\Fonts\VeraBd.ttf
c:\MinGW\ttf-bitstream-vera-1.10\VeraBd.ttf
<program's installation directory>\VeraBd.ttf

The font itself is at:

http://ftp.gnome.org/pub/GNOME/sources/ttf-bitstream-vera/1.10/

You can read more here:

http://www.gnome.org/fonts/

The installation will install VeraBd.ttf next to the program.

2. Can't initialize SDL graphics library.
3. Can't set up SDL screen. 
4. Can't lock screen.
5. Can't flip screen.

These four errors indicate an issue with the SDL library. An error
message will be printed to a file named stdout.txt in the same
directory as the program. Searching that error message on the Internet
may produce a fix, but chances are there could be an incompatbility
that prevents you from playing this game. If so, sorry!

6. Can't load help.bmp.
7. Can't load tetris.bmp.
8. Can't load start.bmp.

These messages indicate that the bitmap files are not in the same
directory as the program. Ensure that these files are there. They can
also be retrieved from the website mentioned above.

Feedback
--------

Comments? Questions? Send e-mail to rickumali@gmail.com 

Acknowledgements
----------------

Thank you Jenn, Mia, Snowbie, Puggy, Annie, Bobo, Zipzap.
