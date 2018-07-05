/*
** initialize_level.h for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 21:19:30 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 21:19:32 2018 HYVERNAUD Alexandre
*/

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
  BRICK,
  BOMB,
  EMPTY
};

typedef struct	s_element
{
  int		x;
  int		y;
  enum type	type;
  union
  {
    t_character	*c;
    t_wall	*w;
    t_bomb	*b;
  }		u_elt;
}		t_element;

typedef struct	s_level
{
  t_element	***elements;
  SDL_Surface	*map;
}		t_level;

t_level		*g_level;

t_level		*generate_default_level();

#endif		/* !_LEVEL_H_ */
