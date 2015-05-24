/*
** ss.c for ss.c in /home/vautie_a/rendu/CPE_2014_Pushswap/push_swap_src
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Dec  8 11:30:18 2014 jules vautier
** Last update Fri May 15 10:53:46 2015 Jules Vautier
*/

#include "my.h"

void		free_list_hist(t_stock **list)
{
  t_hist	*tmp;
  t_hist	*wait;

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

int		my_put_in_list_hist(t_hist **list,
				    char *str)
{
  static int	nb;
  t_hist	*l_a;

  if ((l_a = malloc(sizeof(*l_a))) == NULL)
    return (ERROR);
  if ((l_a->str = my_strcpy(str)) == NULL)
    return (ERROR);
  l_a->nb = nb;
  l_a->next = *list;
  *list = l_a;
  nb++;
  return (SUCCES);
}

void		my_show_list_hist(t_hist **list)
{
  t_hist	*tmp;

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
