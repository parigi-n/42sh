/*
** my_strlcmp.c for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh/src/shared
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Mon May  4 17:25:56 2015 david sebaoun
** Last update Mon May  4 17:26:17 2015 david sebaoun
*/

#include "shared.h"

int	my_strlcmp(char *str, char *new, int nb)
{
  int	i;
  int	n;

  i = my_strlen(str);
  n = my_strlen(new);
  while (nb > 0 && i >= 0 && n >= 0)
    {
      if (str[i] != new[n])
	return (-1);
      i--;
      n--;
      nb--;
    }
  if (str[i] != new[n])
    return (-1);
  return (0);
}
