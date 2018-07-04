/*
** my_putchar.c for my_putchar in /home/faly/documents/devc_jour1/langlo_f
** 
** Made by LANGLOIS Faly-Thomas
** Login   <langlo_f@etna-alternance.net>
** 
** Started on  Mon Oct 16 12:20:07 2017 LANGLOIS Faly-Thomas
** Last update Mon Oct 16 20:48:29 2017 LANGLOIS Faly-Thomas
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
