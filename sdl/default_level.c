/*
** default_level.c for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 21:19:04 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 21:19:05 2018 HYVERNAUD Alexandre
*/

#include	"initialize_level.h"
#include	"graphics.h"

int		is_wall(int i, int j)
{
  return (i == 0 || i == LEVEL_WIDTH - 1
	  || j == 0 || j == LEVEL_HEIGHT - 1
	  || (i % 2 == 0 && j % 2 == 0));
}

int		is_brick(int i, int j)
{
  return ((i == 1 && ((j >= 3 && j <= 5) || (j >= 7 && j <= 9)))
	  || (i == 2 && j != 1 && j != 11)
	  || (i == 3 && j != 4)
	  || (i == 4 && j != 11)
	  || (i == 5)
	  || (i == 6)
	  || (i == 7 && (j == 2 || j == 4 || j == 6 || (j >= 8 && j <= 10)))
	  || (i == 8)
	  || (i == 9 && j != 8)
	  || (i == 10 && j != 1)
	  || (i == 11 && j != 4 && j != 8)
	  || (i == 12 && j != 1 && j != 11)
	  || (i == 13 && (j == 4 || j == 5 || j == 7 || j == 8)));

}

int		*get_starting_position()
{
  static int	coords[2];

  switch(g_player_number)
  {
  case 1:
  default:
    coords[0] = 1;
    coords[1] = 1;
    break;
  case 2:
    coords[0] = 13;
    coords[1] = 1;
    break;
  case 3:
    coords[0] = 1;
    coords[1] = 11;
    break;
  case 4:
    coords[0] = 13;
    coords[1] = 11;
    break;
  }
  return coords;
}

int		is_player_starting_position(int i, int j)
{
  int		*coords;

  coords = get_starting_position();
  return (i == coords[0] && j == coords[1]);
}

int		get_player_number_from_pos(int i, int j)
{
  if (i/32 == 1 && j/32 == 1)
    return 1;
  else if (i/32 == 13 && j/32 == 1)
    return 2;
  else if (i/32 == 1 && j/32 == 11)
    return 3;
  else
    return 4;
}
