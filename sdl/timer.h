/*
** timer.h for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 21:19:43 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 21:19:45 2018 HYVERNAUD Alexandre
*/

#ifndef		_TIMER_H_
# define	_TIMER_H_

int		g_timer_started;

int		g_timer_paused;

int		g_start_ticks;

int		g_paused_ticks;

void		start_timer();

void		stop_timer();

void		pause_timer();

void		unpause_timer();

int		get_timer_ticks();

#endif		/* !_TIMER_H_ */
