/*
** main.c for main in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Jan 12 19:10:30 2015 Jules Vautier
** Last update Sun May 24 19:55:13 2015 Jules Vautier
*/

#include "my.h"

int		my_exit(t_struct *var, char **tab)
{
  if (my_tablen(tab) < 2 || ((var->ret = my_getnbr(tab[1])) == -1))
    var->ret = 0;
  free_list(&var->env);
  free_list(&var->alias);
  free_list_pars(&var->buffer);
  free(var->buff);
  free(var->term.prompt);
  my_putstr("exit\n");
  if (var->term.curse == 1)
    un_raw_mod();
  return (ERROR);
}
