/*
** test.c for env in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb 26 17:20:30 2015 Jules Vautier
** Last update Sun Mar 15 14:39:14 2015 Jules Vautier
*/

#include "my.h"

int		erase_list(t_list **list, char *str)
{
  t_list	*tmp;
  t_list	*wait;

  wait = *list;
  tmp = wait->next;
  while (wait != NULL && my_strncmp(wait->str, str, my_strlen(str)) != 0)
    {
      wait = tmp;
      tmp = tmp->next;
    }
  if (tmp == NULL)
    {
      puterr("This element doesn't.\n");
      return (ERROR);
    }
  free(wait->str);
  free(wait);
  wait = tmp;
  *list = wait;
  return (SUCCES);
}

int		add_list_env(t_list **list, char *env, char *str)
{
  t_list	*tmp;
  char		*try;

  tmp = *list;
  while (tmp != NULL && my_strncmp(tmp->str, env, my_strlen(env)) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    {
      if ((try = my_strcat(str, env)) == NULL)
	return (ERROR);
      if (my_put_in_list_env(list, try) == -1)
	return (ERROR);
      free(try);
    }
  else
    {
      free(tmp->str);
      if ((try = my_strcat(str, env)) == NULL)
	return (ERROR);
      tmp->str = try;
    }
  return (SUCCES);
}

int		listlen(t_list **list)
{
  int		i;
  t_list	*tmp;

  tmp = *list;
  i = 0;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}

t_list		*reverse_list(t_list *list)
{
  t_list	*tmp;
  t_list	*new;

  tmp = list;
  (new) = NULL;
  while (tmp != NULL)
    {
      if (my_put_in_list_env(&new, tmp->str) == -1)
	return (NULL);
      tmp = tmp->next;
    }
  free_list(&list);
  return (new);
}
