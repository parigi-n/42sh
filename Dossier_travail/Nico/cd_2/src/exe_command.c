/*
** exe_command.c for exe_cmd in /home/vautie_a/rendu/PSU_2014_minishell1
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sat Jan 31 09:39:51 2015 Jules Vautier
** Last update Sat May 23 16:28:35 2015 Nicolas PARIGI
*/

#include "my.h"

static int	init_exe_cmd(t_struct *var, char **tab)
{
  var->check = 0;
  var->exe.tmp = NULL;
  var->exe.envi = NULL;
  if ((var->exe.envtab = do_tab_exec(&var->env)) == NULL)
    return (ERROR);
  if ((var->exe.envi = do_env(&var->env)) == NULL)
    return (ERROR);
  if ((var->exe.tmp = my_strcpy(tab[0])) == NULL)
    return (ERROR);
  return (SUCCES);
}

static int	do_exe_cmd(t_struct *var, int i, char **tab)
{
  char	*str;

  free(tab[0]);
  tab[0] = NULL;
  if ((str = my_strcat(var->exe.tmp, "/")) == NULL)
    return (ERROR);
  if ((tab[0] = my_strcat(str, var->exe.envi[i])) == NULL)
    return (ERROR);
  free(str);
  if (access(tab[0], X_OK) == 0)
    {
      my_putstr("SALUT\n");
      un_raw_mod();
      var->check = 1;
      execve(tab[0], tab, var->exe.envtab);
    }
  return (SUCCES);
}

int	exe_cmd(t_struct *var, char **tab)
{
  int	i;

  i = 0;
  if (builtin(var, tab) == SUCCES)
    exit(0);
  if ((init_exe_cmd(var, tab)) == -1)
    exit(-1);
  if (access(tab[0], X_OK) == 0)
    {
      var->check = 1;
      execve(tab[0], tab, var->exe.envtab);
    }
  while (var->exe.envi[i] != NULL)
    {
      if (do_exe_cmd(var, i, tab) == -1)
	exit(2);
      i++;
    }
  exit(-1);
  return (ERROR);
}
