/*
** bomb.h for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 21:18:16 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 21:18:19 2018 HYVERNAUD Alexandre
*/

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
