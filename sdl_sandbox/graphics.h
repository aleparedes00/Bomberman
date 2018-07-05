#ifndef		_GRAPHICS_H_
# define	_GRAPHICS_H_

#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>

#define		SCREEN_WIDTH 480
#define		SCREEN_HEIGHT 416
#define		SCREEN_BPP 32

enum		key
{
  DEFAULT,
  UP,
  DOWN,
  LEFT,
  RIGHT,
  TOTAL
};

SDL_Surface	*g_window;

SDL_Surface	*g_screen;

SDL_Surface	*g_background;

SDL_Surface	*g_key_surfaces[TOTAL];

SDL_Surface	*g_current_surface;

SDL_Surface	*g_wall;

SDL_Surface	*g_brick;

SDL_Surface	*g_bomb;

int		init();

int		load_media();

void		close();

SDL_Surface*	load_image(char *path);

void		apply(int x, int y, SDL_Surface *src, SDL_Surface *dst);

#endif		/* !_GRAPHICS_H_ */
