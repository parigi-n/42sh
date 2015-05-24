/*
** get_str.c for get_str.c in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Apr 28 17:24:31 2015 Jules Vautier
** Last update Sun May 24 11:45:59 2015 Jules Vautier
*/

#include "my.h"

int		eff_line(char *str)
{
  int		i;

  i = my_strlen (str);
  my_putchar('\r');
  while (i > -10)
    {
      i--;
      my_putchar(' ');
    }
  my_putchar('\r');
  return (0);
}

int		aff_last_line(t_struct *var, char c)
{
  int		i;

  i = my_strlen (var->buff);
  while (i > 0 && var->buff[i] != '\n')
    i--;
  if (var->buff[i] == '\n')
    i++;
  while (var->buff[i] != '\0')
    write(1, &var->buff[i++], 1);
  while (i > var->term.i)
    {
      my_putstr(var->term.ret);
      i--;
    }
  if (c == '\n')
    my_putchar(c);
  else if (c == ERASE)
    my_putstr(" \b");
  return (0);
}
