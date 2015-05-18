/*
** my_put_nbr.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh/src/shared
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Mon May  4 17:23:08 2015 david sebaoun
** Last update Mon May  4 17:23:31 2015 david sebaoun
*/

#include "shared.h"

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
