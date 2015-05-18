/*
** str_fct.c for str_fct in /home/vautie_a/rendu/Colle-1_P3CWR/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Apr 27 20:15:15 2015 Jules Vautier
** Last update Tue Apr 28 16:32:29 2015 Jules Vautier
*/

#include "my.h"

int	my_strcmp(char *str, char *new)
{
  int	i;
  
  i = 0;
  while (str[i] != '\0' || new[i] != '\0')
    {
      if (str[i] != new[i])
	return (-1);
      i++;
    }
  if (str[i] != new[i])
    return (-1);
  return (0);
}

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

int	my_strncmp(char *str, char *new, int nb)
{
  int	i;
  
  i = 0;
  while (i < (nb - 1) && str[i] != '\0' && new[i] != '\0')
    {
      if (str[i] != new[i])
	return (-1);
      i++;
    }
  if (str[i] != new[i])
    return (-1);
  return (0);
}
