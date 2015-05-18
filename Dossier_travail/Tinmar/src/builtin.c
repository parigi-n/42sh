/*
** cd.c for cd in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Jan 23 12:09:15 2015 Jules Vautier
** Last update Thu Mar 12 17:58:36 2015 Jules Vautier
*/

#include "my.h"

int	builtin(t_struct *var, char **tab)
{
  int	end;

  end = 1;
  if (my_strcmp(tab[0], "exit") == 0)
    exit(my_exit(var));
  else if (my_strcmp(tab[0], "cd") == 0)
    end = my_cd(var, tab);
  else if (my_strcmp(tab[0], "env") == 0 || my_strncmp(tab[0], "env ", 4) == 0)
    {
      my_show_list(var->list);
      end = 0;
    }
  else if (my_strncmp(tab[0], "unsetenv", 8) == 0)
    end = erase_list(&var->list, tab[1]);
  else if (my_strncmp(tab[0], "setenv", 6) == 0)
    end = add_list_env(&var->list, tab[1], tab[2]);
  if (end == -1)
    puterr("Can't execute the command.\n");
  return (end);
}
