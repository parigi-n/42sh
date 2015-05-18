/*
** my_strcat.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh/src/shared
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Mon May  4 17:27:40 2015 david sebaoun
** Last update Mon May  4 17:28:14 2015 david sebaoun
*/

#include <stdlib.h>
#include "shared.h"

char	*my_strcat(char *str, char *way)
{
  char	*new;
  int	i;
  int	n;

  i = 0;
  n = 0;
  if ((new = malloc
       (sizeof(char) * (my_strlen(way) + my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (way[n] != '\0')
    {
      new[n] = way[n];
      n++;
    }
  while (str[i] != '\0')
    {
      new[n] = str[i];
      n++;
      i++;
    }
  new[n] = '\0';
  return (new);
}
