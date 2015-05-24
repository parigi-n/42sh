/*
** my_strcpy.c for my_strcpy in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Jan 20 16:32:59 2015 Jules Vautier
** Last update Fri May  8 12:08:00 2015 Jules Vautier
*/

#include "my.h"

char		*my_strcpy(char *str)
{
  char		*new;
  int		i;

  i = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}

char		*my_strncpy(char *str, int i)
{
  char		*new;
  int		x;

  x = 0;
  if (i > my_strlen(str))
    return (NULL);
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[x] != '\0' && x < i)
    {
      new[x] = str[x];
      x++;
    }
  new[x] = '\0';
  return (new);
}

char		*my_strlcpy(char *str, int i)
{
  char		*new;
  int		x;

  x = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  new[x] = '\0';
  if (i > my_strlen(str))
    return (new);
  while (str[i] != '\0')
    {
      new[x] = str[i];
      x++;
      i++;
    }
  new[x] = '\0';
  return (new);
}
