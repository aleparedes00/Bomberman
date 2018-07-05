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
