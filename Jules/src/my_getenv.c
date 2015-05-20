/*
** my_getstock.c for my_getstock in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Mar  2 16:02:58 2015 Jules Vautier
** Last update Sun May 17 14:48:49 2015 david sebaoun
*/

#include "my.h"

char	*my_getstock(t_stock **list, char *str)
{
  t_stock	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->name != NULL && my_strcmp(tmp->name, str) == SUCCES)
	return (tmp->comment);
	tmp = tmp->next;
    }
  return (NULL);
}

char	*my_getstock_name(t_stock **list, char *str)
{
  t_stock	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->name != NULL && my_strcmp(tmp->name, str) == SUCCES)
	return (tmp->name);
      tmp = tmp->next;
    }
  return (NULL);
}
