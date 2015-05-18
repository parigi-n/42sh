/*
** my_putchar.c for my_putchar in /home/vautie_a/bin/lib/lib03
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Nov 27 16:23:06 2014 Jules Vautier
** Last update Sun Feb  1 14:14:16 2015 Jules Vautier
*/

#include <unistd.h>
#include <stddef.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	x;

  if (str == NULL)
    return (0);
  x = 0;
  while (str[x] != '\0')
    x = x + 1;
  return (x);
}

void	 my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  /*if (str != NULL)
    write(1, str, my_strlen(str));*/
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

int		puterr(char *str)
{
  if (str)
    write(2, str, my_strlen(str));
  return (-1);
}

