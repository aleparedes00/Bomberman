#include	<SDL/SDL.h>
#include	"graphics.h"
#include	"level.h"

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
    printf("wall: %d\n", elt->type);
    printf("w: %p\n", elt->w);
    elt->w = malloc(sizeof(t_wall));
    elt->w->x = x;
    elt->w->y = y;
    elt->w->sprite = g_wall;
    printf("w: %p\n", elt->w);
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    apply(elt->w->x, elt->w->y, elt->w->sprite, level->map);
    printf("applied\n");
    break;
  case BOMB:
    //apply(element->x, element->y, element->c->sprite, level->map);
    break;
  case EMPTY:
  default:
    printf("default: %d\n", elt->type);
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
      //lvl->elements[i][j]->x = i * 32;
      //printf("x: %d\n", lvl->elements[i][j]->x);
      //lvl->elements[i][j]->y = j * 32;
      //printf("x after y: %d\n", lvl->elements[i][j]->x);
      if (i == 0 || i == LEVEL_WIDTH - 1
	  || j == 0 || j == LEVEL_HEIGHT - 1
	  || (i % 2 == 0 && j % 2 == 0))
      {
	lvl->elements[i][j]->type = WALL;
	//lvl->elements[i][j]->w = malloc(sizeof(t_wall));
	//lvl->elements[i][j]->w->sprite = g_wall;
      } else
      {
	lvl->elements[i][j]->type = EMPTY;
      }
      if (lvl->elements[i][j]->type != EMPTY)
	{
	place_element(lvl, &(lvl->elements[i][j]), i * 32, j * 32);
	printf("w: %p\n", lvl->elements[i][j]->w);
	}
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
