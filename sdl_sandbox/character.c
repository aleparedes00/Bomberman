#include	<SDL/SDL.h>
#include	"character.h"
#include	"graphics.h"

void		move_character(enum key direction, t_character *character)
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
  g_current_surface = g_key_surfaces[direction];
}

void		handle_player_input(SDL_Event e, t_character *character)
{
  switch (e.key.keysym.sym)
  {
  case SDLK_UP:
    move_character(UP, character);
    break;
  case SDLK_DOWN:
    move_character(DOWN, character);
    break;
  case SDLK_LEFT:
    move_character(LEFT, character);
    break;
  case SDLK_RIGHT:
    move_character(RIGHT, character);
    break;
  default:
    break;
  }
}
