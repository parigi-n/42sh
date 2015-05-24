/*
** ss.c for ss.c in /home/vautie_a/rendu/CPE_2014_Pushswap/push_swap_src
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Dec  8 11:30:18 2014 jules vautier
** Last update Thu May 14 10:07:40 2015 Jules Vautier
*/

#include "my.h"

void		free_list_pars(t_buff **list)
{
  t_buff	*tmp;
  t_buff	*wait;

  tmp = *list;
  while (tmp != NULL)
    {
      wait = tmp->next;
      freetab(tmp->tab);
      free(tmp->buff);
      free(tmp);
      tmp = wait;
    }
}

void		my_show_list_pars(t_buff *list)
{
  t_buff	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_printf("str: %s\n", tmp->buff);
      tmp = tmp->next;
    }
}

int		my_put_in_list_pars(t_buff **list,
				    char *str, int type, char **tab)
{
  t_buff	*l_a;

  if ((l_a = malloc(sizeof(*l_a))) == NULL)
    return (ERROR);
  if ((l_a->buff = my_strcpy(str)) == NULL)
    return (ERROR);
  l_a->type = type;
  if ((l_a->tab = tabcpy(tab)) == NULL)
    return (ERROR);
  l_a->next = *list;
  *list = l_a;
  return (SUCCES);
}

t_buff		*reverse_list_pars(t_buff *buffer)
{
  t_buff	*tmp;
  t_buff	*new;

  tmp = buffer;
  (new) = NULL;
  if (tmp == NULL || tmp->next == NULL)
    return (buffer);
  while (tmp != NULL)
    {
      if (my_put_in_list_pars(&new, tmp->buff, tmp->type, tmp->tab) == -1)
	return (NULL);
      tmp = tmp->next;
    }
  free_list_pars(&buffer);
  return (new);
}
