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
  if (chdir(str) == -1)
    {
      if ((access(str, F_OK)) == -1)
	return (my_printf("%s%s", str,
			     " : File doesn't exist.\n"));
      else
	return (my_printf("%s%s", str,
			     " : Is not a directory (chdir error).\n"));
    }
  return (SUCCES);
}

static char	*get_home(t_stock **env, char *raw_path)
{
  char		*path;
  char		*home;

  raw_path = decal(raw_path, 1);
  if ((home = my_getstock(env, "HOME")) == NULL)
    {
      puterr(ERROR_HOME);
      return (NULL);
    }
  if ((path = my_strcat(home, raw_path)) == NULL)
    {
      puterr(ERROR_MALLOC);
      return (NULL);
    }
  return (path);
}

int		my_cd(t_struct *var, char **tab)
{
  char		*path;

  if (my_tablen(tab) < 2)
    {
      if ((path = my_getstock(&var->env, "HOME")) != NULL)
	return (puterr(ERROR_HOME));
      return (do_cd(path));
    }
  else if (tab[1][0] == '~')
      if ((path = get_home(&var->env, tab[1])) == NULL)
	return (-1);
  else if ((my_strcmp(tab[1], "-") == 0))
    if ((path = my_getstock(&var->env, "OLDPWD")) == NULL)
      return (puterr("Error : No previous working directory found in env.\n"));
  if (path == NULL)
    return ("Error : Undefined error in CD.\n");
  if (do_cd(path) == -1)
    return(ERROR);
  return (SUCCES);
}
