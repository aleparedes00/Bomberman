#ifndef		_BOMB_H_
# define	_BOMB_H_

#include	<SDL/SDL.h>

typedef struct	s_bomb
{
  int		x;
  int		y;
  int		power;
  int		visible;
  SDL_Surface	*sprite;
  SDL_Rect	*collision_box;
}		t_bomb;

typedef struct	s_flame
{
  int		visible;
  SDL_Surface	*sprite;
  SDL_Rect	*collision_box;
}		t_flame;

#endif		/* !_BOMB_H_ */
