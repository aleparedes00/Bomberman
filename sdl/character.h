/*
** character.h for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 21:18:46 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 21:18:48 2018 HYVERNAUD Alexandre
*/

#ifndef		_CHARACTER_H_
# define	_CHARACTER_H_

#include	<SDL/SDL.h>

typedef struct	s_character
{
  int		x;
  int		y;
  int		xvel;
  int		yvel;
  int		player_number;
  int		bomb_power;
  int		speed;
  int		visible;
  SDL_Surface	*sprite;
  SDL_Rect	*collision_box;
}		t_character;

void		handle_player_input(SDL_Event e);

void		move_character(t_character *character);

#endif		/* !_CHARACTER_H_ */
