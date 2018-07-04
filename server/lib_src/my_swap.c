/*
** my_swap.c for my_swap in /home/coquel-l/C/libmy
** 
** Made by Coquelet Loïc
** Login   <coquel_l@etna-alternance.net>
** 
** Started on  Sat Oct 21 15:05:59 2017 Coquelet Loïc
** Last update Sat Oct 21 15:07:44 2017 Coquelet Loïc
*/

void	my_swap(int *a, int *b)
{
  int c;
  
  c = *b;
  *b = *a;
  *a = c;
}
