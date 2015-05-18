/*
** fct_prompt_misc.c for fctpromptmisc in /home/parigi_n/Testrendu/PSU_2014_42sh/Nico/mysh/src/prompt
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sat May 16 16:37:02 2015 Nicolas PARIGI
** Last update Sat May 16 16:37:03 2015 Nicolas PARIGI
*/

#include "my.h"

int		flag_backslash(t_stock **env)
{
  (void)env;
  my_putchar('\\');
  return (0);
}

int		flag_mod(t_stock **env)
{
  (void)env;
  my_putchar('%');
  return (0);
}

int		flag_hist(t_stock **env)
{
  (void)env;
  my_putchar('%');
  return (0);
}

int		flag_escape_open(t_stock **env)
{
  (void)env;
  return (1);
}

int		flag_escape_close(t_stock **env)
{
  (void)env;
  return (-1);
}
