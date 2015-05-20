/*
** main.c for main in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Jan 12 19:10:30 2015 Jules Vautier
** Last update Wed May 13 11:48:03 2015 Jules Vautier
*/

#include "my.h"

int		my_exit(t_struct *var, char **tab)
{
  int		nb;

  free_list(&var->env);
  free_list(&var->alias);
  free_list_pars(&var->buffer);
  free(var->buff);
  my_putstr("Exit the minishell.\n");
  un_raw_mod();
  /*if (my_tablen(tab) > 1 && my_getnbr(tab[2]))
    return (nb);*/
  (void)nb;
  (void)tab;
  return (SUCCES);
}
