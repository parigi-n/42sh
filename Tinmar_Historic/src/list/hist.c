/*
** hist.c for hist in /home/pellem_m/Rendu/PSU_2014_42sh/Jules/src/list
** 
** Made by Martin PELLEMOINE
** Login   <pellem_m@epitech.net>
** 
** Started on  Fri May 22 16:43:08 2015 Martin PELLEMOINE
** Last update Sun May 24 21:09:18 2015 Martin PELLEMOINE
*/

#include "my.h"

void		free_hist(t_hist **hist)
{
  t_hist	*tmp;

  tmp = *hist;
  while (tmp->next != NULL)
    tmp = tmp->next;
  if (tmp != NULL)
    {
      free(tmp->str);
      free(tmp);
      tmp = NULL;
    }
  *hist = tmp;
  my_show_list(tmp);
}

int		my_put_in_hist(t_hist **hist, char *cmd, int nb)
{
  t_hist	*tmp;

  if ((tmp = malloc(sizeof(t_hist))) == NULL)
    return (ERROR);
  if ((tmp->str = my_strcpy(cmd)) == NULL)
    return (ERROR);
  tmp->nb = nb;
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
      my_putstr("\ntmp->str = ");
      my_putstr(tmp->str);
      my_printf("\n");
      my_printf("tmp->nb = %d\n", tmp->nb);
      tmp = tmp->next;
    }
}

t_hist		my_find_in_hist(t_hist **hist_stock, int position)
{
  t_stock	*tmp;
  int		i;

  tmp = list;
  while (i < position)
    {
      tmp = tmp->next;
      i++;
    }
}
