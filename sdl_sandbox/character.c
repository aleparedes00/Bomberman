#include	<SDL/SDL.h>
#include	"character.h"
#include	"graphics.h"

void		move_character(t_character *character)
{
  character->x += character->xvel;
  character->y += character->yvel;
}

void		handle_player_input(SDL_Event e)
{
  if (e.type == SDL_KEYDOWN)
  {
    switch (e.key.keysym.sym)
    {
    case SDLK_UP:
      g_player->character->sprite = g_character[g_player_number - 1][UP];
      g_player->character->yvel -= 8; break;
    case SDLK_DOWN:
      g_player->character->sprite = g_character[g_player_number - 1][DOWN];
      g_player->character->yvel += 8; break;
    case SDLK_LEFT:
      g_player->character->sprite = g_character[g_player_number - 1][LEFT];
      g_player->character->xvel -= 8; break;
    case SDLK_RIGHT:
      g_player->character->sprite = g_character[g_player_number - 1][RIGHT];
      g_player->character->xvel += 8; break;
    default: break;
    }
  }
  else if (e.type == SDL_KEYUP)
  {
    switch (e.key.keysym.sym)
    {
    case SDLK_UP: g_player->character->yvel += 8; break;
    case SDLK_DOWN: g_player->character->yvel -= 8; break;
    case SDLK_LEFT: g_player->character->xvel += 8; break;
    case SDLK_RIGHT: g_player->character->xvel -= 8; break;
    default: break;
    }
  }
}
