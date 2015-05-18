/*
** my_strcpy.c for my_strcpy in /home/vautie_a/rendu/PSU_2014_minishell1/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Jan 20 16:32:59 2015 Jules Vautier
** Last update Tue Apr 28 16:31:59 2015 Jules Vautier
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
