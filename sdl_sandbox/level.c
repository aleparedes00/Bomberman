#include	<SDL/SDL.h>
#include	"graphics.h"
#include	"level.h"

int		draw_level(t_level *level)
{
  return (level != NULL);
}

void		place_element(t_level *level, t_element *element)
{
  switch(element->type)
  {
  case CHARACTER:
    //apply(element->x, element->y, element->c->sprite, level->map);
    break;
  case WALL:
    printf("wall: %d\n", element->type);
    printf("w defined: %d\n", (element->w != NULL));
    //printf("w->x defined: %d\n", (element->w->x != NULL));
    //printf("w->y defined: %d\n", (element->w->y != NULL));
    //printf("w->sprite defined: %d\n", (element->w->sprite != NULL));
    printf("level->map defined: %d\n", (level->map != NULL));
    apply(element->w->x, element->w->y, g_wall, level->map);
    printf("applied");
    break;
  case BOMB:
    //apply(element->x, element->y, element->c->sprite, level->map);
    break;
  case EMPTY:
  default:
    printf("default: %d\n", element->type);
    break;
  }
}

void		load_default_elements(t_level *level)
{
  int		i;
  int		j;

  for (i = 0; i < LEVEL_WIDTH; i++)
  {
    for (j = 0; j < LEVEL_HEIGHT; j++)
    {
      if (i == 0 || i == LEVEL_WIDTH - 1
	  || j == 0 || j == LEVEL_HEIGHT - 1
	  || (i % 2 == 0 && j % 2 == 0))
      {
	//printf("type set to wall: %d\n", WALL);
	//printf("type check: %d\n", level->elements[i][j]->type);
	level->elements[i][j]->w = malloc(sizeof(t_wall));
	//printf("type check: %d\n", level->elements[i][j]->type);
	printf("g_wall is defined: %d\n", (g_wall != NULL));
	level->elements[i][j]->w->sprite = g_wall;
	printf("w->sprite is defined: %d\n", (level->elements[i][j]->w->sprite != NULL));
	level->elements[i][j]->w->x = i * 32;
	level->elements[i][j]->w->y = j * 32;
	level->elements[i][j]->type = WALL;
	printf("type check: %d\n", level->elements[i][j]->type);
      } else
	{
	  printf("set to default, ");
	level->elements[i][j]->type = EMPTY;
	printf("default successful, ");
	}
      if (level->elements[i][j]->type != EMPTY)
	place_element(level, level->elements[i][j]);
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
