/*
** cd.c for cd in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Jan 23 12:09:15 2015 Jules Vautier
** Last update Thu Mar 12 16:49:28 2015 Jules Vautier
*/

#include "my.h"

static	int	my_cd_home(t_struct *var)
{
  int	i;
  char	*home;
  char	*tmp;

  i = 0;
  if ((tmp = my_getenv(&var->list, "HOME=")) == NULL)
    return (puterr("Can't find HOME.\n"));
  if ((home = malloc(sizeof(char)
		     * (my_strlen(tmp) + 1))) == NULL)
    return (ERROR);
  while (tmp[i + 5] != '\0')
    {
      home[i] = tmp[i + 5];
      i++;
    }
  home[i] = '\0';
  if (chdir(home) == -1)
    return (puterr("Fail with chdir.\n"));
  free(home);
  return (SUCCES);
}

static	int	my_cd_old(t_struct *var)
{
  int	i;
  char	*home;
  char	*tmp;

  i = 0;
  if ((tmp = my_getenv(&var->list, "OLDPWD=")) == NULL)
    return (puterr("Can't find OLDPWD.\n"));
  if ((home = malloc(sizeof(char)
		     * (my_strlen(tmp) + 1))) == NULL)
    return (ERROR);
  while (tmp[i + 7] != '\0')
    {
      home[i] = tmp[i + 7];
      i++;
    }
  home[i] = '\0';
  if (chdir(home) == -1)
    return (puterr("Fail with chdir.\n"));
  free(home);
  return (SUCCES);
}

int	my_cd(t_struct *var, char **tab)
{
  if ((my_tablen(tab) < 2) || (my_strcmp(tab[1], "~") == 0))
    return (my_cd_home(var));
  else if ((my_strcmp(tab[1], "-") == 0))
    return (my_cd_old(var));
  else if (chdir(tab[1]) == -1)
    return (puterr("Fail with chdir.\n"));
  return (SUCCES);
}
