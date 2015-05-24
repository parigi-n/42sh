/*
** hist.c for hist in /home/pellem_m/Rendu/PSU_2014_42sh/Jules/src/list
** 
** Made by Martin PELLEMOINE
** Login   <pellem_m@epitech.net>
** 
** Started on  Fri May 22 16:43:08 2015 Martin PELLEMOINE
** Last update Sun May 24 23:00:56 2015 Nicolas PARIGI
*/

#include "my.h"

void		free_hist(t_hist **hist)
{
  t_hist	*tmp;
  t_hist	*wait;

  my_putstr("Début de free, bellek frère...\n");
  tmp = *hist;
  wait = tmp;
  while (tmp != NULL)
    {
      my_putstr("On parcourt la liste jusqu'a la fin...\n");
      wait = tmp;
      tmp = tmp->next;
    }
  if (wait != NULL)
    {
      wait = NULL;
      my_putstr("Historique free frère #iZi\n");
    }
}

int		my_put_in_hist(t_hist **hist, char *cmd)
{
  t_hist	*tmp;
  static int	count = 0;

  if ((tmp = malloc(sizeof(*hist))) == NULL)
    return (ERROR);
  if ((tmp->str = my_strcpy(cmd)) == NULL)
    return (ERROR);
  count++;
  tmp->prev = NULL;
  tmp->nb = count;
  tmp->next = *hist;
  if (tmp->next != NULL)
    tmp->next->prev = tmp;
  *hist = tmp;
  return (SUCCESS);
}

void		my_show_hist(t_hist **hist_stock)
{
  t_hist	*tmp;

  tmp = *hist_stock;
  while (tmp != NULL)
    {
      my_putstr("\ntmp->str = ");
      my_putstr(tmp->str);
      my_printf("\n");
      my_printf("tmp->nb = %d\n", tmp->nb);
      if (tmp->prev != NULL)
	my_printf("tmp->prev->str%s", tmp->prev->str);
      tmp = tmp->next;
    }
}
