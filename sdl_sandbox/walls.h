#ifndef		_WALLS_H_
# define	_WALLS_H_

#include	<SDL/SDL.h>

typedef struct	s_wall
{
  int		x;
  int		y;
  int		breakable;
  int		visible;
  SDL_Surface	*sprite;
}		t_wall;

#endif		/* !_WALLS_H_ */
