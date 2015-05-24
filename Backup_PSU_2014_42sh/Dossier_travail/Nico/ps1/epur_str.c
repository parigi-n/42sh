/*
** epur_str.c for epur_str in /home/vautie_a/rendu/Piscine_C_J08
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Oct 27 16:55:39 2014 jules vautier
** Last update Sun Mar 15 17:56:26 2015 Jules Vautier
*/

#include "my.h"

static	int	check_space(char *str, int i)
{
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    i++;
  return (i);
}

char		*epur_str(char *str)
{
  char		*new;
  int		i;
  int		n;

  i = 0;
  n = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      i = check_space(str, i);
      while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
	{
	  new[n] = str[i];
	  n++;
	  i++;
	}
      i = check_space(str, i);
      if (str[i] != '\0')
	new[n++] = ' ';
    }
  new[n] = '\0';
  return (new);
}
