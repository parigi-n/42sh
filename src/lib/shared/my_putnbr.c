/*
** my_putnbr.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun May 17 12:04:31 2015 david sebaoun
** Last update Sun May 24 17:43:29 2015 Nicolas PARIGI
*/

#include <stddef.h>
#include "shared.h"

int	my_putnbr(int nb)
{
  int	x;

  x = 1;
  if (nb < 0)
    {
      my_putchar((char)'-');
      nb = nb - (2 * nb);
    }
  while (nb / x > 9)
    x = x * 10;
  while (x > 0)
    {
      my_putchar((nb / x) % 10 + 48);
      x = x / 10;
    }
  return (SUCCESS);
}
