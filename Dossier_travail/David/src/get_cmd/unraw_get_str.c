/*
** get_str.c for get_str.c in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Apr 28 17:24:31 2015 Jules Vautier
** Last update Fri May 22 10:14:18 2015 Jules Vautier
*/

#include "my.h"

int		my_get_next_str_unraw(t_struct *var)
{
  char		*wait;
  char		*tmp;

  var->buff = get_next_line(0);
  while (check_quote(var->buff) == ERROR)
    {
      if ((wait = get_next_line(0)) == NULL)
	return (-1);
      if ((tmp = my_strcat_separ(var->buff, wait, '\n')) == NULL)
	return (-1);
      free(var->buff);
      free(wait);
      if ((var->buff = my_strcpy(tmp)) == NULL)
	return (-1);
      free(tmp);
    }
  if (var->buff == NULL)
    return (ERROR);
  return (SUCCES);
}
