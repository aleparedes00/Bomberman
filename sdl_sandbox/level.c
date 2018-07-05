#include	<SDL/SDL.h>
#include	"graphics.h"
#include	"level.h"
#include	"default_level.h"

int		draw_level(t_level *level)
{
  return (level != NULL); //temp
}

void		place_element(t_level *level, t_element **element, int x, int y)
{
  t_element	*elt;

  elt = *element;
  switch(elt->type)
  {
  case CHARACTER:
    //apply(element->x, element->y, element->c->sprite, level->map);
    break;
  case WALL:
    elt->w = malloc(sizeof(t_wall));
    elt->w->x = x;
    elt->w->y = y;
    elt->w->breakable = 0;
    elt->w->sprite = g_wall;
    apply(elt->w->x, elt->w->y, elt->w->sprite, level->map);
    elt->w->visible = 1;
    break;
  case BRICK:
    elt->w = malloc(sizeof(t_wall));
    elt->w->x = x;
    elt->w->y = y;
    elt->w->breakable = 1;
    elt->w->sprite = g_brick;
    apply(elt->w->x, elt->w->y, elt->w->sprite, level->map);
    elt->w->visible = 1;
    break;
  case BOMB:
    //apply(element->x, element->y, element->c->sprite, level->map);
    break;
  case EMPTY:
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
      else
	lvl->elements[i][j]->type = EMPTY;
      place_element(lvl, &(lvl->elements[i][j]), i * 32, j * 32);
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
