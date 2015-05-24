/*
** my_fct.c for my_fct in /home/vautie_a/rendu/PSU_2014_my_printf/printf
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Nov 11 10:56:52 2014 jules vautier
** Last update Sun May 17 18:34:54 2015 Jules Vautier
*/

#include "my.h"

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

int	aff_print_t(int len, va_list ap)
{
  char	**tmp;

  tmp = va_arg(ap, char **);
  my_show_tab(tmp);
  return (len);
}

int	aff_print_d(int len, va_list ap)
{
  int	x;
  int	nb;

  nb = va_arg(ap, int);
  x = 1;
  my_putnbr(nb);
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
