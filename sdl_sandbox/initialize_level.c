/*
** initialize_level.c for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 19:40:08 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 20:37:43 2018 HYVERNAUD Alexandre
*/

#include	<SDL/SDL.h>
#include	"graphics.h"
#include	"initialize_level.h"
#include	"default_level.h"

void		place_player(t_element **element, int x, int y)
{
  t_element	*e;
  int		p_number;

  e = *element;
  p_number = get_player_number_from_pos(x, y);
  e->u_elt.c = malloc(sizeof(t_character));
  if (p_number == g_player_number)
    g_player->character = e->u_elt.c;
  g_characters[p_number - 1] = e->u_elt.c;
  e->u_elt.c->x = x;
  e->u_elt.c->y = y;
  e->u_elt.c->xvel = 0;
  e->u_elt.c->yvel = 0;
  e->u_elt.c->player_number = p_number;
  e->u_elt.c->bomb_power = 1;
  e->u_elt.c->speed = 1;
  e->u_elt.c->sprite = g_character[e->u_elt.c->player_number - 1][DOWN];
  e->u_elt.c->visible = 1;
}

void		place_wall(t_element **element, int x, int y)
{
  t_element	*e;

  e = *element;
  e->u_elt.w = malloc(sizeof(t_wall));
  e->u_elt.w->x = x;
  e->u_elt.w->y = y;
  switch(e->type)
  {
  case WALL:
  default:
    e->u_elt.w->breakable = 0;
    e->u_elt.w->sprite = g_wall;
    break;
  case BRICK:
    e->u_elt.w->breakable = 1;
    e->u_elt.w->sprite = g_brick;
    break;
  }
  e->u_elt.w->visible = 1;
}

void		place_element(t_element **element, int x, int y)
{
  t_element	*e;

  e = *element;
  switch(e->type)
  {
  case CHARACTER:
    place_player(element, x, y);
    break;
  case WALL:
  case BRICK:
    place_wall(element, x, y);
    break;
  default:
    break;
  }
}

void		load_default_elements(t_level *level)
{
  t_level	*lvl;
  int		i;
  int		j;

  lvl = level;
  for (i = 0; i < LEVEL_WIDTH; i++)
  {
    for (j = 0; j < LEVEL_HEIGHT; j++)
    {
      if (is_wall(i, j))
	lvl->elements[i][j]->type = WALL;
      else if (is_brick(i, j))
	lvl->elements[i][j]->type = BRICK;
      else if (is_player_starting_position(i, j))
	lvl->elements[i][j]->type = CHARACTER;
      else
	lvl->elements[i][j]->type = EMPTY;
      place_element(&(lvl->elements[i][j]), i * 32, j * 32);
    }
  }
}

t_level		*generate_default_level()
{
  t_level	*level;
  int		i;
  int		j;

  level = malloc(sizeof(t_level));
  level->map = load_image("img/background.png");
  level->elements = malloc(LEVEL_WIDTH * sizeof(t_element**));
  for (i = 0; i < LEVEL_WIDTH; i++)
  {
    level->elements[i] = malloc(LEVEL_HEIGHT * sizeof(t_element*));
    for (j = 0; j < LEVEL_HEIGHT; j++)
    {
      level->elements[i][j] = malloc(sizeof(t_element));
    }
  }
  load_default_elements(level);
  return level;
}
