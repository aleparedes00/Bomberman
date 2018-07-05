#ifndef		_LEVEL_H_
# define	_LEVEL_H_

#include	<SDL/SDL.h>
#include	"character.h"
#include	"walls.h"
#include	"bomb.h"

#define		LEVEL_WIDTH 15
#define		LEVEL_HEIGHT 13

enum		type
{
  CHARACTER,
  WALL,
  BOMB,
  EMPTY
};

typedef union	u_element
{
  int		x;
  int		y;
  enum type	type;
  t_character	*c;
  t_wall	*w;
  t_bomb	*b;
}		t_element;

typedef struct	s_level
{
  t_element	***elements;
  SDL_Surface	*map;
}		t_level;

t_level		*g_level;

t_level		*generate_default_level();

#endif		/* !_LEVEL_H_ */
