/*
** walls.h for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 21:20:29 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 21:20:31 2018 HYVERNAUD Alexandre
*/

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
  SDL_Rect	*collision_box;
}		t_wall;

#endif		/* !_WALLS_H_ */
