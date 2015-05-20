/*
** my_fct.c for my_fct in /home/vautie_a/rendu/PSU_2014_my_printf/printf
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Nov 11 10:56:52 2014 jules vautier
** Last update Wed May 13 15:01:04 2015 Jules Vautier
*/

#include "my.h"

static const		t_flag g_flag[] =
  {
    {&aff_print_c, 'c'},
    {&aff_print_s, 's'},
    {&aff_print_d, 'd'},
    {&aff_print_d, 'i'},
    {NULL, '\0'}
  };

static int		aff_print_c_error(int len, va_list ap)
{
  char			tmp;

  tmp = (va_arg(ap, int));
  write(2, &tmp, 1);
  return (0);
}

static int		aff_print_s_error(int len, va_list ap)
{
  char			*tmp;

  tmp = va_arg(ap, char *);
  puterr(tmp);
  return (0);
}

static int		aff_print_d_error(int len, va_list ap)
{
  int			x;
  int			nb;
  char			tmp;

  nb = va_arg(ap, int);
  x = 1;
  if (nb < 0)
    {
      puterr("-");
      nb = nb - (2 * nb);
    }
  while (nb / x > 9)
    x = x * 10;
  while (x > 0)
    {
      tmp = ((nb / x) % 10 + 48);
      write(2, &tmp, 1);
      x = x / 10;
    }
  return (0);
}

static t_counter	what_is_this_print(char *arg, t_counter counter, va_list ap)
{
  int			n;

  n = 0;
  while (g_flag[n].flag != '\0')
    {
      if (g_flag[n].flag == arg[counter.i])
	{
	  g_flag[n].ptr(counter.len, ap);
	  return (counter);
	}
      n = n + 1;
    }
  if (arg[counter.i] != '\0')
    counter.i++;
  else
    counter.i--;
  return (counter);
}

int			printf_err(char *arg, ...)
{
  va_list		ap;
  t_counter		counter;
  char			tmp;

  counter.i = 0;
  va_start(ap, arg);
  while (arg[counter.i] != '\0')
    {
      if (arg[counter.i] == '%' && arg[counter.i + 1] != '\0')
	{
	  counter.i++;
	  while (arg[counter.i] == ' ' || arg[counter.i] == '-'
		 || arg[counter.i] == '+')
	    counter.i++;
	  counter = what_is_this_print(arg, counter, ap);
	}
      else if (arg[counter.i] != '%')
	{
	  tmp = arg[counter.i];
	  write(1, &tmp, 1);
	}
      counter.i++;
    }
  va_end(ap);
  return (-1);
}
