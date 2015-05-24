/*
** cd.c for cd new in /home/parigi_n/Testrendu/PSU_2014_42sh/Jules
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sun May 24 16:57:23 2015 Nicolas PARIGI
** Last update Sun May 24 16:57:26 2015 Nicolas PARIGI
*/

#include "my.h"

static int	do_cd(char *str, t_stock **env)
{
  char		*oldpwd;

  my_printf("on est dans cd: go -%s-\n", str);
  if (chdir(str) == -1)
    {
      if ((access(str, F_OK)) == -1)
	return (printf_err("%s%s", str,
			   " : File doesn't exist.\n"));
      else
	return (printf_err("%s%s", str,
			   " : Is not a directory (chdir error).\n"));
    }
  else
    {
      if ((oldpwd = my_getstock(env, "PWD")) != NULL)
	if ((add_list_stock(env, "OLDPWD", oldpwd)) == -1)
	  puterr(ERROR_MALLOC);
      if ((add_list_stock(env, "PWD", str)) == -1)
	puterr(ERROR_MALLOC);
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

  path = NULL;
  if (my_tablen(tab) == 1)
    {
      if ((path = my_getstock(&var->env, "HOME")) == NULL)
	return (puterr(ERROR_HOME));
    }
  else if (tab[1][0] == '~')
    {
      if ((path = get_home(&var->env, tab[1])) == NULL)
	return (-1);
    }
  else if (my_strcmp(tab[1], "-") == 0)
    {
      if ((path = my_getstock(&var->env, "OLDPWD")) == NULL)
	return (puterr(ERROR_NOPWD));
    }
  else if (my_tablen(tab) >= 2)
    path = tab[1];
  if (path == NULL)
    return (puterr(ERROR_CD));
  if (do_cd(path, &var->env) == -1)
    return (ERROR);
  return (SUCCES);
}
