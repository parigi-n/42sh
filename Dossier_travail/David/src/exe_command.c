/*
** exe_command.c for exe_cmd in /home/vautie_a/rendu/PSU_2014_minishell1
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sat Jan 31 09:39:51 2015 Jules Vautier
** Last update Sun May 17 14:45:59 2015 david sebaoun
*/

#include "my.h"

static int	init_exe_cmd(t_struct *var, char **tab)
{
  var->check = 0;
  var->new = NULL;
  var->envi = NULL;
  var->alias = NULL;
  if ((var->envtab = do_tab_exec(&var->env)) == NULL)
    return (ERROR);
  if ((var->envi = do_env(&var->env)) == NULL)
    return (ERROR);
  if ((var->new = my_strcpy(tab[0])) == NULL)
    return (ERROR);
  return (SUCCES);
}

static int	do_exe_cmd(t_struct *var, int i, char **tab)
{
  char	*str;

  free(tab[0]);
  tab[0] = NULL;
  if ((str = my_strcat(var->new, "/")) == NULL)
    return (ERROR);
  if ((tab[0] = my_strcat(str, var->envi[i])) == NULL)
    return (ERROR);
  free(str);
  if (access(tab[0], X_OK) == 0)
    {
      var->check = 1;
      execve(tab[0], tab, var->envtab);
    }
  return (SUCCES);
}

int	exe_cmd(t_struct *var, char **tab)
{
  int	i;

  i = 0;
  if ((init_exe_cmd(var, tab)) == -1)
    exit(-1);
  if (access(tab[0], X_OK) == 0)
    {
      var->check = 1;
      execve(tab[0], tab, var->envtab);
    }
  while (var->envi[i] != NULL)
    {
      if (do_exe_cmd(var, i, tab) == -1)
	exit(2);
      i++;
    }
  exit(-1);
  return (ERROR);
}
