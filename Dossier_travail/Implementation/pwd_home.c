/*
** pwd_home.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh/David
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Fri May 15 17:37:20 2015 david sebaoun
** Last update Fri May 15 17:37:40 2015 david sebaoun
*/

#include "my.h"

char		*pwd_home(char *home, char *path)
{
  int		i;
  int		j;
  int		count;
  char		*tmp;

  i = -1;
  j = 0;
  count = 0;
  tmp = my_strcpy(path);
  if (my_strncmp(home, path, my_strlen(home)) == 0)
    {
      while (path[++i] != 0 && count < 3)
	++count;
      path[j++] = '~';
      i = my_strlen(home) - 1;
      while (tmp[++i] != 0)
	{
	  path[j] = tmp[i];
	  ++j;
	}
      path[j] = 0;
      return (path);
    }
  return (tmp);
}
