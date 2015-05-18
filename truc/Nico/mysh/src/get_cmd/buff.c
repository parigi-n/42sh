/*
** buff.c for buffer in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Mar  6 08:26:24 2015 Jules Vautier
** Last update Wed May  6 08:47:03 2015 Jules Vautier
*/

#include "my.h"

int		check_buff(char *str)
{
  int		i;
  char		c;

  i = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && str[i] != '"' && str[i] != 39)
	i++;
      c = str[i];
      if (c == '\0')
	return (SUCCES);
      i++;
      while (str[i] != '\0' && str[i] != c)
	i++;
      if (str[i] == '\0')
	return (1);
      i++;
    }
  return (SUCCES);
}
