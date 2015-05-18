/*
** choice_type.c for choice_type in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sun Mar 15 17:10:25 2015 Jules Vautier
** Last update Sun Mar 15 17:38:35 2015 Jules Vautier
*/

#include "my.h"

t_buff	*type_zero(t_struct *var, t_buff *tmp)
{
  exe_solo(var, tmp->tab);
  tmp = tmp->next;
  return (tmp);
}

t_buff	*type_one(t_struct *var, t_buff *tmp, char **tab)
{
  if ((tmp = tmp->next) != NULL)
    {
      if (my_tablen(tmp->tab) != 1)
	puterr("Invalid redirection\n");
      my_write(var, tab, tmp->tab);
      tmp = tmp->next;
    }
  else
    puterr("Invalid redirection\n");
  return (tmp);
}

t_buff	*type_two(t_struct *var, t_buff *tmp, char **tab)
{
  if ((tmp = tmp->next) != NULL)
    {
      fct_pipe(var, tab, tmp->tab);
      tmp = tmp->next;
    }
  else
    puterr("Invalid pipe\n");
  return (tmp);
}
