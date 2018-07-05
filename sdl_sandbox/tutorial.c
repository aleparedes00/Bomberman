#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	"graphics.h"
#include	"character.h"
#include	"level.h"

int		init_map()
{
  g_level = generate_default_level();
  if (g_level == NULL)
    return 0;
  apply(0, 0, g_level->map, g_screen);
  g_current_surface = g_key_surfaces[DEFAULT];
  apply(180, 140, g_current_surface, g_screen);
  if (SDL_Flip(g_screen) == -1)
    return 0;
  return 1;
}

int		main()
{
  int		quit;
  t_character	*character;
  SDL_Event	e;

  if (!(init() && init_map()))
    return 1;
  quit = 0;
  character = malloc(sizeof(*character));
  character->x = 180;
  character->y = 140;
  character->speed = 1;
  while (!quit)
  {
    while (SDL_PollEvent(&e) != 0)
    {
      if (e.type == SDL_QUIT)
	quit = 1;
      else if (e.type == SDL_KEYDOWN)
	handle_player_input(e, character);
      apply(character->x, character->y, g_current_surface, g_screen);
      SDL_Flip(g_screen);
    }
  }
  free(g_level);
  SDL_FreeSurface(g_current_surface);
  SDL_FreeSurface(g_background);
  SDL_Quit();
  return 0;
}
