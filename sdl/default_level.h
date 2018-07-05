/*
** default_level.h for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 21:19:18 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 21:19:19 2018 HYVERNAUD Alexandre
*/

#ifndef		_DEFAULT_LEVEL_H_
# define	_DEFAULT_LEVEL_H_

int		is_wall(int i, int j);

int		is_brick(int i, int j);

int		is_player_starting_position(int i, int j);

int		get_player_number_from_pos(int i, int j);

#endif		/* !_DEFAULT_LEVEL_H_ */
