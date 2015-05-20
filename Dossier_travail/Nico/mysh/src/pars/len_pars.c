/*
** parsing.c for parsing in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Fri Mar  6 09:37:29 2015 Jules Vautier
** Last update Thu May 14 15:43:33 2015 Jules Vautier
*/

#include "my.h"

int		parsing_len(char *str, int i)
{
  char		c;
  int		len;

  len = 0;
  if (i > my_strlen(str))
    return (SUCCES);
  while (str[i] != '\0' && char_cmp_str(str[i], ">|&;") == ERROR)
    {
      if (str[i] == QUOTE || str[i] == '"')
	{
	  len++;
	  c = str[i++];
	  while (str[i] != '\0' && str[i] != c)
	    {
	      len++;
	      i++;
	    }
	}
      len++;
      i++;
    }
  return (len);
}
