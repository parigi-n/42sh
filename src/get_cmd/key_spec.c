/*
** fct_spec.c for fct_spec in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/pars
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Apr 30 12:11:26 2015 Jules Vautier
<<<<<<< HEAD
** Last update Sun May 24 23:01:25 2015 Nicolas PARIGI
=======
** Last update Sun May 24 22:57:26 2015 Jules Vautier
>>>>>>> 2f63a1805299513c507e2787d5c087b3f2ff6936
*/

#include "my.h"

int		end_get_cmd(t_struct *var)
{
<<<<<<< HEAD
=======
  (void)var;
>>>>>>> 2f63a1805299513c507e2787d5c087b3f2ff6936
  my_putchar('\n');
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
