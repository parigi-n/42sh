/*
** main.c for main in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Jan 12 19:10:30 2015 Jules Vautier
** Last update Wed May 20 16:24:21 2015 Jules Vautier
*/

#include "my.h"

int		my_exit(t_struct *var, char **tab)
{
  int		nb;

  nb = 0;
  if (my_tablen(tab) < 2 || ((nb = my_getnbr(tab[1])) == -1))
    nb = 0;
  free_list(&var->env);
  free_list(&var->alias);
  free_list_pars(&var->buffer);
  free(var->buff);
  my_putstr("exit\n");
  un_raw_mod();
  return (nb);
}
