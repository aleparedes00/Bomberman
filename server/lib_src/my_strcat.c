/*
** my_strcat.c for my_strcat in /home/coquel-l/C/libmy
** 
** Made by Coquelet Loïc
** Login   <coquel_l@etna-alternance.net>
** 
** Started on  Sat Oct 21 15:09:18 2017 Coquelet Loïc
** Last update Sat Oct 21 15:09:21 2017 Coquelet Loïc
*/

char	*my_strcat(char *dest, char *src)
{
  int i;
  i = 0;
  while (*dest != '\0')
    {
      dest++;
      i++;
    }
  while (*src)
    {
      *dest = *src;
      dest++;
      src++;
      i++;
    }
  *dest = '\0';
  return (dest - i);
}
