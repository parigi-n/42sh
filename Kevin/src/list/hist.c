/*
** hist.c for hist in /home/pellem_m/Rendu/PSU_2014_42sh/Jules/src/list
** 
** Made by Martin PELLEMOINE
** Login   <pellem_m@epitech.net>
** 
** Started on  Fri May 22 16:43:08 2015 Martin PELLEMOINE
** Last update Sun May 24 17:08:44 2015 kevin ventalon
*/

#include "my.h"

void		free_hist(t_hist **hist)
{
  t_hist	*tmp;
  t_hist	*wait;

  tmp = *hist;
  wait = tmp->next;
  while (tmp != NULL)
    {
      while (tmp != NULL)
	{
	  my_putstr("On parcourt la liste jusqu'a la fin...\n");
	  wait = tmp;
	  tmp = tmp->next;
	}
      if (wait != NULL)
	{
	  free(tmp);
	  wait = NULL;
	}
  my_printf("Je free ou pas fdp?\n");
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
  tmp->nb = count;
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
      my_printf("tmp->nb = %d\n", tmp->nb);
      tmp = tmp->next;
    }
}
