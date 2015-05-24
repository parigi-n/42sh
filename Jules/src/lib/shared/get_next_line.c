/*
** get_next_line.c for lem_in in /home/sebaou_d/rendu/CPE_2014_lemin
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Tue Apr 21 11:24:20 2015 david sebaoun
** Last update Sun May 24 09:30:41 2015 Jules Vautier
*/

#include <unistd.h>
#include <stdlib.h>
#include "shared.h"

static char	*re_alloc(char *str, const char c)
{
  char		*new;
  int		i;

  i = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i++] = c;
  new[i++] = '\0';
  free(str);
  return (new);
}

char		*get_next_line(int fd)
{
  char		buff[2];
  char		*str;
  int		len;
  static int	check = 0;

  if ((str = malloc(1)) == NULL)
    return (NULL);
  str[0] = '\0';
  while ((len = read(fd, buff, 1)) > 0)
    {
      if (buff[0] == '\0')
	check++;
      if (check > 1)
	return (NULL);
      if (buff[0] == '\n')
        return (str);
      str = re_alloc(str, buff[0]);
    }
  if (my_strlen(str) != 0)
    return (str);
  free(str);
  return (NULL);
}
