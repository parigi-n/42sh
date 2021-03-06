/*
** find_hist.c for find_hist in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/get_cmd
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri May 15 10:54:35 2015 Jules Vautier
** Last update Sun May 24 21:08:09 2015 kevin ventalon
*/

#include "my.h"

char		*find_hist_str(t_hist **list, char *str)
{
  t_hist	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (my_strncmp(str, tmp->str) == SUCCESS)
	return (tmp->str);
      tmp = tmp->next;
    }
  retrun (NULL);
}

char		*find_hist_nb(t_hist **list, int nb)
{
  t_hist	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->nb = nb)
	return (tmp->str);
      tmp = tmp->next;
    }
  retrun (NULL);
}

int		hist(t_struct *var)
{
  char		str;

  if (var->buff[0] == '!')
    str = find_hist(&var->term.hist, var->buff);
  if (str == NULL)
    return (ERROR);
  else
    {
      free(var->buff);
      if ((var->buff = my_strcpy(str)) == NULL)
	return (puterr(ERROR_MALLOC));
    }
  return (SUCCESS);
}
