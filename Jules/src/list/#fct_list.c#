/*
** test.c for env in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb 26 17:20:30 2015 Jules Vautier
** Last update Sat May 23 10:19:48 2015 Jules Vautier
*/

#include "my.h"

int		erase_list(t_stock **list, char *str)
{
  t_stock	*tmp;
  t_stock	*wait;

  wait = *list;
  tmp = wait->next;
  while (wait != NULL && my_strcmp(wait->name, str) != 0)
    {
      wait = tmp;
      tmp = tmp->next;
    }
  if (tmp == NULL)
    return (ERROR);
  free(wait->name);
  free(wait->comment);
  free(wait);
  wait = tmp;
  *list = wait;
  return (SUCCESS);
}

int		add_list_stock(t_stock **list, char *name, char *comment)
{
  t_stock	*tmp;

  if ((tmp = my_getstock_list(list, name)) == NULL)
    {
      if (my_put_in_list_stock(list, name, comment) == -1)
	return (-1);
    }
  else
    {
      free(tmp->comment);
      if ((tmp->comment = my_strcpy(comment)) == NULL)
	return (-1);
    }
  return (SUCCESS);
}

int		listlen(t_stock **list)
{
  int		i;
  t_stock	*tmp;

  tmp = *list;
  i = 0;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}

t_stock		*reverse_list(t_stock *list)
{
  t_stock	*tmp;
  t_stock	*new;

  tmp = list;
  new = NULL;
  while (tmp != NULL)
    {
      if (my_put_in_list_stock(&new, tmp->name,
			       tmp->comment) == -1)
	return (NULL);
      tmp = tmp->next;
    }
  free_list(&list);
  return (new);
}
