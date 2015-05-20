/*
** init.c for alias in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/42shrc
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu May  7 16:14:28 2015 Jules Vautier
** Last update Sun May 17 14:51:46 2015 david sebaoun
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int		open_rc(t_struct *var)
{
  char	*home;
  char	*path;
  int		fd;

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
