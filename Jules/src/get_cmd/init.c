/*
** init.c for init in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/get_cmd
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu May 14 09:29:44 2015 Jules Vautier
** Last update Fri May 22 10:35:12 2015 Jules Vautier
*/

#include "my.h"

int		my_get_next_str(t_struct *var)
{
  int		ret;

  if ((my_getstock(&var->env, "TERM") != NULL)
      && var->term.curse == 1)
    ret = my_get_next_str_raw(var);
  else
    ret = my_get_next_str_unraw(var);
  return (ret);
}
