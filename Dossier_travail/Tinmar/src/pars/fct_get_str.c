/*
** get_str.c for get_str.c in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Apr 28 17:24:31 2015 Jules Vautier
** Last update Thu Apr 30 18:21:38 2015 Martin PELLEMOINE
*/

#include "my.h"

int		eff_line(char *str)
{
  int		i;

  i = my_strlen(str);
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

  my_prompt(&var);
  /* my_printf("\r\033[1;36m%s \033[0m", ">$"); */
  i = my_strlen(var->buff);
  while (i > 0 && var->buff[i] != '\n')
    i--;
  if (var->buff[i] == '\n')
    i++;
  while (var->buff[i] != '\0')
    write(1, &var->buff[i++], 1);
  if (c == '\n')
    my_putchar(c);
  else if (c == ERASE)
    my_putstr(" \b");
  return (0);
}