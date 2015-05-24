/*
** cd.c for cd in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Jan 23 12:09:15 2015 Jules Vautier
** Last update Sun May 17 15:46:52 2015 Jules Vautier
*/

#include "my.h"

static	int	my_cd_home(t_struct *var)
{
  int		i;
  char	*home;
  char	*tmp;

  i = 0;
  if ((tmp = my_getstock(&var->env, "HOME")) == NULL)
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
    {
      if ((access(home, F_OK)) == -1)
	return (puterr("HOME directory doesn't exist (access and chdir error).\n"));
      else
	return (puterr("HOME is not a directory (chdir error).\n"));
    }
  free(home);
  return (SUCCES);
}

static int	my_cd_old(t_struct *var)
{
  int	i;
  char	*home;
  char	*tmp;

  i = 0;
  if ((tmp = my_getstock(&var->env, "OLDPWD=")) == NULL)
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

int		my_cd(t_struct *var, char **tab)
{
  if ((my_tablen(tab) < 2) || (my_strcmp(tab[1], "~") == 0))
    return (my_cd_home(var));
  else if ((my_strcmp(tab[1], (char *)"-") == 0))
    return (my_cd_old(var));
  else if (chdir((char *)tab[1]) == -1)
    {
      /*if ((access(tab[1], F_OK)) == -1)
	return (printf_error("%s%s", tab[1], " : File doesn't exist.\n"));
      else
	return (printf_error("%s%s",
	tab[1], " : Is not a directory (chdir error).\n"));*/
      /*NEED PRINTF*/
    }
  return (SUCCES);
}
