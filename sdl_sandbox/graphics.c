#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	<graphics.h>

int		init()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return 0;
  g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
			    SDL_SWSURFACE);
  if (!g_screen)
    return 0;
  if(!load_media())
    return 0;
  SDL_WM_SetCaption("Bomberman", NULL);
  return 1;
}

SDL_Surface	*load_image(char *path)
{
  SDL_Surface	*loaded_image;
  SDL_Surface	*optimized_image;

  loaded_image = IMG_Load(path);
  if (loaded_image)
  {
    optimized_image = SDL_DisplayFormat(loaded_image);
    SDL_FreeSurface(loaded_image);
  }
  return optimized_image;
}

int		load_media()
{
  g_key_surfaces[DEFAULT] = load_image("../img/spr_player1_up1.png");
  g_key_surfaces[UP] = load_image("../img/spr_player1_up1.png");
  g_key_surfaces[DOWN] = load_image("../img/spr_player1_down1.png");
  g_key_surfaces[LEFT] = load_image("../img/spr_player1_left1.png");
  g_key_surfaces[RIGHT] = load_image("../img/spr_player1_right1.png");
  g_wall = load_image("img/spr_wall.png");
  g_brick = load_image("img/spr_brick.png");
  return (g_key_surfaces[DEFAULT] && g_key_surfaces[UP] && g_key_surfaces[DOWN]
	  && g_key_surfaces[LEFT] && g_key_surfaces[RIGHT] && g_wall
	  && g_brick);
}

void		apply(int x, int y, SDL_Surface *src, SDL_Surface *dst)
{
  printf("enter apply\n");
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, dst, &offset);
}
