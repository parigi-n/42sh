/*
** hist.c for hist in /home/pellem_m/Rendu/PSU_2014_42sh/Jules/src/list
** 
** Made by Martin PELLEMOINE
** Login   <pellem_m@epitech.net>
** 
** Started on  Fri May 22 16:43:08 2015 Martin PELLEMOINE
** Last update Sat May 23 11:43:07 2015 Martin PELLEMOINE
*/

#include "my.h"

void		free_hist(t_hist **hist)
{
  t_hist	*tmp;

  tmp = *hist;
  while (tmp != NULL)
    tmp = tmp->next;
  if (tmp->prev != NULL)
    {
      tmp = tmp->prev;
      free(tmp->str);
      tmp->nb--;
      *hist = tmp;
      my_putstr("Historique free frère #iZi\n");
    }
}

int		my_put_in_hist(t_hist **hist, char *cmd)
{
  t_hist	*tmp;

  if ((tmp = malloc(sizeof(*hist))) == NULL)
    return (ERROR);
  if ((tmp->str = my_strcpy(cmd)) == NULL)
    return (ERROR);
  tmp->next = *hist;
  *hist = tmp;
  return (SUCCES);
}

void		my_show_hist(t_hist **hist_stock)
{
  t_hist	*tmp;

  tmp = *hist_stock;
  while (tmp != NULL)
    {
      my_putstr("hist = ");
      my_putstr(tmp->str);
      printf("\n");
      printf("Nb = %d\n", tmp->nb);
      my_putchar('\n');
      tmp = tmp->next;
    }
}
