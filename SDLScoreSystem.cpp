#include "SDL/SDL.h"
#include "SDL_ttf.h"
#include "SDLScoreSystem.h"
#include "Constants.h"
#include "OriginalNintendoScoring.h"

extern TTF_Font *font;

// Constructor
SDLScoreSystem::SDLScoreSystem(SDL_Surface *surface_in) {
  surface = surface_in;
  scoresystem = new OriginalNintendoScoring();
}

void SDLScoreSystem::add_lines_to_score(int level, int rows) {
  (void) scoresystem->add_lines_to_score(level, rows);
}

void SDLScoreSystem::set_current_score(int score) {
  scoresystem->set_current_score(score);
}

void SDLScoreSystem::add_to_current_score(int score) {
  scoresystem->add_to_current_score(score);
}

int SDLScoreSystem::get_current_score() {
  return(scoresystem->get_current_score());
}

/*
 * Writes the score to the scoring area.
 * It blanks out the score line, THEN it draws 
 * the message into the blacked out area.
 */
void SDLScoreSystem::write_score() {
    const int X_OFFSET = 17;
    const int Y_OFFSET = 5;
    Uint32 blackColor = SDL_MapRGB(surface->format, 0, 0, 0);
    SDL_Color textColor = {0, 255, 0};
    char s[20];

    sprintf(s, "Score: %10d", scoresystem->get_current_score());
    SDL_Surface *message = TTF_RenderText_Solid( font, s, textColor);

    // This is the entire blank area of the scoring line
    SDL_Rect status_line_offset;
    status_line_offset.x = X_OFFSET * GRID_SIZE;
    status_line_offset.y = Y_OFFSET * GRID_SIZE;
    status_line_offset.h = 1 * GRID_SIZE - 1;
    status_line_offset.w = 30 * GRID_SIZE - 1;

    // This is the area for the message
    SDL_Rect text_offset;
    text_offset.x = X_OFFSET * GRID_SIZE;
    text_offset.y = Y_OFFSET * GRID_SIZE;

    SDL_FillRect (surface, &status_line_offset, blackColor);
    SDL_BlitSurface (message, NULL, surface, &text_offset);
    SDL_FreeSurface(message);
}

