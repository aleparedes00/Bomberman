/*
** util.c for Bomberman in /home/darts
**
** Made by HYVERNAUD Alexandre
** Login   <hyvern_a@etna-alternance.net>
**
** Started on  Thu Jul  5 21:20:19 2018 HYVERNAUD Alexandre
** Last update Thu Jul  5 21:20:21 2018 HYVERNAUD Alexandre
*/

char		*digit_to_str(int i)
{
  static char	str[2];

  str[0] = '0' + i;
  return str;
}
