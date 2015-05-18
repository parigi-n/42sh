/*
** parsing.c for parsing in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Mar  6 09:37:29 2015 Jules Vautier
** Last update Thu May 14 11:29:18 2015 Jules Vautier
*/

#include "my.h"

static int	parsing_add_more(char *str, char *new,
				 int *ptri, int *ptrlen)
{
  char		c;
  int		i;
  int		len;

  i = *ptri;
  len = *ptrlen;
  if (str[i] == 39 || str[i] == '"')
    {
      c = str[i];
      i++;
      new[len] = str[i];
      while (str[i] != '\0' && str[i + 1] != c)
	{
	  new[len] = str[i];
	  len++;
	  i++;
	}
    }
  *ptri = i;
  *ptrlen = len;
  return (SUCCES);
}

char		*parsing_add(char *str, int i, char *new)
{
  int		len;

  len = 0;
  while (str[i] != '\0' && char_cmp_str(str[i], ">|&;") == ERROR)
    {
      /*parsing_add_more(str, new, &i, &len);*/
      new[len] = str[i];
      len++;
      i++;
    }
  if (str[i] != '\0')
    {
      new[len] = str[i];
      len++;
    }
  new[len] = '\0';
  return (new);
}

int		advance(char *str, int i)
{

  char		c;

  while (str[i] != '\0' && char_cmp_str(str[i], ">|&;") == ERROR)
    i++;
  if (str[i] != '\0')
    i++;
  return (i);
}
