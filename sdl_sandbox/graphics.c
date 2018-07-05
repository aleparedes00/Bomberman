#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	<graphics.h>

char		*digit_to_str(int i);

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
  if (loaded_image == NULL) printf("not found: %s\n", path);
  if (loaded_image)
  {
    optimized_image = SDL_DisplayFormat(loaded_image);
    SDL_FreeSurface(loaded_image);
  }
  return optimized_image;
}

char		*get_path(int player_number, int direction)
{
  char		*path;
  char		*prefix;
  char		*suffix;

  prefix = "img/spr_player";
  switch (direction)
  {
  case UP:
    suffix = "_up1.png";
    break;
  case DOWN:
    suffix = "_down1.png";
    break;
  case LEFT:
    suffix = "_left1.png";
    break;
  case RIGHT:
    suffix = "_right1.png";
    break;
  }
  path = malloc(strlen(prefix) + strlen(suffix) + 2);
  strcpy(path, prefix);
  strcat(path, digit_to_str(player_number + 1));
  strcat(path, suffix);
  return path;
}

int		load_media()
{
  int		i;

  for (i = 0; i < TOTAL_PLAYERS; i++)
  {
    g_character[i][UP] = load_image(get_path(i, UP));
    g_character[i][DOWN] = load_image(get_path(i, DOWN));
    g_character[i][LEFT] = load_image(get_path(i, LEFT));
    g_character[i][RIGHT] = load_image(get_path(i, RIGHT));
  }
  g_wall = load_image("img/spr_wall.png");
  g_brick = load_image("img/spr_brick.png");
  return 1;
}

void		apply(int x, int y, SDL_Surface *src, SDL_Surface *dst)
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, dst, &offset);
}
