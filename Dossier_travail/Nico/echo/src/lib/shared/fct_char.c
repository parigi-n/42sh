/*
** add_pas.c for add_pas in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src/pars
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu May  7 11:51:38 2015 Jules Vautier
** Last update Sun May 17 15:33:15 2015 david sebaoun
*/

#include "shared.h"

char	*add_char(char *str, int i, char c)
{
  char	*new;
  int		x;

  x = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[x] != '\0' && x < i)
    {
      new[x] = str[x];
      x++;
    }
  new[x++] = c;
  while (str[x -1] != '\0')
    {
      new[x] = str[x -1];
      x++;
    }
  new[x] = '\0';
  return (new);
}

int	char_cmp_str(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (c == str[i])
        return (0);
      i++;
    }
  return (-1);
}
