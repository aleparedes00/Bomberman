/*
** my_put_nbr.c for my_put_nbr in /home/coquel-l/C/libmy
** 
** Made by Coquelet Loïc
** Login   <coquel_l@etna-alternance.net>
** 
** Started on  Sat Oct 21 15:09:33 2017 Coquelet Loïc
** Last update Sat Oct 21 16:20:48 2017 Coquelet Loïc
*/

void	my_putchar(char c);

void	my_put_nbr(int n)
{
  int i;
  i = 0;
  
  if (n < 0)
    {
      my_putchar('-');
      if (n / 10 != 0)
	{
	  i = n / 10;
	  i = -i;
	  my_put_nbr(i);
	}
      n = n % 10;
      n = -n;
      my_putchar(n + '0');
    }
  else
    {
      if (n / 10 != 0)
	my_put_nbr(n / 10);
      my_putchar(n % 10 + '0');
    }
}
