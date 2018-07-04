/*
** my_strdup.c for my_strdup in /home/coquel-l/C/day07/my_strdup
** 
** Made by Coquelet Loïc
** Login   <coquel_l@etna-alternance.net>
** 
** Started on  Mon Oct 23 10:02:19 2017 Coquelet Loïc
** Last update Mon Oct 23 10:02:22 2017 Coquelet Loïc
*/

#include <stdlib.h>
int		my_strlen(char *str);
char	*strcpy(char *dest, char *src);

char	*my_strdup(char *str)
{
  int slen;
  char *dup;
  
  slen = my_strlen(str);
  if ((dup = malloc(sizeof(*dup) * (slen + 1))) == NULL)
    return (NULL);
  dup = strcpy(dup, str);
  return(dup);
}
