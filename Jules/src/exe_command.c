/*
** exe_command.c for exe_cmd in /home/vautie_a/rendu/PSU_2014_minishell1
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sat Jan 31 09:39:51 2015 Jules Vautier
** Last update Sun May 24 20:49:16 2015 kevin ventalon
*/

#include "my.h"

char		**delete_redir(char **tab)
{
  int		i;
  char		**new_tab;

  i = 0;
  if ((new_tab = malloc(sizeof(char *) * (my_tablen(tab) + 1))) == NULL)
    return (NULL);
  while (tab[i] != NULL && tab[i][0] != '>' && tab[i][0] != '<' &&
	 tab[i][my_strlen(tab[i]) - 1] != '>' &&
	 tab[i][my_strlen(tab[i]) - 1] != '>')
    {
      new_tab[i] = my_strcpy(tab[i]);
      ++i;
    }
  new_tab[i] = NULL;
  return (new_tab);
}

static int	init_exe_cmd(t_struct *var, char **tab)
{
  var->exe.fdin = 0;
  var->exe.fdout = 1;
  var->check = 0;
  var->exe.tmp = NULL;
  var->exe.envi = NULL;
  if ((var->exe.envtab = do_tab_exec(&var->env)) == NULL)
    return (ERROR);
  if ((var->exe.envi = do_env(&var->env)) == NULL)
    return (ERROR);
  if ((var->exe.tmp = my_strcpy(tab[0])) == NULL)
    return (ERROR);
  if (redir(var, tab) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

static int	do_exe_cmd(t_struct *var, int i, char **tab)
{
  char		*str;

  free(tab[0]);
  tab[0] = NULL;
  if ((str = my_strcat(var->exe.tmp, "/")) == NULL)
    return (ERROR);
  if ((tab[0] = my_strcat(str, var->exe.envi[i])) == NULL)
    return (ERROR);
  free(str);
  if (access(tab[0], X_OK) == 0)
    {
      var->check = 1;
      return (SUCCESS);
    }
  return (ERROR);
}

int		exe_cmd(t_struct *var, char **tab)
{
  int		i;

  i = 0;
  if (builtin(var, tab) == SUCCESS)
    return (SUCCESS);
  if ((init_exe_cmd(var, tab)) == -1)
    return (ERROR);
  if (access(tab[0], X_OK) == 0)
    {
      var->check = 1;
      return (SUCCESS);
    }
  while (var->exe.envi[i] != NULL)
    {
      if (do_exe_cmd(var, i, tab) == 0)
	return (SUCCESS);
      i++;
    }
  return (puterr(INVALID_CMD));
}
