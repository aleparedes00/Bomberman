#include	"level.h"

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
