/*
** mainprintf.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh/src/shared/printf
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Mon May  4 17:31:07 2015 david sebaoun
** Last update Mon May  4 17:35:09 2015 david sebaoun
*/

#include "printf.h"
#include "shared.h"

static const	t_flag g_flag[] =
  {
    {&aff_print_c, 'c'},
    {&aff_print_s, 's'},
    {&aff_print_d, 'd'},
    {&aff_print_d, 'i'},
    {&aff_print_mod, '%'},
    {NULL, '\0'}
  };

static t_counter	what_is_this_print
(char *arg, t_counter counter, va_list ap)
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

int		printf_error(char *arg, ...)
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
  return (counter.len);
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
