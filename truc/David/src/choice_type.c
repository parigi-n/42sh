/*
** choice_type.c for choice_type in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sun Mar 15 17:10:25 2015 Jules Vautier
** Last update Sat May 16 11:19:03 2015 david sebaoun
*/

#include "my.h"

int	type_zero(t_struct *var, t_buff *cmd)
{
  exe_solo(var, cmd->tab);
  return (SUCCES);
}

int	type_write(t_struct *var, t_buff *cmd, t_buff *next, int type)
{
  if (next != NULL)
    my_write(var, next->tab, cmd->tab, type);
  else
    puterr(INVALID_DIR);
  return (SUCCES);
}

int	type_pipe(t_struct *var, t_buff *cmd, t_buff *next)
{
  if (next != NULL)
    fct_pipe(var, cmd);
  else
    puterr(INVALID_PIPE);
  return (SUCCES);
}
