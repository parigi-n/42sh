/*
** exe_command.c for exe_cmd in /home/vautie_a/rendu/PSU_2014_minishell1
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sat Jan 31 09:39:51 2015 Jules Vautier
** Last update Sun May 24 20:28:00 2015 david sebaoun
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
  my_printf("%s\n", str);
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
  my_printf("%s\n", new_str);
  return (new_str);
}

static int	redir_right(t_struct *var, char *path)
{
  if (var->exe.fdout != 1)
    close(var->exe.fdout);
  if (my_strlen(path) > 2 && path[0] == '>' && path[1] == '>')
    {
      if ((var->exe.fdout = open(mod_path(path, '>'),
				 O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR |
			       S_IRGRP | S_IWGRP | S_IROTH)) == ERROR)
	return (puterr("Error : error while opening output file\n"));
    }
  else if (my_strlen(path) > 1 && path[0] == '>')
    if ((var->exe.fdout = open(mod_path(path, '>'),
			       O_RDWR | O_CREAT, S_IRUSR | S_IWUSR |
			       S_IRGRP | S_IWGRP | S_IROTH)) == ERROR)
      return (puterr("Error : error while opening output file\n"));
  return (var->exe.fdout);
}

static int	redir_left(t_struct *var, char *path)
{
  if (var->exe.fdin != 0)
    close(var->exe.fdin);
  if (my_strlen(path) > 2 && path[0] == '<' && path[1] == '<')
    {
      if ((var->exe.fdin = open(mod_path(path, '<'), O_RDWR)) == ERROR)
	return (puterr("Error : error while opening output file\n"));
    }
  if (my_strlen(path) > 1 && path[0] == '<' && path[1] != '<')
    {
      if ((var->exe.fdin = open(mod_path(path, '<'), O_RDWR)) == ERROR)
	return (puterr("Error : error while opening input file\n"));
      if (dup2(0, var->exe.fdin) == ERROR)
	return (puterr("Error : dup2 sys call failed in\n"));
      send_file(var->exe.fdin, );
    }
  return (var->exe.fdin);
}

int		redir(t_struct *var, char **tab)
{
  int		i;

  i = -1;
  while (tab[++i] != NULL)
    if (my_strlen(tab[i]) == 1 && (tab[i][0] == '<' || tab[i][0] == '>'))
      {
	my_printf("Error: syntax error near unexpected token '%c'\n", tab[i][0]);
	return (ERROR);
      }
  i = -1;
  while (tab[++i] != NULL)
    if (tab[i][0] == '>' || ((tab[i][0] == '>') && (tab[i][1] == '>')))
      if ((var->exe.fdout = redir_right(var, tab[i])) == ERROR)
	return (ERROR);
  i = -1;
  while (tab[++i] != NULL)
    {
      if (tab[i][0] == '<' || ((tab[i][0] == '<') && (tab[i][1] == '<')))
	if ((var->exe.fdin = redir_left(var, tab[i])) == ERROR)
	  return (ERROR);
    }
  if (dup2(var->exe.fdout, 1) == ERROR)
    return (puterr("Error: dup2 sys call failed out\n"));
  return (SUCCES);
}
