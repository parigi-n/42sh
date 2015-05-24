/*
** alias.c for alias in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/builtin
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed May 13 11:36:37 2015 Jules Vautier
** Last update Wed May 13 11:56:22 2015 Jules Vautier
*/

#include "my.h"

int		builtin_alias(t_struct *var, char **tab, int end)
{
  my_show_tab(tab);
  if (my_tablen(tab) == 3)
    end = add_list_stock(&var->alias, tab[1], tab[2]);
  else if (my_tablen(tab) == 1)
    {
      my_show_list(var->alias);
      end = 0;
    }
  return (end);
}
