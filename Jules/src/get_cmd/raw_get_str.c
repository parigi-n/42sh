/*
** get_str.c for get_str.c in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Apr 28 17:24:31 2015 Jules Vautier
** Last update Sun May 24 18:04:36 2015 Nicolas PARIGI
*/

#include "my.h"

static int	init(t_struct *var)
{
  if (raw_mode(&var->env) == ERROR)
    return (ERROR);
  if ((var->buff = malloc(1)) == NULL)
    return (ERROR);
  var->buff[0] = '\0';
  var->term.i = 0;
  var->term.pos = 0;
  my_prompt(var->term.prompt, &var->env);
  return (SUCCES);
}

static int	solo_char(t_struct *var, char c)
{
  static int	check = 0;
  int		len;

  if (c == '\n' && (check % 2) == 0)
    return (end_get_cmd(var));
  if (c <= 31 || c == ERASE)
    gere_key_control(var, c);
  else
    {
      if ((var->buff = add_char(var->buff, var->term.i, c)) == NULL)
	return (ERROR);
      var->term.i++;
    }
  eff_line(var->buff);
  my_prompt(var->term.prompt, &var->env);
  aff_last_line(var, c);
  return (SUCCES);
}

int		my_get_next_str_raw(t_struct *var)
{
  char		buff[4];
  int		len;

  if (init(var) == ERROR)
    return (ERROR);
  while ((len = read(0, buff, 3)) > 0)
    {
      buff[len] = '\0';
      if (len == 1)
	{
	  if (solo_char(var, buff[0]) == 2)
	    return (un_raw_mod());
	}
      else if (len == 3)
	{
	  key_hook(var, buff);
	}
    }
  return (puterr(INVALID_READ));
}
