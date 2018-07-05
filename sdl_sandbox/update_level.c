/*
** update_level.c for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 19:40:24 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 20:40:15 2018 HYVERNAUD Alexandre
*/

#include	<SDL/SDL.h>
#include	"graphics.h"
#include	"initialize_level.h"

void		draw_characters()
{
  int		i;

  for (i = 0; i < TOTAL_PLAYERS; i++)
  {
    if (g_characters[i]->visible)
      apply(g_characters[i]->x, g_characters[i]->y,
	    g_characters[i]->sprite, g_level->map);
  }
}

void		draw_elements()
{
  int		i;
  int		j;

  for (i = 0; i < LEVEL_WIDTH; i++)
  {
    for (j = 0; j < LEVEL_HEIGHT; j++)
    {
      switch (g_level->elements[i][j]->type)
      {
      case WALL:
      case BRICK:
	if (g_level->elements[i][j]->u_elt.w->visible)
	  apply(g_level->elements[i][j]->u_elt.w->x,
		g_level->elements[i][j]->u_elt.w->y,
		g_level->elements[i][j]->u_elt.w->sprite,
		g_level->map);
	break;
      default:
	break;
      }
    }
  }
}

void		draw_level()
{
  SDL_FillRect(g_screen, NULL, SDL_MapRGB(g_screen->format, 255, 255, 255));
  g_level->map = load_image("img/background.png");
  draw_elements();
  draw_characters();
  apply(0, 0, g_level->map, g_screen);
}
