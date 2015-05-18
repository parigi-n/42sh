/*
** ss.c for ss.c in /home/vautie_a/rendu/CPE_2014_Pushswap/push_swap_src
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Dec  8 11:30:18 2014 jules vautier
** Last update Thu May 14 16:07:16 2015 Jules Vautier
*/

#include "my.h"

void		free_list(t_stock **list)
{
  t_stock	*tmp;
  t_stock	*wait;

  tmp = *list;
  while (tmp != NULL)
    {
      wait = tmp->next;
      free(tmp->name);
      free(tmp->comment);
      free(tmp);
      tmp = wait;
    }
}

int		my_put_in_list_stock(t_stock **list,
				     char *name, char *comment)
{
  t_stock	*l_a;

  if ((l_a = malloc(sizeof(*l_a))) == NULL)
    return (ERROR);
  if ((l_a->name = my_strcpy(name)) == NULL)
    return (ERROR);
  if ((l_a->comment = my_strcpy(comment)) == NULL)
    return (ERROR);
  l_a->next = *list;
  *list = l_a;
  return (SUCCES);
}

void		my_show_list(t_stock *list)
{
  t_stock	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->name);
      my_putstr("=");
      my_putstr(tmp->comment);
      my_putchar('\n');
      tmp = tmp->next;
    }
}
