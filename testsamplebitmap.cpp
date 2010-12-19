/**
 *
 * Code sample based on http://dungeonmaker.sourceforge.net/manual/tutorial1_1.html
 */

#include<SDL/SDL.h>

int main( int argc, char* args[] )
{
  SDL_Surface* screen;
  SDL_Surface* image;
  SDL_Rect src , dest;

  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("Unable to init SDL: %s\n" , SDL_GetError());
    return(1);
  }
  atexit(SDL_Quit);

  //x and y are the dimensions of our map, and we render each map-square as an
  //image of 4x4 white pixels - (scale == 4)
  //we want a 16 bit color model, so we don't have to mess with a palette
  //the last parameter 0 gives us a rendering surface in a window
  screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
  if(screen == NULL) {
    printf("Unable to set video mode: %s\n" , SDL_GetError());
    return(1);
  }

  image = SDL_LoadBMP("samplebitmap.bmp");
  if(image == NULL) {
     printf("Unable to load samplebitmap.bmp\n");
     return(1);
  }
  src.x = 0;
  src.y = 0;
  dest.x = 0;
  dest.y = 0;
  SDL_BlitSurface(image , &src , screen , &dest);

  SDL_UpdateRect(screen , 0 , 0 , 0 , 0 );
  
  //now wait for the user to close the window
  SDL_Event event;
  while(SDL_WaitEvent(&event) != 0) {
      switch(event.type) {
        case (SDL_QUIT):
          SDL_FreeSurface(image);
          goto jump;
      }
      //we handle only the one event
  }
  jump: SDL_Quit();
}
