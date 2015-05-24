/*
** init.c for alias in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/42shrc
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu May  7 16:14:28 2015 Jules Vautier
** Last update Thu May 14 09:28:34 2015 Jules Vautier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int		open_rc(t_struct *var)
{
  char		*path;
  int		fd;
  char		*home;

  if ((home = my_getstock(&var->env, "HOME")) == NULL)
    return (SUCCES);
  if ((path = my_strcat_separ(home, RC_NAME, '/')) == NULL)
    return (puterr(ERROR_MALLOC));
  if ((access(path, F_OK)) == -1)
    return (SUCCES);
  if ((fd = open(path, O_RDONLY)) == -1)
    return (puterr(ERROR_OPEN));
  if (list_stock_rc(&var->alias, fd) == ERROR)
    return (ERROR);
  free(path);
  close(fd);
  return (SUCCES);
}
