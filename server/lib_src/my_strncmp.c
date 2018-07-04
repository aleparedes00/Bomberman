/*
** my_strncmp.c for my_strncmp in /home/coquel-l/C/libmy
** 
** Made by Coquelet Loïc
** Login   <coquel_l@etna-alternance.net>
** 
** Started on  Sat Oct 21 15:08:09 2017 Coquelet Loïc
** Last update Sat Oct 21 15:08:17 2017 Coquelet Loïc
*/

int		my_strncmp(char *s1, char *s2, int n)
{
  int i;
  i = 0;
  
  while ((*s1 || *s2) && i < n)
    {
      if (*s1 - *s2 < 0)
	return (-1);
      if (*s1 - *s2 > 0)
	return (1);
      s1++;
      s2++;
      i++;
    }
  return (0);
}
