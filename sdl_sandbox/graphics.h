/*
** graphics.h for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 20:10:17 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 20:33:00 2018 HYVERNAUD Alexandre
*/

#ifndef		_GRAPHICS_H_
# define	_GRAPHICS_H_

#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	"character.h"

#define		SCREEN_WIDTH 480
#define		SCREEN_HEIGHT 416
#define		SCREEN_BPP 32

#define		TOTAL_PLAYERS 1

enum		directions
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

int		g_player_number;

SDL_Surface	*g_window;

SDL_Surface	*g_screen;

SDL_Surface	*g_character[TOTAL_PLAYERS][4];

SDL_Surface	*g_wall;

SDL_Surface	*g_brick;

SDL_Surface	*g_bomb;

t_character	*g_characters[TOTAL_PLAYERS];

typedef struct	s_player
{
  t_character	*character;
}		t_player;

t_player	*g_player;

int		init();

int		load_media();

void		close();

SDL_Surface*	load_image(char *path);

void		apply(int x, int y, SDL_Surface *src, SDL_Surface *dst);

#endif		/* !_GRAPHICS_H_ */
