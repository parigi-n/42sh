/*
** cd.c for cd in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Jan 23 12:09:15 2015 Jules Vautier
** Last update Sat May 23 10:20:46 2015 Jules Vautier
*/

#include "my.h"

static int	builtin_alias(t_struct *var, char **tab, int end)
{
  if (my_tablen(tab) == 3)
    end = add_list_stock(&var->alias, tab[1], tab[2]);
  else if (my_tablen(tab) == 1)
    {
      my_show_list(var->alias);
      end = 0;
    }
  return (end);
}

static int	builtin_env(t_struct *var, char **tab, int end)
{
  if (my_strncmp(tab[0], "unsetenv", 8)
	   == 0 && my_tablen(tab) == 2)
    end = erase_list(&var->env, tab[1]);
  else if (my_strncmp(tab[0], "setenv", 6) == 0 && my_tablen(tab) == 3)
    end = add_list_stock(&var->env, tab[1], tab[2]);
  return (end);
}

int		builtin_main(t_struct *var, char **tab)
{
  int		end;

  end = 1;
  if (my_strcmp(tab[0], "exit") == 0)
    exit(my_exit(var, tab));
  else if (my_strcmp(tab[0], "cd") == 0)
    end = my_cd(var, tab);
  else if (my_strcmp(tab[0], "alias") == 0)
    end = builtin_alias(var, tab, end);
  else
    end = builtin_env(var, tab, end);
  var->status = end;
  return (end);
}
