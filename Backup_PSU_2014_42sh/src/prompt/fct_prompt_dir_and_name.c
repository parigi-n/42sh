/*
** fct_prompt_dir_and_name.c for fct_prompt_dir_name in /home/parigi_n/Testrendu/PSU_2014_42sh/Nico/mysh/src/prompt
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sat May 16 16:36:38 2015 Nicolas PARIGI
** Last update Sat May 16 16:36:40 2015 Nicolas PARIGI
*/

#include "my.h"

int		flag_name(t_stock **env)
{
  char		*str;

  str = my_getstock(env, "USER");
  if (str == NULL)
    {
      if ((str = my_getstock(env, "LOGNAME")) == NULL)
	return (0);
    }
  my_putstr(str);
  return (0);
}

int		flag_fullhost(t_stock **env)
{
  char		*str;

  str = my_getstock(env, "HOST");
  if (str == NULL)
    {
      if ((str = my_getstock(env, "HOSTNAME")) == NULL)
	return (0);
    }
  my_putstr(str);
  return (0);
}

int		flag_host(t_stock **env)
{
  char		*str;
  char		**tab;

  str = my_getstock(env, "HOST");
  if (str == NULL)
    {
      if ((str = my_getstock(env, "HOSTNAME")) == NULL)
	return (0);
    }
    if ((tab = my_word_to_tab_custom(str, '.')) == NULL)
      {
	return (0);
      }
    if (my_tablen(tab) < 1)
      {
	return (0);
      }
    my_putstr(tab[0]);
    return (0);
}

int		flag_current_dir(t_stock **env)
{
  char		*str;

  str = my_getstock(env, "PWD");
  if (str == NULL)
    {
      return (0);
    }
  my_putstr(str);
  return (0);
}

int		flag_current_dir_home(t_stock **env)
{
  char		*str;
  char		*pwd;
  char		*home;

  pwd = my_getstock(env, "PWD");
  home = my_getstock(env, "HOME");
  if (pwd == NULL || home == NULL)
    return (0);
  if ((str = pwd_home(my_strcpy(home), my_strcpy(pwd))) == NULL)
    return(0);
  my_putstr(str);
  free(str);
  return (0);
}
