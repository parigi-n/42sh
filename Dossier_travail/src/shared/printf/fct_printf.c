/*
** fct_printf.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh/src/shared/printf
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Mon May  4 17:31:55 2015 david sebaoun
** Last update Mon May  4 17:32:01 2015 david sebaoun
*/

#include "shared.h"

int	aff_print_c(int len, va_list ap)
{
  my_putchar(va_arg(ap, int));
  return (len + 1);
}

int	aff_print_s(int len, va_list ap)
{
  char	*tmp;

  tmp = va_arg(ap, char *);
  my_putstr(tmp);
  len = len + my_strlen(tmp);
  return (len);
}

int	aff_print_d(int len, va_list ap)
{
  int	x;
  int	nb;

  nb = va_arg(ap, int);
  x = 1;
  my_put_nbr(nb);
  if (nb < 0)
    {
      nb = -nb;
      len = len + 1;
    }
  while (nb / x > 9)
    {
      x = x * 10;
      len = len + 1 ;
    }
  return (len + 1);
}

int	aff_print_mod(int len, va_list ap)
{
  (void)ap;
  my_putchar('%');
  return (len + 1);
}
