/*
** my_putchar.c for my_putchar in /home/vautie_a/bin/lib/lib03
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Nov 27 16:23:06 2014 jules vautier
** Last update Mon May 11 16:11:14 2015 Jules Vautier
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	x;

  x = 0;
  while (str != NULL && str[x] != '\0')
    x++;
  return (x);
}

int	 my_putstr(char *str)
{
  if (str)
    write(1, str, my_strlen(str));
  return (0);
}

int	my_put_nbr(int nb)
{
  int	x;

  x = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb - (2 * nb);
    }
  while (nb / x > 9)
    x = x * 10;
  while (x > 0)
    {
      my_putchar((nb / x) % 10 + 48);
      x = x / 10;
    }
  return (0);
}
