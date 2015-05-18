/*
** str_fct.c for str_fct in /home/vautie_a/rendu/Colle-1_P3CWR/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Apr 27 20:15:15 2015 Jules Vautier
** Last update Sun May 17 15:42:22 2015 david sebaoun
*/

#include "shared.h"

int	my_strcmp(const char *str,
		  const char *new)
{
  int	i;

  i = 0;
  while (str[i] != '\0' || new[i] != '\0')
    {
      if (str[i] != new[i])
	return (ERROR);
      i++;
    }
  if (str[i] != new[i])
    return (ERROR);
  return (OK);
}

int	my_strlcmp(const char *str,
		   const char *new, int nb)
{
  int	i;
  int	n;

  i = my_strlen(str);
  n = my_strlen(new);
  while (nb > 0 && i >= 0 && n >= 0)
    {
      if (str[i] != new[n])
	return (ERROR);
      i--;
      n--;
      nb--;
    }
  if (str[i] != new[n])
    return (ERROR);
  return (OK);
}

int	my_strncmp(const char *str,
		   const char *new, const int nb)
{
  int	i;

  i = 0;
  while (i < (nb - 1) && str[i] != '\0' && new[i] != '\0')
    {
      if (str[i] != new[i])
	return (ERROR);
      i++;
    }
  if (str[i] != new[i])
    return (ERROR);
  return (OK);
}

int	my_strcmp_op(const char *str,
		     const char *new, int deb)
{
  int	i;
  int	x;

  if (my_strlen(str) < deb)
    return (ERROR);
  i = deb;
  x = 0;
  while (str[i] != '\0' && new[x] != '\0')
    {
      if (str[i] != new[x])
	return (-1);
      i++;
      x++;
    }
  if ((str[i] == ' ' || str[i] == '\0' ||
       str[i] == '\t' || str[i] == '\n') && new[x] == '\0')
    return (OK);
  return (ERROR);
}
