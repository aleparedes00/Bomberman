/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/coquel-l/C/day07/my_str_to_wordtab
** 
** Made by Coquelet Loïc
** Login   <coquel_l@etna-alternance.net>
** 
** Started on  Mon Oct 23 15:12:45 2017 Coquelet Loïc
** Last update Tue Oct 24 13:31:47 2017 Coquelet Loïc
*/


#include <stdlib.h>

char		*my_strncpy(char *dest, char *src, int nb);

int		my_wordlen(char *str)
{
  int i;
  
  i = 0;
  while (((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')
	  || (*str >= '0' && *str <= '9')) && *str != '\0')
    {
      i++;
      str++;
    }
  return (i);
}

int		my_wordnb(char *str)
{
  int i;
  
  i = 0;
  while (*str != '\0')
    {
      if (my_wordlen(str) > 0)
	{
	  i++;
	  str += (my_wordlen(str));
	}
      else
	str++;
    }
  return (i);
}

char		**my_str_to_wordtab(char *str)
{
  char **tab;
  int i;
  int wordsize;
  int wordnb;
  
  i = 0;
  if (str == NULL)
    return (NULL);
  wordnb = my_wordnb(str);
  if ((tab = malloc(sizeof(char*) * (wordnb + 1))) == NULL)
    return (NULL);
  while (i < wordnb)
    {
      while (my_wordlen(str) == 0 && *str != '\0')
	str++;
      wordsize = my_wordlen(str);
      if ((tab[i] = malloc(sizeof(char) * (wordsize + 1))) == NULL)
	return (NULL);
      my_strncpy(tab[i], str, wordsize);
      tab[i][wordsize] = '\0';
      str = str + wordsize;
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
