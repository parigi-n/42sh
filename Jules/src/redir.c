/*
** exe_command.c for exe_cmd in /home/vautie_a/rendu/PSU_2014_minishell1
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sat Jan 31 09:39:51 2015 Jules Vautier
** Last update Sun May 24 21:02:50 2015 kevin ventalon
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

static char	*mod_path(char *str, char symb)
{
  int		i;
  int		j;
  char		*new_str;

  i = 0;
  j = 0;
  if ((new_str = malloc(sizeof(char)
			* (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] == symb)
    ++i;
  while (str[i] != 0)
    {
      new_str[j++] = str[i];
      ++i;
    }
  new_str[j] = 0;
  return (new_str);
}

static int	redir_right(t_struct *var, char *path)
{
  if (var->exe.fdout != 1)
    close(var->exe.fdout);
  if (my_strlen(path) > 2 && path[0] == '>' && path[1] == '>')
    {
      if ((var->exe.fdout = open(mod_path(path, '>'), O_RDWR |
				 O_APPEND | O_CREAT, S_IRUSR | S_IWUSR |
				 S_IRGRP | S_IWGRP | S_IROTH)) == ERROR)
	return (puterr("Error : error hile opening output file\n"));
    }
  else if (my_strlen(path) > 1 && path[0] == '>')
    if ((var->exe.fdout = open(mod_path(path, '>'),
			       O_RDWR | O_CREAT, S_IRUSR | S_IWUSR |
			       S_IRGRP | S_IWGRP | S_IROTH)) == ERROR)
      return (puterr("Error : error hile opening output file\n"));
  return (var->exe.fdout);
}

int		redir(t_struct *var, char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (tab[i][0] == '>' || ((tab[i][0] == '>') && (tab[i][1] == '>')))
	if ((var->exe.fdout =
	     redir_right(var, tab[i])) == ERROR)
	  return (ERROR);
      ++i;
    }
  if (dup2(var->exe.fdout, 1) == ERROR)
    return (puterr("Error: dup2 sys call failed\n"));
  return (SUCCES);
}
