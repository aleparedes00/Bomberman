/*
** my_strstr.c for my_strstr in /home/coquel-l/C/libmy
** 
** Made by Coquelet Loïc
** Login   <coquel_l@etna-alternance.net>
** 
** Started on  Sat Oct 21 15:07:36 2017 Coquelet Loïc
** Last update Sat Oct 21 15:29:42 2017 Coquelet Loïc
*/

char	*my_strstr(char *str, char *to_find)
{
  int i;
  int j;
  i = 0;
  j = 0;
  
  if (!*to_find)
    return (str);
  while (str[i] != '\0' && to_find[j] != '\0')
    {
      while (str[i + j] == to_find[j])
	{
	  j++;
	  if (to_find[j] == '\0')
	    return (str + i);
	}
      i++;
      j = 0;
    }
  return (0);
}
