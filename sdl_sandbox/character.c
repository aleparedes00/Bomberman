#include	<SDL/SDL.h>
#include	"character.h"
#include	"graphics.h"

void		move_character(int direction, t_character *character)
{
  switch (direction)
  {
  case UP:
    character->y -= 10 * character->speed;
    break;
  case DOWN:
    character->y += 10 * character->speed;
    break;
  case LEFT:
    character->x -= 10 * character->speed;
    break;
  case RIGHT:
    character->x += 10 * character->speed;
    break;
  default:
    break;
  }
  g_player->character->sprite = g_character[g_player_number][direction];
}

void		handle_player_input(SDL_Event e)
{
  switch (e.key.keysym.sym)
  {
  case SDLK_UP:
    move_character(UP, g_player->character);
    break;
  case SDLK_DOWN:
    move_character(DOWN, g_player->character);
    break;
  case SDLK_LEFT:
    move_character(LEFT, g_player->character);
    break;
  case SDLK_RIGHT:
    move_character(RIGHT, g_player->character);
    break;
  default:
    break;
  }
}
