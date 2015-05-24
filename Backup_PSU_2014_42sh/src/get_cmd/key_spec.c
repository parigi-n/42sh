/*
** fct_spec.c for fct_spec in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/pars
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Apr 30 12:11:26 2015 Jules Vautier
** Last update Sun May 24 09:08:09 2015 Jules Vautier
*/

#include "my.h"

int		end_get_cmd(t_struct *var)
{
  /*if (my_put_in_hist(&var->term.hist, var->buff) == ERROR)
    return (ERROR);*/
  /*if (var->term.hist->nb == var->term.lim_hist)
    free_hist(&var->term.hist);*/
  return (2);
}

int		key_hook(t_struct *var, char *str)
{
  if (str[0] == 27 && str[1] == 91)
    {
      if (str[2] == 65)
	gere_up(var);
      else if (str[2] == 66)
	gere_down(var);
      else if (str[2] == 67)
	gere_right(var, str);
      else if (str[2] == 68)
	gere_left(var, str);
    }
  return (SUCCESS);
}
