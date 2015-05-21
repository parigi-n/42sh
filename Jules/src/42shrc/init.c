/*
** init.c for alias in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/42shrc
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu May  7 16:14:28 2015 Jules Vautier
** Last update Thu May 21 10:42:28 2015 Jules Vautier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int		rc_parser(t_struct *var, int fd)
{
  char		*raw_line;

  while	((raw_line = get_next_line(fd)) != NULL)
    {
      if (check_quote(raw_line) == -1)
	return (puterr("File skipped : Syntax error in .tcshrc (missing quote).\n"));
      else
	{
	  if (list_stock_rc(&var->alias, raw_line) == ERROR)
	    return (ERROR);
	  if (prompt_bashrc(var, raw_line) == ERROR)
	    return (ERROR);
	}
      free(raw_line);
    }
  return (0);
}

int		open_rc(t_struct *var)
{
  char		*home;
  char		*path;
  int		fd;

  var->term.prompt = NULL;
  path = NULL;
  if ((home = my_getstock(&var->env, "HOME")) != NULL)
    {
      if ((path = my_strcat_separ(home, RC_NAME, '/')) == NULL)
	return (puterr(ERROR_MALLOC));
    }
  if (path != NULL && access(RC_NAME, R_OK) != -1)
    path = my_strcpy(RC_NAME);
  if (path == NULL || access(path, R_OK) == -1)
    return (puterr(ERROR_NO_RC));
  if ((fd = open(path, O_RDONLY)) == -1)
    return (puterr(ERROR_OPEN));
  if (rc_parser(var, fd) == -1)
    return (ERROR);
  if (path != NULL)
    free(path);
  close(fd);
  if (var->term.prompt == NULL)
    var->term.prompt = DEFAULT_PROMPT;
  return (SUCCES);
}
