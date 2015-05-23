/*
** main.c for  in /home/vautie_a/rendu/PSU_2014_my_printf/printf
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Nov 10 15:56:47 2014 jules vautier
** Last update Fri May 15 11:03:08 2015 Jules Vautier
*/

#include "my.h"

static const	t_flag g_flag[] =
  {
    {&aff_print_c, 'c'},
    {&aff_print_s, 's'},
    {&aff_print_d, 'd'},
    {&aff_print_d, 'i'},
    {&aff_print_t, 't'},
    {NULL, '\0'}
  };

static t_counter	what_is_this_print(char *arg, t_counter counter, va_list ap)
{
  int			n;

  n = 0;
  while (g_flag[n].flag != '\0')
    {
      if (g_flag[n].flag == arg[counter.i])
	{
	  counter.len = g_flag[n].ptr(counter.len, ap);
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

int		my_printf(char *arg, ...)
{
  va_list	ap;
  t_counter	counter;

  counter.i = 0;
  counter.len = 0;
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
	  my_putchar(arg[counter.i]);
	  counter.len = counter.len + 1;
	}
      counter.i++;
    }
  va_end(ap);
  return (-1);
}
