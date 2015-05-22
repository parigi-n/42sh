/*
** parsing.c for parsing in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Mar  6 09:37:29 2015 Jules Vautier
** Last update Thu May 21 10:39:28 2015 Jules Vautier
*/

#include "my.h"

int		advance(char *str, int i)
{
  char		c;

  while (str[i] != '\0' && char_cmp_str(str[i], ">|&;") == ERROR)
    {
      if (str[i] == 39 || str[i] == '"')
	{
	  c = str[i++];
	  while (str[i] != c && str[i] != '\0')
	    i++;
	}
      if (str[i] != '\0')
	i++;
    }
  if (str[i] != '\0')
    i++;
  return (i);
}

char		*parsing_add(char *str, int *ptri, char *new)
{
  int		len;
  int		i;

  i = *ptri;
  len = 0;
  while (str[i] != '\0' && char_cmp_str(str[i], ">|&;") == ERROR)
    {
      new[len] = str[i];
      len++;
      i++;
    }
  *ptri = i;
  new[len] = '\0';
  return (new);
}
