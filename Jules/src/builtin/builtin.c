/*
** cd.c for cd in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Jan 23 12:09:15 2015 Jules Vautier
** Last update Sun May 24 17:18:15 2015 Jules Vautier
*/

#include "my.h"

static int	echo(char **tab)
{
  if (tab[1] != NULL)
    my_putstr(tab[1]);
  my_printf("\n");
  return (SUCCES);
}

static int	builtin_alias(t_struct *var, char **tab, int end)
{
  end = -1;
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
  if (my_strcmp(tab[0], "env") == 0
      || my_strncmp(tab[0], "env ", 4) == 0)
    {
      my_show_list(var->env);
      end = 0;
    }
  else if (my_strncmp(tab[0], "unsetenv", 8) == 0)
    {
      if (my_tablen(tab) != 2)
	end = -1;
      else
	end = erase_list(&var->env, tab[1]);
    }
  else if (my_strncmp(tab[0], "setenv", 6) == 0)
    {
      if (my_tablen(tab) != 3)
	end = -1;
      else
	end = add_list_stock(&var->env, tab[1], tab[2]);
    }
  return (end);
}

int		builtin(t_struct *var, char **tab)
{
  int		end;

  end = 1;
  if (my_strcmp(tab[0], "exit") == 0)
    exit(my_exit(var, tab));
  else if (my_strcmp(tab[0], "cd") == 0)
    end = my_cd(var, tab);
  else if (my_strcmp(tab[0], "echo") == 0)
    echo(tab);
  else if (my_strcmp(tab[0], "alias") == 0)
    end = builtin_alias(var, tab, end);
  else
    end = builtin_env(var, tab, end);
  if (end == -1)
    puterr("Can't execute the command.\n");
  var->status = end;
  return (end);
}
