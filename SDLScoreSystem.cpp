#include "SDL/SDL.h"
#include "SDL_ttf.h"
#include "SDLScoreSystem.h"
#include "Constants.h"
#include "OriginalNintendoScoring.h"

// Constructor
SDLScoreSystem::SDLScoreSystem(SDL_Surface *surface_in, TTF_Font *font_in) {
  surface = surface_in;
  font = font_in;
  scoresystem = new OriginalNintendoScoring();
}

void SDLScoreSystem::add_lines_to_score(int rows) {
  (void) scoresystem->add_lines_to_score(rows);
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

void SDLScoreSystem::write_score_to_file() {
  scoresystem->write_score_to_file();
}

int SDLScoreSystem::get_level() {
  return(scoresystem->get_level());
}

void SDLScoreSystem::increment_level() {
  scoresystem->increment_level();
}

/*
 * Writes the Game Over message.
 */
void SDLScoreSystem::write_gameover() {
    const int X_OFFSET = 13;
    const int Y_OFFSET = 7;
    Uint32 blackColor = SDL_MapRGB(surface->format, 0, 0, 0);
    SDL_Color textColor = {250, 0, 0};
    char s[40];

    sprintf(s, "Game Over! (q = quit; n = start new)");
    SDL_Surface *message = TTF_RenderText_Solid( font, s, textColor);

    // This is the entire blank area of the level line
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

/*
 * Writes the level to the level display area.
 * It blanks out the line, THEN it draws 
 * the message into the blacked out area.
 */
void SDLScoreSystem::write_level() {
    const int X_OFFSET = 17;
    const int Y_OFFSET = 6;
    Uint32 blackColor = SDL_MapRGB(surface->format, 0, 0, 0);
    SDL_Color textColor = {0, 255, 0};
    char s[20];

    if (get_level() > 999999)
      sprintf(s, "Level: Past million!");
    else 
      sprintf(s, "Level: %11d", get_level()); 
    SDL_Surface *message = TTF_RenderText_Solid( font, s, textColor);

    // This is the entire blank area of the level line
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

