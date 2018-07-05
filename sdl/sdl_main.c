/*
** sdl_main.c for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 19:26:18 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 20:35:45 2018 HYVERNAUD Alexandre
*/

#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	"graphics.h"
#include	"timer.h"
#include	"character.h"
#include	"initialize_level.h"
#include	"update_level.h"

int		init_map()
{
  g_level = generate_default_level();
  if (g_level == NULL)
    return 0;
  apply(0, 0, g_level->map, g_screen);
  if (SDL_Flip(g_screen) == -1)
    return 0;
  return 1;
}

int		main()
{
  int		quit;
  SDL_Event	e;

  g_player_number = 1;
  g_player = malloc(sizeof(t_player));
  if (!(init() && init_map()))
    return 1;
  quit = 0;
  while (!quit)
  {
    start_timer();
    while (SDL_PollEvent(&e) != 0)
    {
      handle_player_input(e);
      if (e.type == SDL_QUIT)
	quit = 1;
    }
    move_character(g_player->character);
    SDL_Flip(g_screen);
    if (get_timer_ticks() < 10000 / 60)
    {
      SDL_Delay((1000 / 60) - get_timer_ticks());
    }
    draw_level();
  }
  SDL_Quit();
  return 0;
}
