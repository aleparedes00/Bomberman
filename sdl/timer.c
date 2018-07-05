/*
** timer.c for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 19:24:51 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 19:25:21 2018 HYVERNAUD Alexandre
*/

#include	<SDL/SDL.h>
#include	"timer.h"

void		start_timer()
{
  g_timer_started = 1;
  g_timer_paused = 0;
  g_start_ticks = SDL_GetTicks();
}

void		stop_timer()
{
  g_timer_started = 0;
  g_timer_paused = 0;
}

void		pause_timer()
{
  if (g_timer_started && !g_timer_paused)
  {
    g_timer_paused = 1;
    g_paused_ticks = SDL_GetTicks() - g_start_ticks;
  }
}

void		unpause_timer()
{
  if (g_timer_paused)
  {
    g_timer_paused = 0;
    g_start_ticks = SDL_GetTicks() - g_paused_ticks;
  }
}

int		get_timer_ticks()
{
  if (g_timer_started)
  {
    if (g_timer_paused)
      return g_paused_ticks;
    else
      return SDL_GetTicks() - g_start_ticks;
  }
  return 0;
}
