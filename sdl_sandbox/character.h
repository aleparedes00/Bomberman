#ifndef		_CHARACTER_H_
# define	_CHARACTER_H_

#include	<SDL/SDL.h>

typedef struct	s_character
{
  int		x;
  int		y;
  int		player_number;
  int		bomb_power;
  int		speed;
  int		visible;
  SDL_Surface	*sprite;
  SDL_Rect	*collision_box;
}		t_character;

void		handle_player_input(SDL_Event e, t_character *character);

#endif		/* !_CHARACTER_H_ */
