/*
** cd.c for cd in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Jan 23 12:09:15 2015 Jules Vautier
** Last update Wed May 20 19:28:18 2015 Jules Vautier
*/

#include "my.h"

static int	do_cd(char *str)
{
  if (chdir(tab[1]) == -1)
    {
      if ((access(tab[1], F_OK)) == -1)
	return (printf_error("%s%s", tab[1],
			     " : File doesn't exist.\n"));
      else
	return (printf_error("%s%s", tab[1],
			     " : Is not a directory (chdir error).\n"));
    }
  return (SUCCES);
}

static char	*get_home(char *old)
{
  char		*env;

  tab[1][0] = decal(tab[1][0], 1);
  if ((env = my_getstock(&var->env, "HOME")) != NULL)
    return (puterr(ERROR_HOME));
  if ((env = my_strcat(tab[1], env)) == NULL)
    return (puterr(ERROR_MALLOC));
  return (SUCCES);
}

int		my_cd(t_struct *var, char **tab)
{

  if (my_tablen(tab) < 2)
    {
      if ((env = my_getstock(&var->env, "HOME")) != NULL)
	return (puterr(ERROR_HOME));
      return (do_cd(env));
    }
  else if (tab[1][0] == '~')
    {
      if (get_home(
    }
  else if ((my_strcmp(tab[1], "-") == 0))
    env = my_getstock(&var->env, "OLDPWD"));
  return (SUCCES);
}
