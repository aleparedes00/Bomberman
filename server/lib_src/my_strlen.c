/*
** my_strlen.c for my_strlen in /home/coquel-l/C/libmy
** 
** Made by Coquelet Loïc
** Login   <coquel_l@etna-alternance.net>
** 
** Started on  Sat Oct 21 15:08:31 2017 Coquelet Loïc
** Last update Sat Oct 21 15:08:35 2017 Coquelet Loïc
*/

int		my_strlen(char *str)
{
  int i = 0;
  
  while (str[i] != '\0')
    i++;
  return (i);
}
