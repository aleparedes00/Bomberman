/*
** my_strcpy.c for my_strcpy in /home/coquel-l/C/libmy
** 
** Made by Coquelet Loïc
** Login   <coquel_l@etna-alternance.net>
** 
** Started on  Sat Oct 21 15:09:02 2017 Coquelet Loïc
** Last update Sat Oct 21 15:09:09 2017 Coquelet Loïc
*/

char	*my_strcpy(char *dest, char *src)
{
  int i;
  i = 0;
  while (*src != '\0')
    {
      *dest = *src;
      src++;
      dest++;
      i++;
    }
  *dest = '\0';
  return (dest - i);
}
